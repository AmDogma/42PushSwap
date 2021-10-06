#include "push_swap.h"

int	main(int argc, const char *argv[])
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
	if (sort_ch(stack.a))
		ft_sort(&stack);
	exit(0);
}
