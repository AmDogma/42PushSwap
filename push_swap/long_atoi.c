#include "push_swap.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' ||c == '\v'
		||c == '\f' || c == '\r' || c == ' ');
}

long	long_atoi(const char *str)
{
	int		minus;
	long	res;

	minus = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		if (minus > 0)
			res = (res * 10) + (*str++) - 48;
		else
			res = (res * 10) - ((*str++) - 48);
		if (res > 2147483647 || res < -2147483648)
			break;
	}
	return (res);
}
