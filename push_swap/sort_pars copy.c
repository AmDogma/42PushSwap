#include "push_swap.h"

static int	ft_count(t_ps *temp)
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

static void	ft_index(t_ps **a, int count)
{
	int	ind;
	t_ps *temp;
	int	min;

	ind = 1;
	min = (*a)->cont;
	while (count >= ind)
	{
		temp = *a;
		while (temp)
		{
			if (min >= temp->cont && ind == 1)
			{
				temp->index = ind++;
				min = temp->cont;
			}
			else if (min == temp->cont)
				temp->index = ind++;
			temp = temp->next;
		}
		min += 1;
	}
}

void	ft_sort(t_anb *stack)
{
	int count;

	count = ft_count(*(stack->a));
	ft_index(stack->a, count);
	if (count == 2)
		ft_s(stack, 'a');
	else if (count == 3)
		ft_min_sort(*(stack->a), (*(stack->a))->next, (*(stack->a))->next->next, stack);
	else if (count < 6)
		ft_med_sort(stack, count);
	else
		ft_med_sort(stack, count); // need to change
}

