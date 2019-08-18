#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int ft_check_not_num(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] >= '0' && s[i] <= '9')
            i++;
        else if (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' || s[i] == '\n')
            i++;
        else if ((s[i] == '-' && ft_isdigit(s[i + 1])) || (s[i] == '+' && ft_isdigit(s[i + 1])))
            i++;
        else
            return (1);
    }
    return (0);
}

void    ft_replace_to_space(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\r')
            s[i] = ' ';
        i++;
    }
}

int    ft_isspace(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

int    ft_num_count(int argc, char **argv)
{
    int i;
    int count;
    int j;

    i = 1;
    count = 0;
    while (i < argc)
    {
        // printf("ZDES2\n");
        if (ft_isspace(argv[i]))
            {   j = 0;
                while (argv[i][j])
                    {
                        if (argv[i][j] != ' ' && (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0'))
                            count++;
                        j++;
                        //printf("0count %i", count);
                    }
            }
        else
        {
            count++;
            //printf("1count %i", count);
        }
    i++;
    }
    return (count);
}

int    ft_parse(int argc, char **argv, int *tab)
{
    int i;
    int j;
    int k;
    char **buf;
    //int *arr;

    i = 1;
    j = 0;
    k = 0;
    // tab[0] = 1;
    // tab[1] = 2;
    // tab[2] = 3;
    // tab[3] = 4;
    // tab[4] = 5;
    while (i < argc)    // separate to other piece
    {
        if (ft_check_not_num(argv[i]))
        {   
            // printf("ZDES0 = %s\n", argv[i]);
            return (1);
        }
        ft_replace_to_space(argv[i]);
        // printf("ZDES1\n");
        i++;
    }
    i = 1;
    while (i < argc)
    {
        // printf("ZDES2\n");
        if (ft_isspace(argv[i]))
            {
                // printf("ZDES3\n");
                buf = ft_strsplit(argv[i], ' ');
                // k = 0;
                // while (buf[k] != 0)
                //     printf("%s\n",buf[k++]);
                k = 0;
                while (buf[k] != 0)
                    tab[j++] = ft_atoi(buf[k++]);
                i++;
                //free split buf from FDF
            }
        else
            tab[j++] = ft_atoi(argv[i++]);
    }
    //arr = tab;
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);

    //int tab[1000] = {2};

    int *t;
    //t = tab;
    int count;
    count = ft_num_count(argc, argv);
    printf("2count %i\n", count);
    t = (int *)malloc(sizeof(int) * count);

    ft_parse(argc, argv, t);
    int i = 0;
    while (i < count)
    {
        printf("%i\n", t[i++]);
    }
    
    // char s[] = "Hello       World\n World";
    // printf("%s\n", s);
    // printf("--------------------\n");
    // ft_replace_to_space(s);
    // printf("%s\n", s);

    return (0);

}