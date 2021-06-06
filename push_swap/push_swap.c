#include "push_swap.h"

static int	make_t(t_anb *stack)
{
	t_ps *a_list;
	t_ps *b_list;

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

int main(int argc, const char * argv[])
{
	int		i;
	t_anb	stack;
	t_ps	*temp;
	long	res;

	i = make_t(&stack);
	while (argv[++i])
	{
		res = long_atoi(argv[i]);
		temp = new_pslist((int)res, 0);
		if (!temp || !i || dubl_ch(stack.a, res))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		ft_pslstadd_back(&stack.a, temp);
	}
	if (sort_ch(stack.a))
		ft_sort(&stack);
	exit(0);
	return 0;
}

