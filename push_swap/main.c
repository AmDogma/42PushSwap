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
		if (res > 2147483647 || res < -2147483648 || !temp || !i) // нужен чекер на дубликаты
		{
			write(1, "Error\n", 6);
			break;
		}
		ft_pslstadd_back(stack.a, temp);

	}
	ft_s(&stack, 'a');



	// тут выход на поиск правильной сортировкиж
	//delete this part;
	temp = *(stack.a);
	while (temp)
	{
		printf("%d\n", temp->cont);
		temp = temp->next;
	}
	exit(0);
}

int main()
{
	char *mass[8] = {"program", "44", "22", "-5", "7"};
	push_swap(3, mass);
}
//int main(int argc, const char * argv[]) {
//
//	int i = 0;
//	t_pslist **a_list;
//	long res;
//	a_list = (t_pslist **)malloc(sizeof(t_pslist *));
//	while (argv[++i])
//	{
//		res = long_atoi(argv[i]);
//		if (res > 2147483647 || res < -2147483648 || !a_list)
//		{
//			write(1, "Error\n", 6);
//			return 0;
//		}
//		ft_pslstadd_back(a_list, new_pslist((int)res, 0));
//
//	}
//	printf("Hello, World!\n");
//	return 0;
//}
