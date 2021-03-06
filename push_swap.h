#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ps
{
	int			index;
	int			cont;
	int			place;
	struct s_ps	*next;
	struct s_ps	*back;
}	t_ps;

typedef struct s_anb
{
	struct s_ps	*a;
	struct s_ps	*b;
}	t_anb;

long	long_atoi(const char *str);
t_ps	*new_pslist(int cont, int index);
t_ps	*last_list(t_ps *temp);
int		ft_count(t_ps *temp);
int		sort_ch(t_ps *temp);
int		dubl_ch(t_ps *temp, long res);
int		ind_place(int *place, t_ps *temp, int index);
void	ft_pslstadd_back(t_ps **lst, t_ps *new);
void	ft_s(t_anb *stack, char c);
void	ft_p(t_anb *stack, char c);
void	ft_r(t_anb *stack, char c);
void	ft_rr(t_anb *stack, char c);
void	ft_sort(t_anb *stack);
void	ft_max_sort(t_anb *stack, int count);
void	turn_find(t_anb *stack, t_ps *temp, int index);
void	ft_index(t_ps *a, int count);
void	make_t(t_anb *stack);

void	bon_rr(t_anb *stack, char c);
void	bon_p(t_anb *stack, char c);
void	bon_s(t_anb *stack, char c);
void	bon_r(t_anb *stack, char c);
int		ft_gnl(char **line);
int		ft_strncmp(const char *cmp1, const char *cmp2, size_t n);

#endif
