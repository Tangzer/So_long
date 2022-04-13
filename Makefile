NAME = so_long

SRCS = ./srcs/so_long.c\
        ./srcs/get_next_line/get_next_line.c\
        ./srcs/get_next_line/get_next_line_utils.c\
        ./srcs/utils.c\
        ./srcs/utils_1.c\
        ./srcs/protection.c\
        ./srcs/movement_perso.c\
        ./srcs/update_map.c\
        ./srcs/init_map.c\
        ./srcs/init_map_1.c

OBJS =   ${SRCS:.c=.o}

RM = rm -f

GCC = cc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
			@echo "$(C_YELLOW_B)Compiling...$(C_RESET)";
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			make -C srcs/libft
			@${GCC} $(CFLAGS) -o ${NAME} ${OBJS} -lmlx -framework OpenGL -framework AppKit srcs/libft/libft.a
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
