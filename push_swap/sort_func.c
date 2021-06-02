#include "push_swap.h"

void	ft_min_sort(t_ps *one, t_ps *two, t_ps *three, t_anb *stack)
{
	if (one->cont > two->cont && two->cont > three->cont)
	{
		ft_s(stack, 'a');
		ft_rr(stack, 'a');
	}
	if (one->cont < three->cont && two->cont > three->cont)
	{
		ft_s(stack, 'a');
		ft_r(stack, 'a');
	}
	if (one->cont > two->cont && one->cont < three->cont)
		ft_s(stack, 'a');
	if (one->cont > three->cont && two->cont < three->cont)
		ft_r(stack, 'a');
	if (one->cont > three->cont && two->cont > one->cont)
		ft_rr(stack, 'a');
}

void ft_med_sort(t_anb *stack, int count)
{
	int step;

	step = 0; // потому что всегда оставляем 3
	while (step < count - 3)
	{
		if ((*(stack->a))->index <= count - 3)
		{
			ft_p(stack, 'b');
			step++;
		}
		ft_rr(stack, 'a');
	}
	ft_min_sort(*(stack->a), (*(stack->a))->next, (*(stack->a))->next->next, stack);
	if (!sort_ch(*(stack->b)))
		ft_r(stack, 'b');
	while (*(stack->b))
		ft_p(stack, 'a');
}

static void ft_tob_first(t_anb *stack, int step)
{
	int i = 0;
	while (i < step)
	{
		if ((*(stack->a))->index <= step)
		{
			ft_p(stack, 'b');
			i++;
		}
		else
			ft_r(stack, 'a'); // in wich side we will turn?
	}
}

static int ft_toa_min(t_anb *stack, int mid, int index)
{
	int i;

	i = 0;
	while (i < mid)
	{
		if ((*(stack->a))->index == index)
		{
			if ((*(stack->a))->index == index && (*(stack->b))->index > mid)
				ft_r(stack, 'r');
			else
				ft_r(stack, 'a');
			index++;
		}
		else if ((*(stack->b))->index <= mid)
		{
			ft_p(stack, 'a');
			(*(stack->a))->place = 1; // need ++
			i++;
		}
		else
			ft_r(stack, 'b'); // in wich side we will turn?
	}
	while ((*(stack->a))->index == index)
	{
		ft_r(stack, 'a');
		index++;
	}

	return (index);
}

static int ft_toa_max(t_anb *stack, int mid, int index)
{
	int i;

	i = 0;
	while (i < mid)
	{
		if ((*(stack->a))->index == index)
		{
			if ((*(stack->a))->index == index && (*(stack->b))->index < mid)
				ft_r(stack, 'r');
			else
				ft_r(stack, 'a');
			index++;
		}
		else if ((*(stack->b))->index >= mid)
		{
			ft_p(stack, 'a');
			(*(stack->a))->place++; // need some value to make ++
			i++;
		}
		else
			ft_r(stack, 'b'); // in wich side we will turn?
	}
	while ((*(stack->a))->index == index)
	{
		ft_r(stack, 'a');
		index++;
	}
	return (index);
}


void ft_max_sort(t_anb *stack, int count)
{
	int mid;
	int index;

	index = 1;
	mid = (count/2) + index;
	ft_tob_first(stack, mid);
	while (ft_count(*(stack->b)))
	{
		mid = ((mid - index)/2) + index;
		if (mid < 3)
			index = ft_toa_min(stack, mid, index); // can make 3-5 min values
		else
			index = ft_toa_max(stack, mid, index);
	}



}

