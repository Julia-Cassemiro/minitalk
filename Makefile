P_LIBFT = ./includes/libft/

FILES = ./server.c ./client.c ./utils.c ./utils2.c
SRC = $(FILES:.c=.o)

LIBFT = $(P_LIBFT)libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

all: comp server client

server:
	@$(CC) $(CFLAGS) ./server.o $(LIBFT) -o server
	@echo Server done.

client:
	@$(CC) $(CFLAGS) ./client.o ./utils.o ./utils2.o $(LIBFT) -o client
	@echo Client done.

comp: $(SRC)
	@make --no-print-directory -C $(P_LIBFT)

%.o: %.c
	@$(CC) -c $< -o $@

bonus: all

clean:
	@make clean --no-print-directory -C $(P_LIBFT)
	@$(RM) $(SRC)
	@echo All clean colega.

fclean: clean
	@make fclean --no-print-directory -C $(P_LIBFT)
	@$(RM) client server

re: fclean all