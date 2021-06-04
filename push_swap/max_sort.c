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

static int ft_toa_split(t_anb *stack, int mid, int index, int place)
{
	int i;

	i = 0;
	while (i <= mid && mid - index > 1) // ??чек нужен на след вызове
	{
		if (stack->b->index == index)
		{
			ft_p(stack, 'a');
			if (stack->b->index < mid && stack->b->index != (index + 1))
				ft_r(stack, 'r');
			else // можно еще одну проверку написать, если рядом +1 индекс
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
	return (index);
}

static int ft_toa_last(t_anb *stack, int mid, int index)
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
		else if (stack->b->next && stack->b->next->index == index)
			ft_s(stack, 'b');
		else if (last_list(stack->b)->index == index)
			ft_rr(stack, 'b');
		else
			ft_r(stack, 'b'); // in wich side we will turn?
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
		while (mid)
		{
			if (mid < 4)
				index = ft_toa_last(stack, mid, index); // can make <6 min values with complex drop logic
			else
			{
				mid = mid/2 + index; // можно проверять чтобы не больше 5 уходило и вычислять мидл каждый раз снова
				index = ft_toa_split(stack, mid, index, place++);
			}
			mid = ft_count(stack->b);
		}
		mid = ind_place(--place, stack->a);
		break;
//		mid = ind_place (--place, stack->a);
//		mid = ((mid - index)/2) + index;
		//		ft_tob_first(stack, mid); нужно другую функцию прописать, которая будет отматывать под сортированный список


	}



}
