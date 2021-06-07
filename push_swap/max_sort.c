#include "push_swap.h"

static void	ft_tob_first(t_anb *stack, int mid, int index)
{
	int	i;

	i = 0;
	while (i < mid + 1)
	{
		if (stack->b && stack->b->index == index)
		{
			ft_r(stack, 'b');
			index++;
		}
		else if (stack->a->index <= mid + 1)
		{
			ft_p(stack, 'b');
			i++;
		}
		else
			ft_r(stack, 'a');
	}
	while (--index)
		ft_rr(stack, 'b');
}

static void	ft_toa_split(t_anb *stack, int mid, int *index, int place)
{
	int	i;

	i = mid;
	mid = ((mid + 1) / 2) + *index;
	while (i--)
	{
		if (stack->b->index == *index && mid - *index > 1)
		{
			ft_p(stack, 'a');
			if (stack->b && stack->b->index < mid
				&& stack->b->index != *index + 1)
				ft_r(stack, 'r');
			else
				ft_r(stack, 'a');
			(*index)++;
		}
		else if (stack->b->index >= mid)
		{
			ft_p(stack, 'a');
			stack->a->place = place;
		}
		else
			ft_r(stack, 'b');
	}
}

static int	ft_toa_last(t_anb *stack, int index)
{
	while (stack->b || stack->a->index == index)
	{
		if (stack->a->index == index)
		{
			if (stack->b && stack->b->index != index + 1)
				ft_r(stack, 'r');
			else
				ft_r(stack, 'a');
			index++;
		}
		else if (stack->b->index == index)
			ft_p(stack, 'a');
		else if (stack->b->index == index + 1)
			ft_p(stack, 'a');
		else if (stack->b->next && stack->b->next->index == index)
			ft_s(stack, 'b');
		else if (stack->a->next->index == index)
			ft_s(stack, 'a');
		else if (stack->a->next->index == index + 1)
			ft_s(stack, 'a');
		else
			turn_find(stack, stack->b, index);
	}
	return (index);
}

static int	ft_tob(t_anb *stack, int index, int place)
{
	while (stack->a->place == place && stack->a->index >= index)
	{
		if (stack->a->index == index)
		{
			ft_r(stack, 'a');
			index++;
		}
		else if (stack->b && stack->b->index == index)
			ft_p(stack, 'a');
		else if (stack->b && stack->b->next && stack->b->next->index == index)
			ft_s(stack, 'b');
		else if (stack->a->next->index == index)
			ft_s(stack, 'a');
		else
			ft_p(stack, 'b');
	}
	return (index);
}

void	ft_max_sort(t_anb *stack, int count)
{
	int	mid;
	int	index;
	int	place;

	place = 0;
	index = 1;
	ft_tob_first(stack, count / 2, index);
	while (count >= index)
	{
		while (stack->b)
		{
			mid = ft_count(stack->b);
			if (mid < 7)
				index = ft_toa_last(stack, index);
			else
				ft_toa_split(stack, mid, &index, ++place);
		}
		mid = ind_place(&place, stack->a, index);
		index = ft_tob(stack, index, place);
	}
}
