NAME = so_long

SRCS = ./src/main.c\
        ./src/get_next_line/get_next_line.c\
        ./src/get_next_line/get_next_line_utils.c\
        ./src/utils.c\
        ./src/utils_1.c\
        ./src/protection.c\
        ./src/movement_perso.c\
        ./src/update_map.c\
        ./src/init_map.c\
        ./src/init_map_1.c

OBJS =   ${SRCS:.c=.o}

RM = rm -f

GCC = cc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
			@echo "$(C_YELLOW_B)Compiling...$(C_RESET)";
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			make -C src/libft
			@${GCC} $(CFLAGS) -o ${NAME} ${OBJS} -lmlx -framework OpenGL -framework AppKit src/libft/libft.a
			@echo "$(C_GREEN_B)Finished!$(C_RESET)";

all:        ${NAME}
			@echo "Creation fichier ${NAME}"

clean:
			@echo "Clean"
			${RM} ${OBJS}

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
