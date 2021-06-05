#include "push_swap.h"

static void ft_rotate_r(t_ps **some)
{
	t_ps *temp;

	temp = *some;
	while (temp->next)
		temp = temp->next;
	temp->next = *some;
	temp->back->next = NULL;
	temp->back = NULL;
	(*some)->back = temp;
	*some = temp;
}

static void ft_rotate(t_ps **some)
{
	t_ps *temp;

	temp = *some;
	while (temp->next)
		temp = temp->next;
	(*some)->back = temp;
	temp->next = *some;
	(*some)->next->back = NULL;
	*some = (*some)->next;
	temp->next->next = NULL;
}

void ft_r(t_anb *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next) // do we need check??
	{
		ft_rotate(&stack->a);
		write(1, "ra\n", 3);
		GLOB++;
	}
	else if (c == 'b' && stack->b && stack->b->next)
	{
		ft_rotate(&stack->b);
		write(1, "rb\n", 3);
		GLOB++;
	}
	else if (c == 'r') // && *(stack->b) && (*(stack->b))->next && *(stack->a) && (*(stack->a))->next
	{
		ft_rotate(&stack->a);
		ft_rotate(&stack->b);
		write(1, "rr\n", 3);
		GLOB++;
	}
}

void ft_rr(t_anb *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)  // do we need check??
	{
		ft_rotate_r(&stack->a);
		write(1, "rra\n", 4);
		GLOB++;
	}
	else if (c == 'b' && stack->b && stack->b->next)
	{
		ft_rotate_r(&stack->b);
		write(1, "rrb\n", 4);
		GLOB++;
	}
	else if (c == 'r') // && *(stack->b) && (*(stack->b))->next && *(stack->a) && (*(stack->a))->next
	{
		ft_rotate_r(&stack->a);
		ft_rotate_r(&stack->b);
		write(1, "rrr\n", 4);
		GLOB++;
	}
}

