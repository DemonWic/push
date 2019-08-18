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
        if (ft_isspace(argv[i]))
            {   j = 0;
                while (argv[i][j])
                    {
                        if (argv[i][j] != ' ' && (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0'))
                            count++;
                        j++;
                    }
            }
        else
            count++;
    i++;
    }
    return (count);
}

int     ft_check(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_check_not_num(argv[i]))
        {   
            return (1);
        }
        ft_replace_to_space(argv[i]);
        i++;
    }
    return (0);
}

int    ft_parse(int argc, char **argv, int *tab)
{
    int i;
    int j;
    int k;
    char **buf;

    i = 1;
    j = 0;
    k = 0;
    while (i < argc)
    {
        if (ft_isspace(argv[i]))
            {
                buf = ft_strsplit(argv[i], ' ');
                k = 0;
                while (buf[k] != 0)
                    tab[j++] = ft_atoi(buf[k++]);
                i++;
                //free split buf from FDF
            }
        else
            tab[j++] = ft_atoi(argv[i++]);
    }
    return (0);
}

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
    // *a ^= *b;
    // *b ^= *a;
    // *a ^= *b;
}

void    ft_quick_sort(int *arr, int first, int last)
{
    int left;
    int right;
    int middle;

    if (first < last)
    {
        left = first;
        right = last;
        middle = arr[(left + right) / 2];
        while (left <= right)
        {
            while (arr[left] < middle)
                left++;
            while (arr[right] > middle)
                right--;
            if (left <= right)
                ft_swap(&arr[left++], &arr[right--]);
        }
        ft_quick_sort(arr, first, right);
        ft_quick_sort(arr, left, last);
    }
}

int     *ft_copy_tab(int * tab, int count)
{
    int i;
    int *res;

    i = 0;
    res = (int *)malloc(sizeof(int) * count);
    if (res == NULL)
        return (NULL);
    while (i < count)
    {
        res[i] = tab[i];
        i++;
    }
    return(res);
}

int     ft_check_duplicate(int *tab, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        if (((i + 1) != count) && tab[i] == tab[i + 1])
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);

    int *t;
    int *t_sort;
    int count;
    t_stek *top_a;
    t_stek *new;


    if (ft_check(argc, argv))
        return (1);
    count = ft_num_count(argc, argv);
    //printf("2count %i\n", count);
    t = (int *)malloc(sizeof(int) * count);
    ft_parse(argc, argv, t);
    int i = 0;
    t_sort = ft_copy_tab(t, count);
    ft_quick_sort(t_sort, 0, count - 1);
    if (ft_check_duplicate(t_sort, count))
        return (1);
    i = 0;
    printf("==========================\n");
    while (i < count)
    {
        printf("%i\n", t[i++]);
    }
    printf("==========================\n");
    i = 0;

    while (i < count)
    {
        new = ft_node_new(t[i]);
        ft_node_add(&top_a, new);
        i++;
    }
    ft_print_stek(&top_a, 'A');

    if (count == 3)
    {
        if (t[2] > t[1])
            ft_stekswap(&top_a);
        printf("==========================\n");
        ft_print_stek(&top_a, 'A');
        if (t[0] < t[2])
            ft_stek_revrot(&top_a);
    }
    printf("==========================\n");
    ft_print_stek(&top_a, 'A');
    // printf("==========================\n");
    // int a = 100;
    // int b = 300;
    // ft_swap(&a, &b);
    // printf("a =%i\n b = %i\n", a, b);
    return (0);
}