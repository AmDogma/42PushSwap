#include "push_swap.h"

static void ft_tob_first(t_anb *stack, int mid)
{
	int i = 0;
	while (i < mid)
	{
		if (stack->a->index <= mid)
		{
			ft_p(stack, 'b');
			i++;
		}
		else
			ft_r(stack, 'a'); // in wich side we will turn? can be some ft fo find optimal
	}
}

static int ft_toa_min(t_anb *stack, int mid, int index)
{
	int i;

	i = index;
	while (index <= mid)
	{
		if (stack->a->index == index)
		{
			if (stack->b && stack->a->index == index && stack->b->index != index + 1)
				ft_r(stack, 'r');
			else
				ft_r(stack, 'a');
			index++;
		}
		else if (stack->b && stack->b->index == index)
		{
			ft_p(stack, 'a');
			i++;
		}
		else if (stack->b && stack->b->next && stack->b->next->index == index)
			ft_s(stack, 'b');
		else
			ft_r(stack, 'b'); // in wich side we will turn?
	}
	while (stack->a->index == index)
	{
		ft_r(stack, 'a');
		index++;
	}

	return (index);
}

static int ft_toa_max(t_anb *stack, int mid, int index, int place)
{
	int i;

	i = index;
	while (i <= mid)
	{
		if (stack->a->index == index)
		{
			if (stack->a->index == index && stack->b->index < mid)
				ft_r(stack, 'r');
			else
				ft_r(stack, 'a');
			index++;
		}
		else if (stack->b->index >= mid)
		{
			ft_p(stack, 'a');
			stack->a->place = place;
			i++;
		}
		else
			ft_r(stack, 'b'); // in wich side we will turn?
	}
	while (stack->a->index == index)
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
	int place;

	place = 1;
	index = 1;
	mid = (count/2) + index;
	ft_tob_first(stack, mid); // step 1
	while (count != index)
	{
		while (stack->b)
		{
			if (ft_count(stack->b) < 4)
				index = ft_toa_min(stack, mid, index); // can make 3-5 min values
			else
			{
				mid = ((mid - index)/2) + index;
				index = ft_toa_max(stack, mid, index, place++);
			}

		}
		mid = ind_place (--place, stack->a);
		mid = ((mid - index)/2) + index;
		//		ft_tob_first(stack, mid); нужно другую функцию прописать, которая будет отматывать под сортированный список
		break;

	}



}
