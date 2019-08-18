#include <stdio.h>


typedef struct 
{
    int x;
    int y;
    int z;
} Coord;


void Print()
{
    static Coord C1;
    C1.x = 1;
    C1.y = 2;
    printf("C1 = %d %d %d", C1.x, C1.y, C1.z);
}

int main()
{
    Print();
    return (0);
}