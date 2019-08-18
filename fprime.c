#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int nb;
    int i;
    if (argc == 2)
    {
        nb = atoi(argv[1]);
        if (nb == 1)
        {
            printf ("1\n");
            return (0);
        }
        i = 2;
        while (nb >= i)
        {
            if (nb % i == 0)
            {
                printf("%i", i);
                if (nb == i)
                    break;
                printf("*");
                nb /= i;
                i = 1;
            }
            i++;
        }
        printf("\n");
        return (0);
    }
}