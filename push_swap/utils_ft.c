#include "push_swap.h"

int ind_place(int *place, t_ps *temp, int index)
{
	int count;

	count = 0;
	*place = temp->place;
	while (temp && temp->place == *place && temp->index >= index) // 999 не нужно писать если все работать будет
	{
		count++;
		temp = temp->next;
	}
	return(count);
}

void turn_find(t_anb *stack, int index) // maybe formula - count will be shorter
{
	t_ps *temp;
	int begin;
	int last;

	last = 0;
	begin = 0;
	temp = last_list(stack->b);
	while (temp->back)
	{
		if (index == temp->index || index + 1 == temp->index)
			break;
		last++;
		temp = temp->back;
	}
	temp = stack->b;
	while (temp->next)
	{
		if (index == temp->index || index + 1 == temp->index)
			break;
		begin++;
		temp = temp->next;
	}
	if (last < begin)
		ft_rr(stack, 'b');
	else
		ft_r(stack, 'b');
}
