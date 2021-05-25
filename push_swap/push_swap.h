#include "/Users/mdewayne/Desktop/pool/libc/libft/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_ps
{
	int			index;
	int			cont;
	struct s_ps	*next;
	struct s_ps	*back;
} t_ps;

typedef struct s_anb
{
	struct s_ps	**a;
	struct s_ps	**b;
} t_anb;

long	long_atoi(const char *str);
t_ps	*new_pslist(int cont, int index);
void	ft_pslstadd_back(t_ps **lst, t_ps *new);
void	ft_sa(t_ps **some_list);
void	ft_sb(t_ps **some_list);
void	ft_ss(t_ps **some_list);
void	ft_swap(t_ps **some_list, t_ps *temp);
