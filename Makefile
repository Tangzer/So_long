NAME = so_long

SRCS = so_long.c\



OBJS =   ${SRCS:.c=.o}

RM = rm -f

GCC = cc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
			@echo "$(C_YELLOW_B)Compiling...$(C_RESET)";
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			@${GCC} -o ${NAME} ${OBJS} -lmlx -framework OpenGL -framework AppKit
			@echo "$(C_GREEN_B)Finished!$(C_RESET)";

all:
			${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus


C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m
