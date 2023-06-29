#include "main.h"

/**
 * leet - Encodes a string into 1337 (Leet Speak) format.
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *str)
{
  int i, j;
  char *letters = "aAeEoOtTlL";
  char *leet_nums = "4433007711";

  for (i = 0; str[i]; i++)
  {
    for (j = 0; letters[j]; j++)
    {
      if (str[i] == letters[j])
      {
        str[i] = leet_nums[j];
        break;
      }
    }
  }

  return str;
}

