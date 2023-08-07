#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(void);

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    int from, to, r, w;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    buffer = create_buffer();
    from = open(argv[1], O_RDONLY);
    if (from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        free(buffer);
        exit(98);
    }

    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        free(buffer);
        close(from);
        exit(99);
    }

    r = read(from, buffer, 1024);
    while (r > 0)
    {
        w = write(to, buffer, r);
        if (w == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            free(buffer);
            close(from);
            close(to);
            exit(99);
        }
        r = read(from, buffer, 1024);
    }

    free(buffer);
    if (close(from) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
        exit(100);
    }
    if (close(to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to);
        exit(100);
    }

    return (0);
}

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);
    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO, "Error: Can't malloc buffer\n");
        exit(99);
    }

    return (buffer);
}
