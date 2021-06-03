#include "push_swap.h"

int ind_place(int place, t_ps *temp)
{
	int mid;

	mid = 0;
	while (temp && temp->place == place)
	{
		if(temp->index > mid)
			mid = temp->index;
		temp = temp->next;
	}
	return(mid);
}
