#include "push_swap.h"

t_pslist	*new_pslist(int content, int index)
{
	t_pslist	*new;

	new = (t_pslist *)malloc(sizeof(t_pslist));
	if (new)
	{
		new->content = content;
		new->index = index;
		new->next = NULL;
		new->forw = NULL;
	}
	return (new);
}

void	ft_pslstadd_back(t_pslist **lst, t_pslist *new)
{
	t_pslist	*temp;

	temp = *lst;
	if (!*lst)
		*lst = new;
	if (lst && temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (temp && new)
		temp->next = new;
}
