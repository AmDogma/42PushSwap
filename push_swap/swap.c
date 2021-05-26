#include "push_swap.h"

static void ft_swap(t_ps **some_list, t_ps *two) // можно еще поменять контент в листах в два действия
{
		(*some_list)->back = two;
		two->next->back = *some_list;
		two->back = (*some_list)->back;
		(*some_list)->next = two->next;
		two->next = *some_list;
		(*some_list)->back = two;
		*some_list = two;
}

void ft_s(t_anb *stack, char c)
{
	if (c == 'a' && *(stack->a) && (*(stack->a))->next)
	{
		ft_swap(stack->a, (*(stack->a))->next);
		write(1, "sa\n", 3);
	}
	else if (c == 'b' && *(stack->b) && (*(stack->b))->next)
	{
		ft_swap(stack->b, (*(stack->b))->next);
		write(1, "sa\n", 3);
	}
	else if (c == 's')
	{
		ft_s(stack, 'a');
		ft_s(stack, 'b');
		write(1, "ss\n", 3);
	}
}
