#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 20

void    filter(char *line, char *filter)
{
    size_t i;
    size_t k;

    i = 0;
    k = 0;
    while (line[i])
    {
        k = 0;
        while (line[i + k] == filter[k])
        {
            k++;
        }
        if (k == strlen(filter))
        {
            k = 0;
            while (k < strlen(filter))
            {
                line[i + k] = '*';
                k++;
            }
        }
        i++;
    }
}

void    ft_strjoin(char **target, char *src)
{
    char    *append;
    size_t  tar_len = 0;
    size_t  src_len = 0;
    size_t  k = 0;

    tar_len = strlen(*target);
    src_len = strlen(src);
    append = realloc(*target, tar_len + src_len + 1);
    k = 0;
    while (src[k])
    {
        append[tar_len + k] = src[k];
        k++;
    }
    append[tar_len + k] = '\0';
    *target = append;
}

int main(int argc, char *argv[])
{
    char    *line;
    char    *append;
    ssize_t bytes_read;

    line = NULL;
    append = NULL;
    if (argc != 2)
        return (printf("Wrong argument count!\n"), 1);
    append = calloc(1, 1);
    line = calloc(BUFFER_SIZE + 1, 1);
    while ((bytes_read = read(STDIN_FILENO, line, BUFFER_SIZE)) > 0)
    {
        line[bytes_read] = '\0';
        ft_strjoin(&append, line);
    }
    filter(append, argv[1]);
    printf("%s", append);
    free(line);
    free(append);
}
