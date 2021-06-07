#include "push_swap.h"

static void	ft_rotate_r(t_ps **some)
{
	t_ps	*temp;

	temp = *some;
	while (temp->next)
		temp = temp->next;
	temp->next = *some;
	temp->back->next = NULL;
	temp->back = NULL;
	(*some)->back = temp;
	*some = temp;
}

static void	ft_rotate(t_ps **some)
{
	t_ps	*temp;

	temp = *some;
	while (temp->next)
		temp = temp->next;
	(*some)->back = temp;
	temp->next = *some;
	(*some)->next->back = NULL;
	*some = (*some)->next;
	temp->next->next = NULL;
}

void	bon_r(t_anb *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
		ft_rotate(&stack->a);
	else if (c == 'b' && stack->b && stack->b->next)
		ft_rotate(&stack->b);
	else if (c == 'r')
	{
		bon_r(stack, 'a');
		bon_r(stack, 'b');
	}
}

void	bon_rr(t_anb *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
		ft_rotate_r(&stack->a);
	else if (c == 'b' && stack->b && stack->b->next)
		ft_rotate_r(&stack->b);
	else if (c == 'r')
	{
		bon_rr(stack, 'a');
		bon_rr(stack, 'b');
	}
}
