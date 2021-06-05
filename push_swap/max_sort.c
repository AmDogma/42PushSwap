#include "push_swap.h"

static void ft_tob_first(t_anb *stack, int mid, int *index)
{
	int i = 0;
	while (i < mid + 1)
	{
		if (stack->b && stack->b->index == *index)
		{
			ft_r(stack, 'b');
			(*index)++;
		}
		else if (stack->a->index <= mid + 1)
		{
			ft_p(stack, 'b');
			i++;
		}
		else
			ft_r(stack, 'a'); // in wich side we will turn? can be some ft fo find optimal
	}
	i = 1;
	while (*index > i) // can be separate ft
	{
		ft_rr(stack, 'b');
		ft_p(stack, 'a');
		stack->a->place = 999; // можно пометить только 1 индекс в начале
		i++;
	}
	while (--i)
		ft_r(stack, 'a');
}

static int ft_toa_split(t_anb *stack, int mid, int index, int place) // может быть ощшибка тут
{
	int i;

	i = mid;
	mid = (mid+1)/2 + index;
	while (i--)
	{
		if (stack->b->index == index && mid - index > 0)
		{
			ft_p(stack, 'a');
			stack->a->place = 999; // можно пометить только 1 индекс в начале
			if (stack->b && stack->b->index < mid && stack->b->index != index + 1)
				ft_r(stack, 'r');
			else
				ft_r(stack, 'a');
			index++;
		}
		else if (stack->b->index >= mid)
		{
			ft_p(stack, 'a');
			stack->a->place = place;
		}
		else
			ft_r(stack, 'b'); // in wich side we will turn?
	}
	return (index);
}

static int ft_toa_last(t_anb *stack, int mid, int index)
{
	while (stack->b || stack->a->index == index)
	{
		if (stack->a->index == index)
		{
			stack->a->place = 999; // можно пометить только 1 индекс в начале
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
		else if (stack->a->next->index == index || stack->a->next->index == index + 1)
			ft_s(stack, 'a');
		else
			turn_find(stack, index);
	}
	return (index);
}

static int ft_tob(t_anb *stack, int mid, int index, int place)
{

	while (stack->a->place == place && stack->a->index >= index) // можно мид отнимать
	{
		if (stack->a->index == index)
		{
			ft_r(stack, 'a');
			index++;
		}
		else if (stack->b && stack->b->index == index)
			ft_p(stack, 'a');
		else if	(stack->b && stack->b->next && stack->b->next->index == index)
			ft_s(stack, 'b');
		else if (stack->a->next->index == index)
			ft_s(stack, 'a');
		else
		{
			ft_p(stack, 'b');
			mid++;
		}
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
	int delete = 0; // delete
	ft_tob_first(stack, count/2, &index); // step 1
	while (count >= index)
	{
		while (stack->b)
		{
			mid = ft_count(stack->b);
			if (mid < 7) // поэкспериментировать над кол-вом
				index = ft_toa_last(stack, mid, index);
			else
			{
				index = ft_toa_split(stack, mid, index, ++place);
			}
		} // может быть все отсортировано после этой функции
		mid = ind_place(&place, stack->a, index); // нужно заново считать или возв кол-во как
		if (mid)
			index = ft_tob(stack, mid + index, index, place);

//		if (delete++ > 3)
//			break;
	}



}
