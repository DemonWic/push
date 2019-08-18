#include <stdio.h>
#include <stdlib.h>


typedef struct s_stek
{
    int val;
    struct s_stek *next;
} t_stek;

t_stek *ft_node_new(int value)
{
    t_stek *new;

    new = (t_stek*)malloc(sizeof(t_stek));
    if (new == NULL)
        return (NULL);
    new->val = value;
    new->next = NULL;
    return (new);
}

void	ft_node_add(t_stek **top, t_stek *new)
{
	if (new)
	{
		new->next = *top;
		*top = new;
	}
}

int ft_stek_size(t_stek *top)
{
    int i;
    
    i = 0;
    while(top->next != NULL)
    {
        i++;
        top = top->next;
    }
    i++;
    if (i >= 2)
        return (1);
    return (0);
}

void    ft_stekswap(t_stek **top)
{
    t_stek *buf;

    if (ft_stek_size(*top))
    {
        buf = (*top)->next;
        (*top)->next = buf->next;
        buf->next = *top;
        *top = buf;
    }
    printf("sw\n");
}

void  ft_stekpush(t_stek **src, t_stek **dst)
{
    t_stek *buf;
    t_stek *buf2;
    int k;

    k = 1;
    if (src != NULL)
    {
        buf =(t_stek *)malloc(sizeof(t_stek));
        buf->val = (*src)->val;
        ft_node_add(dst, buf);
        buf2 = *src;
        if ((*src)->next == NULL)
        {
            free(*src);
            *src = NULL;
            k = 0;
        }
        if (k)
        {
            *src = (*src)->next;
            free(buf2);
        }
    }
    printf("ps\n");
}


void    ft_stek_rot(t_stek **top)
{
    t_stek *buf;
    t_stek *buf2;

    buf = *top;
    buf2 = (*top)->next;
    while((*top)->next != NULL)
        *top = (*top)->next;
    (*top)->next = buf;
    buf->next = NULL;
    *top = buf2; 
}
void    ft_stek_revrot(t_stek **top)
{
    t_stek *buf;
    t_stek *buf2;

    buf = *top;
    while((*top)->next != NULL)
    {
        buf2 = *top;
        *top = (*top)->next;
    }
    buf2->next = NULL;
    (*top)->next = buf;
}


void ft_print_stek(t_stek **top, char name)
{
    int i;
    t_stek *buf;

    i = 0;
    buf = *top;
    if (buf == NULL)
    {
        printf("Stek empty\n");
        return;
    }
    while(buf->next)
    {
        printf("%i %c %i\n", i, name, buf->val);
        buf = buf->next;
        i++;
    } 
    printf("%i %c %i\n", i, name, buf->val);
    printf("---------------------------------\n\n\n");
}

int main()
{

    t_stek *top_a;
    t_stek *top_b;
    t_stek *new;
    top_a = ft_node_new(1);
    top_b = ft_node_new(5);
    new = ft_node_new(2);
    ft_node_add(&top_a, new);
    new = ft_node_new(3);
    ft_node_add(&top_a, new);
    new = ft_node_new(10);
    ft_node_add(&top_a, new);
    ft_stekswap(&top_a);
    // ft_print_stek(&top_a, 'A');
    // ft_print_stek(&top_b, 'B');
    // ft_stekswap(&top_a);
    ft_stekpush(&top_a, &top_b);
    // printf("---------------------------------\n\n\n");
    // ft_print_stek(&top_a, 'A');
    // ft_print_stek(&top_b, 'B'); 
    // printf("---------------------------------\n\n\n");
    ft_stekswap(&top_a);
    ft_stekswap(&top_b);
    // ft_print_stek(&top_a, 'A');
    // ft_print_stek(&top_b, 'B');
    // printf("---------------------------------\n\n\n");
    ft_stekpush(&top_a, &top_b);
    ft_stekpush(&top_a, &top_b);
    // ft_print_stek(&top_b, 'B');
    // printf("---------------------------------\n\n\n");
    // ft_stekpush(&top_a, &top_b);
    // ft_stekpush(&top_a, &top_b);
    ft_stek_rot(&top_b);
    // ft_print_stek(&top_b, 'B');
    ft_stek_revrot(&top_b);
    ft_stek_revrot(&top_b);
    // ft_print_stek(&top_b, 'B');
    ft_stekpush(&top_b, &top_a);
    ft_stekpush(&top_b, &top_a);
    ft_stekpush(&top_b, &top_a);
    ft_stekpush(&top_b, &top_a);
    ft_print_stek(&top_b, 'B');
    ft_print_stek(&top_a, 'A');
    t_stek *buf_a;
    t_stek *buf_b;
    int i = 0;
    while(i <= 2)
    {
        buf_a = top_a;
        while(buf_a->next)
        {
            if (buf_a->next != NULL)
                if (buf_a->val > (buf_a->next)->val)
                {
                    ft_stekswap(&top_a);
                    // printf("1\n");
                }
            ft_stekpush(&top_a, &top_b);
             buf_b = top_b;
            if (buf_b->next != NULL)
                if (buf_b->val > (buf_b->next)->val)
                {
                    ft_stekswap(&top_b);
                    // printf("3\n");
                }
            buf_a = top_a;
            //buf_a = buf_a->next;
        }
        ft_stekpush(&top_a, &top_b);
        buf_b = top_b;
          while(buf_b->next)
        {
            if (buf_b->next != NULL)
                if (buf_b->val < (buf_b->next)->val)
                {
                    ft_stekswap(&top_b);
                    // printf("1\n");
                }
            ft_stekpush(&top_b, &top_a);
             buf_a = top_a;
            if (buf_a->next != NULL)
                if (buf_a->val > (buf_a->next)->val)
                {
                    ft_stekswap(&top_a);
                    // printf("3\n");
                }
            buf_b = top_b;
            //buf_b = buf_b->next;
        }
        ft_stekpush(&top_b, &top_a);
        i++;
    }
        //  if (top_b->next != NULL)
        //         if (top_b->val < (top_b->next)->val)
        //         {
        //             ft_stekswap(&top_b);
        //             printf("1\n");
        //         }
        // ft_stekpush(&top_b, &top_a);
        // ft_stekpush(&top_b, &top_a);
    // int i = 0;
    // while (i <= 3)
    // {
    //     buf_a = top_a;
    //     while(buf_a->next)
    //     {
    //         if (buf_a->next != NULL)
    //             if (buf_a->val > (buf_a->next)->val)
    //             {
    //                 ft_stekswap(&top_a);
    //                 printf("1\n");
    //             }
    //         ft_stekpush(&top_a, &top_b);
    //         buf_b = top_b;
    //         printf("2\n");
    //         if (buf_b->next != NULL)
    //             if (buf_b->val > (buf_b->next)->val)
    //             {
    //                 ft_stekswap(&top_b);
    //                 printf("3\n");
    //             }
    //         buf_a = top_a;
    //         buf_a = buf_a->next;
    //     }
    //     if (top_a->next != NULL)
    //             if (top_a->val > (top_a->next)->val)
    //             {
    //                 ft_stekswap(&top_a);
    //                 printf("1\n");
    //             }
    //     ft_stekpush(&top_a, &top_b);
    //     ft_stekpush(&top_a, &top_b);
    //     // ft_print_stek(&top_b, 'B');
    //     // ft_print_stek(&top_a, 'A');


    //     buf_b = top_b;
    //     while(buf_b->next)
    //     {
    //         if (buf_b->next != NULL)
    //             if (buf_b->val < (buf_b->next)->val)
    //             {
    //                 ft_stekswap(&top_b);
    //                 printf("1\n");
    //             }
    //         ft_stekpush(&top_b, &top_a);
    //         buf_a = top_a;
    //         printf("2\n");
    //         if (buf_a->next != NULL)
    //             if (buf_a->val > (buf_a->next)->val)
    //             {
    //                 ft_stekswap(&top_a);
    //                 printf("3\n");
    //             }
    //         buf_b = top_b;
    //         buf_b = buf_b->next;
    //     }
    //     if (top_b->next != NULL)
    //             if (top_b->val < (top_b->next)->val)
    //             {
    //                 ft_stekswap(&top_b);
    //                 printf("1\n");
    //             }
    //     ft_stekpush(&top_b, &top_a);
    //     ft_stekpush(&top_b, &top_a);
    //     i++;
    // }

    ft_print_stek(&top_b, 'B');
    ft_print_stek(&top_a, 'A');
    // ft_stek_revrot(&top_b);
    return (0);
}