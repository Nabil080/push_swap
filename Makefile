NAME = push_swap

SRCS_NAMES =	main.c \
				parsing.c \
				inputs.c \
				outputs.c \
				operations.c \
				operations_2.c \
				operations_utils.c \
				solver.c \

SRCS = ${addprefix srcs/, ${SRCS_NAMES}}

OBJS_DIR = objs

OBJS = ${addprefix ${OBJS_DIR}/, ${SRCS_NAMES:.c=.o}}

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

all : ${NAME}

${NAME} : ${OBJS_DIR} ${OBJS}
	make -C ${LIBFT}
	cc ${OBJS} ${LIBFT}/libft.a -o $@

${OBJS_DIR} :
	mkdir $@

${OBJS_DIR}/%.o : srcs/%.c
	cc ${FLAGS} -I . -I ${LIBFT} -c $< -o $@

clean :
	make clean -C ${LIBFT}
	rm -rf ${OBJS_DIR}

fclean : clean
	make fclean -C ${LIBFT}
	rm -rf ${NAME}

norm :
	make norm -C ${LIBFT}
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${HEADER}

test : all
	./${NAME} 2 1 3 6 5 8

error : all
	./${NAME} -2 1 +3 16 5a 8b

sort : all
	./${NAME} 1 2 3 4 5 6

re : fclean all
