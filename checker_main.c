#include "push_swap.h"

static	void	make_oper(char *line, t_anb *stack)
{
	if (!ft_strncmp(line, "rra", 4) || !ft_strncmp(line, "rrb", 4)
		|| !ft_strncmp(line, "rrr", 4))
		bon_rr(stack, *(line + 2));
	else if (!ft_strncmp(line, "sa", 3) || !ft_strncmp(line, "sb", 3)
		|| !ft_strncmp(line, "ss", 3))
		bon_s(stack, *(line + 1));
	else if (!ft_strncmp(line, "pa", 3) || !ft_strncmp(line, "pb", 3))
		bon_p(stack, *(line + 1));
	else if (!ft_strncmp(line, "ra", 3) || !ft_strncmp(line, "rb", 3)
		|| !ft_strncmp(line, "rr", 3))
		bon_r(stack, *(line + 1));
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

static	void	ft_compare(t_anb *stack)
{
	char	*line;

	while (ft_gnl(&line))
	{
		make_oper(line, stack);
		if (line)
			free(line);
		line = NULL;
	}
	if (ft_count(stack->a) && (!sort_ch(stack->a) && !ft_count(stack->b)))
		write(1, "OK\n", 3);
	else if (sort_ch(stack->a) || ft_count(stack->b))
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_anb	stack;
	t_ps	*temp;
	long	res;

	i = 0;
	make_t(&stack);
	while (argv[++i] && argc > 1)
	{
		res = long_atoi(argv[i]);
		temp = new_pslist((int)res, 0);
		if (!temp || dubl_ch(stack.a, res))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		ft_pslstadd_back(&stack.a, temp);
	}
	if (ft_count(stack.a))
		ft_compare(&stack);
	exit(0);
}
