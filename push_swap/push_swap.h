#include <stdio.h> // del this
#include <stdlib.h>
#include <unistd.h>
#include <limits.h> // can be used?

typedef struct s_ps
{
	int			index;
	int			cont;
	int			place;
	struct s_ps	*next;
	struct s_ps	*back;
} t_ps;

typedef struct s_anb
{
	struct s_ps	*a;
	struct s_ps	*b;
} t_anb;

long	long_atoi(const char *str);
t_ps	*new_pslist(int cont, int index);
void	ft_pslstadd_back(t_ps **lst, t_ps *new);
void	ft_s(t_anb *stack, char c);
void	ft_p(t_anb *stack, char c);
void	ft_r(t_anb *stack, char c);
void	ft_rr(t_anb *stack, char c);
void	ft_sort(t_anb *stack);
void	ft_min_sort(t_ps *one, t_ps *two, t_ps *three, t_anb *stack);
void	ft_med_sort(t_anb *stack, int count);
void	ft_max_sort(t_anb *stack, int count);
int		ft_count(t_ps *temp);
int		sort_ch(t_ps *temp);
int		ind_place(int place, t_ps *temp, int index);
t_ps	*last_list(t_ps *temp);

