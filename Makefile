CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SERVER		=	server

CLIENT		=	client

SERVER_SRCS	=	source/server/server.c

CLIENT_SRCS	=	

LIBFT_PATH	=	./libft

LIBFT		=	$(LIBFT_PATH)/libft.a

HEADER		= header/

all: $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(SERVER): $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -lft -L$(LIBFT_PATH) -I$(HEADER) -I$(LIBFT_PATH)/$(HEADER) -o $@

$(CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -lft -L$(LIBFT_PATH) -I$(HEADER) -I$(LIBFT_PATH)/$(HEADER) -o $@

clean:
	make -C $(LIBFT_PATH) clean

fclean:
	make -C $(LIBFT_PATH) fclean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re