#include "push_swap.h"

t_ps	*new_pslist(int cont, int index)
{
	t_ps	*new;

	new = (t_ps *)malloc(sizeof(t_ps));
	if (new)
	{
		new->cont = cont;
		new->index = index;
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
