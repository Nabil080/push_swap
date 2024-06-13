NAME = libft.a

IS_CHECKERS_FILES =	ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \

PRINTERS_FILES =	ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putnbr_base.c \
					ft_printf.c \

STRINGS_FILES =	ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_strmapi.c \
				ft_striteri.c \

MEMORY_FILES =	ft_memset.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_bzero.c \
				ft_calloc.c \

CONVERTERS_FILES =	ft_itoa.c \
					ft_atoi.c \
					ft_toupper.c \
					ft_tolower.c \

LINKED_LISTS_FILES =	ft_lstnew.c \
						ft_lstadd_front.c \
						ft_lstsize.c \
						ft_lstlast.c \
						ft_lstadd_back.c \
						ft_lstdelone.c \
						ft_lstclear.c \
						ft_lstiter.c \
						ft_lstmap.c \

SRCS_NAMES =	${addprefix is_checkers/, ${IS_CHECKERS_FILES}} \
				${addprefix printers/, ${PRINTERS_FILES}} \
				${addprefix strings/, ${STRINGS_FILES}} \
				${addprefix memory/, ${MEMORY_FILES}} \
				${addprefix converters/, ${CONVERTERS_FILES}} \
				${addprefix linked_lists/, ${LINKED_LISTS_FILES}} \

SRCS = ${addprefix srcs/, ${SRCS_NAMES}}

OBJS_DIR = objs

OBJS = ${addprefix ${OBJS_DIR}/, ${SRCS_NAMES:.c=.o}}

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS_DIR} ${OBJS}
	ar -rc ${NAME} ${OBJS}

${OBJS_DIR}:
	mkdir ${OBJS_DIR}
	mkdir ${OBJS_DIR}/is_checkers
	mkdir ${OBJS_DIR}/printers
	mkdir ${OBJS_DIR}/strings
	mkdir ${OBJS_DIR}/memory
	mkdir ${OBJS_DIR}/converters
	mkdir ${OBJS_DIR}/linked_lists

${OBJS_DIR}/%.o : srcs/%.c
	cc -I . ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f ${NAME}

norm :
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${HEADER}

re: fclean all