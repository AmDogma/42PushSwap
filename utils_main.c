#include "push_swap.h"

int	dubl_ch(t_ps *temp, long res)
{
	while (temp)
	{
		if (res == (long)temp->cont)
			return (1);
		temp = temp->next;
	}
	if (res > 2147483647 || res < -2147483648)
		return (1);
	return (0);
}

int	sort_ch(t_ps *temp)
{
	while (temp && temp->next)
	{
		if (temp->cont < temp->next->cont)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

int	ft_count(t_ps *temp)
{
	int	i;

	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
