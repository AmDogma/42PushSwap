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

	step = 1; // первый раз можно отправлять в функцию а дальше можно передавать рекурсивно
	while (step <= count)
	{
		if ((*(stack->a))->index == step)
		{
			ft_r(stack, 'a');
			step++;
		}
		else if (*(stack->b) && (*(stack->b))->index == step)
		{
			ft_p(stack, 'a');
			ft_r(stack, 'a');
			step++;
		}
		else if (*(stack->b) && (*(stack->b))->next && (*(stack->b))->index > (*(stack->b))->next->index)
			ft_s(stack, 'r');
		else if ((*(stack->a))->index > step)
			ft_p(stack, 'b');
		else
			ft_rr(stack, 'b');
	}
}

void ft_max_sort(t_anb *stack, int count)
{

}
