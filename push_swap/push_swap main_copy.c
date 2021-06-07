//#include "push_swap.h"
//
//int GLOB = 0; // del
//#include <time.h> //del
//#include <stdio.h> // del this
//#include	"leak_detector_c.h" // del this
//
//void push_swap(int argc, char * argv[]){
//
//	int		i;
//	t_anb	stack;
//	t_ps	*temp;
//	long	res;
//
//	make_t(&stack);
//  i = 0;
//	while (argv[++i])
//	{
//		res = long_atoi(argv[i]);
//		temp = new_pslist((int)res, 0);
//		if (!temp || dubl_ch(stack.a, res)) // нужно чистить возможно перед выходом, если не достаточно exit
//		{
//			write(1, "Error\n", 6);
//			exit(0);
//		}
//		ft_pslstadd_back(&stack.a, temp);
//	}
//	if (sort_ch(stack.a))
//		ft_sort(&stack);
//	temp = stack.a; //delete this part ---->
//	i = 1;
//	while (temp)
//	{
//		printf("A %d    ind %d place %d| ", i++, temp->index, temp->place);
//		printf("con %d\n", temp->cont);
//		temp = temp->next;
//	}
//	temp = stack.b;
//	i = 1;
//	while (temp)
//	{
//		printf("B %d    ind %d  place %d| ", i++, temp->index,  temp->place);
//		printf("con %d\n", temp->cont);
//		temp = temp->next;
//	} //delete this part  <-------
//}
//
//
//
//int main(int argc, const char * argv[])
//{
//	atexit(report_mem_leak);   // comment_it
//
//	char *mass[502] = {"program", "-214748364"};
//
//	srand((unsigned int)time(NULL));
//	int num;
//	for (int i = 2; i < 501; i++)
//	{
//		num = rand();
//		mass[i] = malloc(22);
//		sprintf(mass[i], "%d", num);
//		num = i;
//	}
//	push_swap(3, mass);
//	while(num > 1)
//		free(mass[num--]);
//	printf("GLOB = %d", GLOB);
//	exit(0);
//	return 0;
//}
//
