CLIENT_NAME = client
SERVER_NAME = server
CLIENT_B_NAME = client_bonus
SERVER_B_NAME = server_bonus


SRC_CLIENT = client.c utils.c
SRC_B_CLIENT = client_bonus.c utils.c
SRC_SERVER = server.c utils.c
SRC_B_SERVER = server_bonus.c utils.c


CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJB_CLIENT = $(SRC_B_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJB_SERVER = $(SRC_B_SERVER:.c=.o)

all: $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_B_NAME) $(SERVER_B_NAME)

$(CLIENT_NAME): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@

$(SERVER_NAME): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@

$(CLIENT_B_NAME): $(OBJB_CLIENT)
	$(CC) $(CFLAGS) $(OBJB_CLIENT) -o $@

$(SERVER_B_NAME): $(OBJB_SERVER)
	$(CC) $(CFLAGS) $(OBJB_SERVER) -o $@

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJB_CLIENT) $(OBJB_SERVER)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_B_NAME) $(SERVER_B_NAME)

re: fclean all

