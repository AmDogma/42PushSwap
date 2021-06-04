#include "push_swap.h"

static int	make_t(t_anb *stack)
{
	t_ps *a_list;
	t_ps *b_list;

	a_list = (t_ps *)malloc(sizeof(t_ps));
	b_list = (t_ps *)malloc(sizeof(t_ps));
	if (!a_list || !b_list)
		return (-1);
	a_list = NULL;
	b_list = NULL;
	stack->a = a_list;
	stack->b = b_list;
	return (0);
}

static int dubl_ch(t_ps *temp, long res)
{
	while (temp)
	{
		if (res == (long)temp->cont)
			return (1);
		temp = temp->next;
	}
	if (res > 2147483647 || res < -2147483648)
		return (1);
	return (0);
}

int sort_ch(t_ps *temp)
{
	while (temp && temp->next)
	{
		if (temp->cont < temp->next->cont)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

void push_swap(int argc, char * argv[]){

	int		i;
	t_anb	stack;
	t_ps	*temp;
	long	res;

	i = make_t(&stack);
	while (argv[++i])
	{
		res = long_atoi(argv[i]);
		temp = new_pslist((int)res, 0);
		if (!temp || !i || dubl_ch(stack.a, res)) // нужно чистить возможно перед выходом, если не достаточно exit
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		ft_pslstadd_back(&stack.a, temp);
	}
	if (sort_ch(stack.a))
		ft_sort(&stack);
	temp = stack.a; //delete this part
	i = 1;
	while (temp)
	{
		printf("A %d    ind %d place %d| ", i++, temp->index, temp->place);
		printf("con %d\n", temp->cont);
		temp = temp->next;
	}
	temp = stack.b;
	i = 1;
	while (temp)
	{
		printf("B %d    ind %d  place %d| ", i++, temp->index,  temp->place);
		printf("con %d\n", temp->cont);
		temp = temp->next;
	}//delete this part;
	exit(0);
}

#include <time.h>

int main(int argc, const char * argv[])
{
	char *mass[103] = {"program", "0"};

	srand((unsigned int)time(NULL));

	for (int i = 2; i < 101; i++)
	{
		int num = rand();
		if (num%2)
			num = -num;
		mass[i] = malloc(11);
		sprintf(mass[i], "%d", num);
	}
	push_swap(3, mass);


	return 0;
}

