#include "push_swap.h"

static void	ft_min_sort(t_ps *one, t_ps *two, t_ps *three, t_anb *stack)
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

static void	ft_med_sort(t_anb *stack, int count)
{
	int	step;

	step = 0;
	while (step < count - 3)
	{
		if (stack->a->index <= count - 3)
		{
			ft_p(stack, 'b');
			step++;
		}
		ft_rr(stack, 'a');
	}
	ft_min_sort(stack->a, stack->a->next, stack->a->next->next, stack);
	if (!sort_ch(stack->b))
		ft_r(stack, 'b');
	while (stack->b)
		ft_p(stack, 'a');
}

void	ft_sort(t_anb *stack)
{
	int	count;

	count = ft_count(stack->a);
	ft_index(stack->a, count);
	if (count == 2)
		ft_s(stack, 'a');
	else if (count == 3)
		ft_min_sort(stack->a, stack->a->next, stack->a->next->next, stack);
	else if (count < 6)
		ft_med_sort(stack, count);
	else
		ft_max_sort(stack, count);
}
