NAME = push_swap

NAME_C = checker

FILES = 	sort_pars.c max_sort.c oper_ps.c oper_r.c \
			utils_list.c utils_ft.c bon_oper_ps.c bon_oper_r.c \
			utils_ch.c utils_main.c

FILES_C =	checker_main.c

FILES_PS =	push_swap_main.c

FLAGS = -Wall -Werror -Wextra

OBJ = ${FILES:.c=.o}

OBJ_C = ${FILES_C:.c=.o}

OBJ_PS = ${FILES_PS:.c=.o}

all : $(NAME) $(NAME_C)

$(NAME) : $(OBJ) $(OBJ_PS)
	 gcc $(FLAGS) $(OBJ) $(OBJ_PS) -o push_swap

$(NAME_C) : $(OBJ) $(OBJ_C)
	 gcc $(FLAGS) $(OBJ) $(OBJ_C) -o  checker

clean :
	/bin/rm -f $(OBJ) $(OBJ_C) $(OBJ_PS)

fclean : clean
	/bin/rm -f $(NAME) $(NAME_C)

re : fclean all

.PHONY : all clean fclean re

#norm :
#	norminette -R CheckForbiddenSourceHeader */*.[ch]
