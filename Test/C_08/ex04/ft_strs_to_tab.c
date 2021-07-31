#include <stdlib.h>
#include "ft_stock_str.h"

char *ft_strcpy(char *dest, char *src)
{
    int i;
    i = 0;
    while (src[i] != '\0')
    { 
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int	ft_strlen(char *str)
{
	int	i;
	i = 0;

	while (*str != '\0')
	{
		str++;
		i++;
	}
    return (i);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    int i;

    i = 0;
    t_stock_str *array;
    array = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));

    if ((void *)0 == array)
        return ((void *)0);

    while(i < ac)
    {
        array[i].size = ft_strlen(av[i]);
        array[i].str = av[i];
        array[i].copy = (char *) malloc(ft_strlen(av[i]) + 1);
        if ((void *)0 == array[i].copy)
            return ((void *)0);
        ft_strcpy(array[i].copy, av[i]);
        i++;
    }
    array[i].str = (void *)0;
    return(array);
}
