######################## SETTINGS ########################

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBS = libft

INCLUDES =	includes \
			${foreach lib, ${LIBS}, ${lib} ${lib}/includes}

######################## SOURCES ########################

SRCS_NAMES =	main.c \
				parsing.c \
				outputs.c \
				operations.c \
				operations_2.c \
				operations_utils.c \
				stack.c \
				solver.c \
				solver_utils.c

SRCS_DIR = srcs/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.c=.o}}

######################## BONUS ########################

BONUS = checker

BONUS_NAMES =	main_bonus.c \
				parsing.c \
				outputs.c

BONUS_SRCS = ${addprefix ${SRCS_DIR}, ${BONUS_NAMES}}

BONUS_OBJS = ${addprefix ${OBJS_DIR}, ${BONUS_NAMES:.c=.o}}

######################## BASIC RULES ########################

all : ${NAME}

re : fclean
	${MAKE} all

clean :
	${foreach lib, ${LIBS}, ${MAKE} clean -C ${lib}}
	rm -rf ${OBJS_DIR}

fclean : clean
	${foreach lib, ${LIBS}, ${MAKE} fclean -C ${lib}}
	rm -f ${NAME}
	rm -f ${BONUS}

norm :
	${foreach lib, ${LIBS}, ${MAKE} norm -C ${lib}}
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCLUDES}
	
######################## COMPILATION ########################

${NAME} : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o $@

${OBJS_DIR} :
	mkdir $@

${OBJS_DIR}%.o : ${SRCS_DIR}%.c
	${CC} ${FLAGS} ${CPPFLAGS} ${foreach include, ${INCLUDES},-I ${include}} -c $< -o $@

######################## player ########################

play : play_start re play_end

play_start :
	mv srcs/main.c srcs/tmp.c
	mv srcs/player.c srcs/main.c

play_end :
	mv srcs/main.c srcs/player.c
	mv srcs/tmp.c srcs/main.c

######################## TESTERS ########################

test : all
	./${NAME} 2 9 7 0 6

error : all
	./${NAME} -2 1 +3 16 5a 8b

sort : all
	./${NAME} 1 2 3 4 5 6

######################## BONUS ########################

bonus : ${BONUS}

${BONUS} : ${OBJS_DIR} ${BONUS_OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} ${BONUS_OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o $@