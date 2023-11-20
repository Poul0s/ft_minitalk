CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SERVER		=	server

CLIENT		=	client

SERVER_SRCS	=	source/server/server.c \
				source/server/ft_realloc.c \
				source/server/exit_handler.c

SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)

CLIENT_SRCS	=	source/client/client.c

CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)

LIBFT_PATH	=	./libft

LIBFT		=	$(LIBFT_PATH)/libft.a

HEADER		= header/

all: $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(SERVER): $(LIBFT) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -lft -L$(LIBFT_PATH) -o $@

$(CLIENT): $(LIBFT) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -lft -L$(LIBFT_PATH) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I$(HEADER) -I$(LIBFT_PATH)/$(HEADER) -o $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re