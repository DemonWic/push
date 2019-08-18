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

    new = (t_stek *)malloc(sizeof(t_stek));
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
    ft_stekswap(&top_a);
    ft_stekswap(&top_a);
    ft_stekpush(&top_a, &top_b);
    ft_stekpush(&top_a, &top_b);
    ft_stekpush(&top_a, &top_b);
    ft_stek_rot(&top_b);
    ft_stek_revrot(&top_b);
    ft_stek_revrot(&top_b);
    // while (top_a->next != NULL)
    // {
    //     printf("val=%i\n", top_a->val);
    //     top_a = top_a->next;
    // }
    // printf("val=%i\n", top_a->val);

    while (top_b->next != NULL)
    {
        printf("b val=%i\n", top_b->val);
        top_b = top_b->next;
    }
    printf("b val=%i\n", top_b->val);
    return (0);
}