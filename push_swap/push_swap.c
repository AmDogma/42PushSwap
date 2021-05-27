#include "push_swap.h"

static int	make_t(t_anb *stack)
{
	t_ps **a_list;
	t_ps **b_list;

	a_list = (t_ps **)malloc(sizeof(t_ps *));
	b_list = (t_ps **)malloc(sizeof(t_ps *));
	if (!a_list || !b_list)
		return (-1);
	*a_list = NULL;
	*b_list = NULL;
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

static int sort_ch(t_ps *temp)
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
		if (!temp || !i || dubl_ch(*(stack.a), res)) // нужно чистить возможно перед выходом, если не достаточно exit
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		ft_pslstadd_back(stack.a, temp);
	}
	if (sort_ch(*(stack.a)))// тут выход на поиск правильной сортировки в зависимости от кол-ва
		ft_sort(&stack);
	temp = *(stack.a); //delete this part
	while (temp)
	{
		printf("ind %d | ", temp->index);
		printf("con %d\n", temp->cont);
		temp = temp->next;
	} //delete this part;
	exit(0);
}

int main(int argc, const char * argv[])
{
	char *mass[18] = {"program", "2323223", "243424432", "1", "5", "44", "94", "-2"};
	push_swap(3, mass);


	return 0;
}
