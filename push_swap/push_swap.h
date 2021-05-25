#include "/Users/mdewayne/Desktop/pool/libc/libft/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_pslist
{
	int				index;
	int				cont;
	struct s_pslist	*next;
	struct s_pslist	*forw;
} t_pslist;

long	long_atoi(const char *str);
t_pslist	*new_pslist(int cont, int index);
void	ft_pslstadd_back(t_pslist **lst, t_pslist *new);
