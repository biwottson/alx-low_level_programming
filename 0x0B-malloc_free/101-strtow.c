#include <stdlib.h>
#include "main.h"

/**
 * count_words - Counts the number of words in a string
 * @str: The input string
 *
 * Return: The number of words
 */
int count_words(char *str)
{
    int count = 0, i = 0;

    while (str[i])
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            count++;
        i++;
    }

    return count;
}

/**
 * strtow - Splits a string into words
 * @str: The input string
 *
 * Return: Pointer to an array of strings (Success), or NULL (Failure)
 */
char **strtow(char *str)
{
    char **words;
    int i, j, k, len, word_count;

    if (str == NULL || *str == '\0')
        return NULL;

    word_count = count_words(str);
    if (word_count == 0)
        return NULL;

    words = malloc(sizeof(char *) * (word_count + 1));
    if (words == NULL)
        return NULL;

    i = j = k = 0;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            len = 0;
            j = i;
            while (str[j] && str[j] != ' ')
            {
                len++;
                j++;
            }

            words[k] = malloc(sizeof(char) * (len + 1));
            if (words[k] == NULL)
            {
                for (i = 0; i < k; i++)
                    free(words[i]);
                free(words);
                return NULL;
            }

            j = 0;
            while (str[i] && str[i] != ' ')
            {
                words[k][j] = str[i];
                i++;
                j++;
            }
            words[k][j] = '\0';
            k++;
        }
        else
            i++;
    }

    words[k] = NULL;
    return words;
}
