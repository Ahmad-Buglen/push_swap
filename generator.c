#include "../include/push_swap.h"
#include <time.h>
#include <stdlib.h>

void ps_exit(char *const message)
{
    ft_putstr(message); // error status?
    exit(0);            // param valid? 
}

int ps_random_range(int lower, int upper) 
{ 
    return ((rand() % (upper - lower + 1)) + lower);
} 

int duplicate(int numbers[], int size, int number)
{
    int i;

    i = size;
    while (--i >= 0)
        if (numbers[i] == number)
            return (1);
    return (0);
}

int main(int ac, char **av)
{
    srand(time(NULL));   // Initialization, should only be called once.
    //int r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
    int i;
    char *buf;
    // char *buf1;
    // char *mas;
    int numbers[1000];
    int size;
    int temp;

    // mas = "";

    // while (i++ < 10)
    //     printf("%d\n", rand());
    if (ac == 2)
    {
        size = ft_atoi(av[1]);;
        
        i = 0;
        while (i < size)
        {
            temp = ps_random_range(0, 100000);
            while (duplicate(numbers, i, temp) != 0)
                temp = ps_random_range(0, 100000);
            numbers[i++] = temp;
        }
        // i = 0;
        while (--size >= 0)
        {
            ft_putstr(buf = ft_itoa(numbers[size]));
            if (0 != size)
                ft_putstr(" ");
            ft_strdel(&buf);
        }

        // while (i-- > 0)
        // {
        //     if (!(buf = ft_itoa(ps_random_range(-100000, 100000))))
        //         ps_exit("return NULL\n");
        //     if (i > 0)
        //     {
        //         if (!(buf1 = ft_strjoin(buf, DELIMETER_STRING)))
        //             ps_exit("return NULL\n");
        //         free(buf);
        //     }
        //     else
        //         buf1 = buf;
        //     if (!(buf = ft_strjoin(mas, buf1)))
        //         ps_exit("return NULL\n");
        //     mas = buf;
        //     free(buf1);
        // }
        // ft_putstr(mas);
        // free(mas);    
    }
}