
#include <stdio.h>
#include "libft/libft.h"
#include "include/push_swap.h"

void ps_print(t_ps *const ps)
{
    int i;
    int size;

    size = (ps->len_a > ps->len_b) ? ps->len_a : ps->len_b;

    printf("\n--------------------------------------\n");
    while (--size >= 0)
    {
        printf("|%3d| ", size);
        if (size < ps->len_a)
            printf("%7d (%d) [%d] %s", ps->a[size].number, ps->a[size].index, ps->a[size].weight,
                    1 == ps->a[size].bool ? "t" : "f");
        else
            printf("                    ");
        if (size < ps->len_b)
            printf("  %7d (%d) [%d] %s", ps->b[size].number, ps->b[size].index, ps->b[size].weight,
                    1 == ps->a[size].bool ? "t" : "f");
        else
            printf("                    ");
        printf("\n");
    }
    printf("--------------------------------------\n");
    printf("\\ stack a /           \\ stack b /\n");
}


int main()
{
    printf("%ld", sizeof(t_ps));
}