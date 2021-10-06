#include "push_swap.h"

t_ps	*new_pslist(int cont, int index)
{
	t_ps	*new;

	new = (t_ps *)malloc(sizeof(t_ps));
	if (new)
	{
		new->cont = cont;
		new->index = index;
		new->place = 0;
		new->next = NULL;
		new->back = NULL;
	}
	return (new);
}

void	ft_pslstadd_back(t_ps **lst, t_ps *new)
{
	t_ps	*temp;

	temp = *lst;
	if (!*lst)
		*lst = new;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (temp && new)
	{
		temp->next = new;
		new->back = temp;
	}
}

t_ps	*last_list(t_ps *temp)
{
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	make_t(t_anb *stack)
{
	t_ps	*a_list;
	t_ps	*b_list;

	a_list = NULL;
	b_list = NULL;
	stack->a = a_list;
	stack->b = b_list;
}
