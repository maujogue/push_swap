SRCS	=	ps_main.c	ps_utils.c	ps_utils_lst_2.c	ps_utils_lst.c	ps_split.c	ps_check_fill.c\
			ps_instructions.c	ps_instructions_2.c	ps_sort.c	ps_sort_utils.c\
			ft_printf/ft_printf.c	ft_printf/write_functions_hex.c\
			ft_printf/write_functions_nbr.c	ft_printf/write_functions_str.c

BUILD_DIR	=	build/

OBJS	=	$(SRCS:%.c=$(BUILD_DIR)%.o)

HEAD	=	header/

FLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap.a

LIB	=	ar rc

RM	=	rm -rf

$(BUILD_DIR)%.o:	%.c	${HEAD}	Makefile
	@mkdir -p $(@D)
	cc ${FLAGS} -I${HEAD} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}	$(LIB_DIR)	Makefile
	${LIB}	${NAME}	${OBJS}
	cc ${NAME} -o push_swap

clean:		
	${RM}	${OBJS}	push_swap $(BUILD_DIR)

fclean:	clean 
	${RM}	${NAME}

re:	fclean	all

.PHONY:	all	clean	fclean	re
