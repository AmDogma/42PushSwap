#include "push_swap.h"

static void	ft_push(t_ps **to, t_ps **from)
{
	t_ps	*temp;

	temp = *from;
	if ((*from)->next)
		(*from)->next->back = NULL;
	*from = (*from)->next;
	if (*to)
		(*to)->back = temp;
	temp->next = *to;
	*to = temp;
}

static void	ft_swap(t_ps **some_list, t_ps *two)
{
	if (two->next)
		two->next->back = *some_list;
	two->back = (*some_list)->back;
	(*some_list)->back = two;
	(*some_list)->next = two->next;
	two->next = *some_list;
	*some_list = two;
}

void	bon_p(t_anb *stack, char c)
{
	if (c == 'a' && stack->b)
		ft_push(&stack->a, &stack->b);
	else if (c == 'b' && stack->a)
		ft_push(&stack->b, &stack->a);
}

void	bon_s(t_anb *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
		ft_swap(&stack->a, stack->a->next);
	else if (c == 'b' && stack->b && stack->b->next)
		ft_swap(&stack->b, stack->b->next);
	else if (c == 's')
	{
		bon_s(stack, 'a');
		bon_s(stack, 'b');
	}
}
