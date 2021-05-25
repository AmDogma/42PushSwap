#include "push_swap.h"

void push_swap(int argc, char * argv[]){

	int i = 0;
	t_pslist **a_list;
	t_pslist *temp;
	long res;
	a_list = (t_pslist **)malloc(sizeof(t_pslist *));
	while (argv[++i])
	{
		res = long_atoi(argv[i]);
		temp = new_pslist((int)res, 0);
		if (res > 2147483647 || res < -2147483648 || !a_list || !temp)
		{
			write(1, "Error\n", 6);
			break;
		}
		ft_pslstadd_back(a_list, temp);
	}
	if (i < 1)
		return;
	temp = *a_list;
	while (temp)
	{
		printf("%d", temp->content);
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
