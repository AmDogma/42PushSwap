#include "push_swap.h"

int ind_place(int place, t_ps *temp, int index)
{
	int mid;

	mid = 0;
	while (temp && temp->place == place && temp->index >= index)
	{
		if(temp->index > mid)
			mid = temp->index;
		temp = temp->next;
	}
	return(mid);
}

