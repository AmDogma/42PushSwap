//#include "push_swap.h"
//
//static void ft_push(t_ps **to, t_ps **from)
//{
//	t_ps *temp;
//
//	temp = *from;
//	if ((*from)->next)
//		(*from)->next->back = NULL;
//	*from = (*from)->next;
//	if (*to)
//		(*to)->back = temp;
//	temp->next = *to;
//	*to = temp;
//}
//
//static void ft_swap(t_ps **some_list, t_ps *two)
//{
//	if (two->next)
//		two->next->back = *some_list;
//	two->back = (*some_list)->back;
//	(*some_list)->back = two;
//	(*some_list)->next = two->next;
//	two->next = *some_list;
//	*some_list = two;
//}
//
//void ft_p(t_anb *stack, char c)
//{
//	if (c == 'a' && stack->b)
//	{
//		ft_push(&stack->a, &stack->b);
//		write(1, "pa\n", 3);
//		GLOB++;
//	}
//	else if (c == 'b' && stack->a)
//	{
//		ft_push(&stack->b, &stack->a);
//		write(1, "pb\n", 3);
//		GLOB++;
//	}
//}
//
//void ft_s(t_anb *stack, char c)
//{
//	if (c == 'a' && stack->a && stack->a->next)
//	{
//		ft_swap(&stack->a, stack->a->next);
//		write(1, "sa\n", 3);
//		GLOB++;
//	}
//	else if (c == 'b' && stack->b && stack->b->next)
//	{
//		ft_swap(&stack->b, stack->b->next);
//		write(1, "sb\n", 3);
//		GLOB++;
//	}
//	else if (c == 's') //  && *(stack->b) && (*(stack->b))->next && *(stack->a) && (*(stack->a))->next
//	{
//		ft_swap(&stack->a, stack->a->next);
//		ft_swap(&stack->b, stack->b->next);
//		write(1, "ss\n", 3);
//		GLOB++;
//	}
//}
