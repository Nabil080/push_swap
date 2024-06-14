NAME = push_swap

FLAGS = -Wall -Wextra -Werror

LIBS = libft \

INCLUDES =	includes \
			${foreach lib, ${LIBS}, ${lib} ${lib}/includes}
			
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

all : ${NAME}

${NAME} : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, make -C ${lib}}
	cc ${FLAGS} ${OBJS} ${foreach lib, ${LIBS}, ${lib}/${lib}.a} -o $@

${OBJS_DIR} :
	mkdir $@

${OBJS_DIR}/%.o : srcs/%.c
	cc ${FLAGS} ${foreach include, ${INCLUDES}, -I ${include}} -c $< -o $@

clean :
	${foreach lib, ${LIBS}, make clean -C ${lib}}
	rm -rf ${OBJS_DIR}

fclean : clean
	${foreach lib, ${LIBS}, make fclean -C ${lib}}
	rm -rf ${NAME}

norm :
	${foreach lib, ${LIBS}, make norm -C ${lib}}
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCLUDES}

play : play_start re play_end

play_start :
	mv srcs/main.c srcs/tmp.c
	mv srcs/player.c srcs/main.c

play_end :
	mv srcs/main.c srcs/player.c
	mv srcs/tmp.c srcs/main.c

playtest : play test

test : all
	./${NAME} 2 9 7 0 6

error : all
	./${NAME} -2 1 +3 16 5a 8b

sort : all
	./${NAME} 1 2 3 4 5 6

re : fclean all
