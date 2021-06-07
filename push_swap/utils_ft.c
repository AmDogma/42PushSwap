#include "push_swap.h"

int	ind_place(int *place, t_ps *temp, int index)
{
	int	count;

	count = 0;
	*place = temp->place;
	while (temp && temp->place == *place && temp->index >= index)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	turn_find(t_anb *stack, t_ps *temp, int index)
{
	int	begin;
	int	last;

	last = 0;
	begin = 0;
	while (temp->next && index != temp->index && index + 1 != temp->index)
	{
		begin++;
		temp = temp->next;
	}
	while (temp->back && index != temp->index && index + 1 != temp->index)
	{
		last++;
		temp = temp->back;
	}
	if (last < begin)
		ft_rr(stack, 'b');
	else
		ft_r(stack, 'b');
}

void	ft_index(t_ps *a, int count)
{
	int		ind;
	int		max;
	t_ps	*temp;
	t_ps	*minimum;

	ind = 1;
	minimum = NULL;
	while (count >= ind)
	{
		temp = a;
		max = 2147483647;
		while (temp)
		{
			if (max >= temp->cont && !temp->index)
			{
				max = temp->cont;
				minimum = temp;
			}
			temp = temp->next;
		}
		if (minimum)
			minimum->index = ind++;
	}
}

long	long_atoi(const char *str)
{
	int		minus;
	long	res;

	minus = 1;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	if (*str < 48 || *str > 57)
		res = -21474836488;
	while (*str)
	{
		if (res > 2147483647 || res < -2147483648 || *str < 48 || *str > 57)
		{
			res = -21474836488;
			break;
		}
		res = (res * 10) + (((*str++) - 48) * minus);
	}
	return (res);
}
