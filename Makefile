# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= src
CLIENT_SRCS_DIR	:= $(SRCS_DIR)/client
SERVER_SRCS_DIR	:= $(SRCS_DIR)/server
OBJS_DIR		:= obj
LIBS_DIR		:= lib
LIBFT_DIR		:= $(LIBS_DIR)/libft

# ******************************* General Files ********************************
HEADERS			:= minitalk.h
LIBFT			:= libft.a
LIBFT_SRCS		:= ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_doublelst_addback.c \
					ft_doublelst_addfront.c \
					ft_doublelst_clear.c \
					ft_doublelst_delone.c \
					ft_doublelst_iter.c \
					ft_doublelst_last.c \
					ft_doublelst_map.c \
					ft_doublelst_new.c \
					ft_doublelst_size.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_printf.c \
					ft_putaddr_hex.c \
					ft_putchar.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr.c \
					ft_putnbr_fd.c \
					ft_putnbr_hex.c \
					ft_putnbr_unsigned.c \
					ft_putstr.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strcmp.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c \
					get_next_line.c
LIBFT_HEADER	:= libft.h

# ******************************** Client Files ********************************
CLIENT_NAME	:= client
CLIENT_MAIN	:= client.c
CLIENT_SRCS	:= ft_send_byte.c
CLIENT_OBJS	:= $(CLIENT_SRCS:.c=.o)

# ******************************** Server Files ********************************
SERVER_NAME	:= server
SERVER_MAIN	:= server.c
SERVER_SRCS	:=
SERVER_SRCS	:= ft_install_signal.c \
				ft_print_pid.c \
				ft_sigone_handler.c \
				ft_sigzero_handler.c \
				ft_update_byte.c
SERVER_OBJS	:= $(SERVER_SRCS:.c=.o)

# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
INCLUDES	:= -I $(INCLUDES_DIR) -I $(LIBFT_DIR)/$(INCLUDES_DIR)
LIBS		:= -L $(LIBFT_DIR) -lft

# ******************************* Other commands *******************************
RM		:= rm -rf
MKDIR	:= mkdir -p

# ********************************** Targets ***********************************
all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(addprefix $(OBJS_DIR)/, $(CLIENT_OBJS)) \
				$(LIBFT_DIR)/$(LIBFT) \
				$(addprefix $(INCLUDES_DIR)/, $(HEADERS)) $(CLIENT_MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) \
		$(addprefix $(OBJS_DIR)/, $(CLIENT_OBJS)) \
		$(CLIENT_MAIN) -o $(CLIENT_NAME)

$(SERVER_NAME): $(addprefix $(OBJS_DIR)/, $(SERVER_OBJS)) \
				$(LIBFT_DIR)/$(LIBFT) \
				$(addprefix $(INCLUDES_DIR)/, $(HEADERS)) $(SERVER_MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) \
		$(addprefix $(OBJS_DIR)/, $(SERVER_OBJS)) \
		$(SERVER_MAIN) -o $(SERVER_NAME)

$(LIBFT_DIR)/$(LIBFT): $(LIBFT_DIR)/$(INCLUDES_DIR)/$(LIBFT_HEADER) \
						$(addprefix $(LIBFT_DIR)/$(SRCS_DIR)/, $(LIBFT_SRCS))
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(CLIENT_SRCS_DIR)/%.c \
					$(addprefix $(INCLUDES_DIR)/, $(HEADERS)) \
					$(LIBFT_DIR)/$(INCLUDES_DIR)/$(LIBFT_HEADER)
	@$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(OBJS_DIR)/%.o: $(SERVER_SRCS_DIR)/%.c \
					$(addprefix $(INCLUDES_DIR)/, $(HEADERS)) \
					$(LIBFT_DIR)/$(INCLUDES_DIR)/$(LIBFT_HEADER)
	@$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
