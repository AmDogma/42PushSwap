#include "push_swap.h"

int	ft_gnl(char **line)
{
	int	i;
	int	rd;
	char ch;

	i = 0;
	rd = 1;
	ch = '1';
	char *buffer = malloc(4);
	*line = buffer;
	while(rd && ch != '\n')
	{
		rd = (int)read(0, &ch, 1);
		if (rd < 0 || i > 3 || !buffer)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		if (ch != '\n')
			buffer[i++] = ch;
	}
	buffer[i] = '\0';
	return(rd);
}

int	ft_strncmp(const char *cmp1, const char *cmp2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (n > i && !diff && (cmp1[i] != '\0' || cmp2[i] != '\0'))
	{
		diff = *((unsigned char *)cmp1 + i) - *((unsigned char *)cmp2 + i);
		i++;
	}
	return (diff);
}
