CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SERVER		=	server

CLIENT		=	client

ifndef SERVER_SRCS
SERVER_SRCS	=	source/server/server.c \
				source/server/ft_realloc.c \
				source/server/exit_handler.c
endif

SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)

ifndef CLIENT_SRCS
CLIENT_SRCS	=	source/client/client.c
endif

CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)

BSERVER_SRCS	=	source/server/bonus/server_bonus.c \
				source/server/bonus/ft_realloc_bonus.c \
				source/server/bonus/exit_handler_bonus.c

BSERVER_OBJS	=	$(BSERVER_SRCS:.c=.o)

BCLIENT_SRCS	=	source/client/bonus/client_bonus.c

BCLIENT_OBJS	=	$(BCLIENT_SRCS:.c=.o)

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

bonus:
	make SERVER_SRCS="$(BSERVER_SRCS)" CLIENT_SRCS="$(BCLIENT_SRCS)"

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I$(HEADER) -I$(LIBFT_PATH)/$(HEADER) -o $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(CLIENT_OBJS) $(SERVER_OBJS) $(BCLIENT_OBJS) $(BSERVER_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus