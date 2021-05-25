#include "push_swap.h"

void ft_swap(t_ps **some_list, t_ps *temp) // можно еще поменять контент в листах в два действия
{
		temp = (*some_list)->next;
		(*some_list)->back = temp;
		temp->next->back = *some_list;
		temp->back = NULL;
		(*some_list)->next = temp->next;
		temp->next = *some_list;
		(*some_list)->back = temp;
		*some_list = temp;
}

void ft_sa(t_ps **some_list)
{
	if(some_list && *some_list && (*some_list)->next)
	{
		ft_swap(some_list, (*some_list)->next);
		write(1, "sa\n", 3);
	}
}

void ft_sb(t_ps **some_list)
{
	if(some_list && *some_list && (*some_list)->next)
	{
		ft_swap(some_list, (*some_list)->next);
		write(1, "sb\n", 3);
	}
}

void ft_ss(t_ps **some_list)
{
	if(some_list && *some_list && (*some_list)->next)
	{
		ft_swap(some_list, (*some_list)->next);
		write(1, "ss\n", 3);
	}
}
