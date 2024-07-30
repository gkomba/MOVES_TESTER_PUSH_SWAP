NAME = tester
SRC = tester.c
OBJ = ${SRC:.c=.o}
RM = rm -f
PRINTF = ft_printf
LIBFT = libft

all: ${NAME}

${NAME}: ${OBJ}
	@make -s -C ${PRINTF}
	@make -s -C ${LIBFT}
	@gcc -o ${NAME} ${OBJ} ${LIBFT}/libft.a ${PRINTF}/libftprintf.a
	@echo "\033[0;32mSUCCESS!\033[0m"

clean:
	@make clean -s -C ${PRINTF}
	@make clean -s -C ${LIBFT}
	@${RM} ${OBJ}

fclean: clean
	@make fclean -s -C ${PRINTF}
	@make fclean -s -C ${LIBFT}
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
