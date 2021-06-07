#include "push_swap.h"

static	void make_oper(char *line, t_anb *stack)
{
	if (*line == 's' && *(line + 2) == '\0' && (*(line + 1) == 'a' || *(line + 1) == 'b' || *(line + 1) == 's'))
		bon_s(stack, *(line + 1));
	else if (*line == 'p' && *(line + 2) == '\0' && (*(line + 1) == 'a' || *(line + 1) == 'b'))
		bon_p(stack, *(line + 1));
	else if (*line == 'r' && *(line + 2) == '\0' && (*(line + 1) == 'a' || *(line + 1) == 'b' || *(line + 1) == 'r'))
		bon_r(stack, *(line + 1));
	else if (*line == 'r' && *(line + 1) == 'r' && *(line + 3) == '\0' && (*(line + 2) == 'a' || *(line + 2) == 'b' || *(line + 2) == 'r'))
		bon_rr(stack, *(line + 2));
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	
}

static	void ft_compare(t_anb *stack)
{
	char	*line;

	while (ft_gnl(&line))
	{
		make_oper(line, stack);
		if (line)
			free(line);
		line = NULL;
	}
	if (!sort_ch(stack->a) && !ft_count(stack->b))
		write(1, "OK\n", 3);
	else //if (sort_ch(stack->a) || ft_count(stack->b))
		write(1, "KO\n", 3);
}

void	check(int argc, char *argv[])
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
	ft_compare(&stack);
	exit(0);
}

int main(int argc, char * argv[])
{
//	atexit(report_mem_leak);   // comment_it

	char *mass[502] = {"program", "-1", "1", "2"};

	check(3, mass);
	exit(0);
	return 0;
}
