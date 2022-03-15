
NAME = libft.a

OBJS =   ${SRCS:.c=.o}
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/ft_isalpha.c\
       src/ft_isdigit.c\
       src/ft_isalnum.c\
       src/ft_isascii.c\
       src/ft_isprint.c\
       src/ft_strlen.c\
       src/ft_memset.c\
       src/ft_bzero.c\
       src/ft_memcpy.c\
       src/ft_memmove.c\
       src/ft_strlcpy.c\
       src/ft_toupper.c\
       src/ft_tolower.c\
       src/ft_strchr.c\
       src/ft_strrchr.c\
       src/ft_strncmp.c\
       src/ft_memchr.c\
       src/ft_memcmp.c\
       src/ft_atoi.c\
       src/ft_strlcat.c\
       src/ft_strnstr.c\
       src/ft_calloc.c\
       src/ft_strdup.c\
       src/ft_putchar_fd.c\
       src/ft_putstr_fd.c\
       src/ft_putendl_fd.c\
       src/ft_putnbr_fd.c\
       src/ft_substr.c\
       src/ft_strjoin.c\
       src/ft_strtrim.c\
       src/ft_split.c\
       src/ft_itoa.c\
       src/ft_strmapi.c\
       src/ft_striteri.c\
       src/ft_lstnew.c\
       src/ft_lstadd_front.c\
       src/ft_lstsize.c\
       src/ft_lstlast.c\
       src/ft_lstadd_back.c\
       src/ft_lstdelone.c\
       src/ft_lstclear.c\
       src/ft_lstiter.c\
       src/ft_lstmap.c\
       src/ft_printf/ft_printf.c\
       src/ft_printf/fonctions_supp.c\
       src/ft_printf/ft_print_char.c\
       src/ft_printf/ft_print_hexa.c\
       src/ft_printf/ft_print_int.c\
       src/ft_printf/ft_print_percent.c\
       src/ft_printf/ft_print_pointer.c\
       src/ft_printf/ft_print_string.c\
       src/ft_printf/ft_print_unsigned_int.c\
       src/ft_printf/ft_print_var.c

.c.o:	${SRCS}
	${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJS}
		ar r $(NAME) ${OBJS}

all:	${NAME}

bonus:	${OBJS_BONUS}
		ar r ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
