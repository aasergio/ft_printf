NAME		= libftprintf.a
SRCS		= ft_printf.c ft_printf_utils.c
LIBFT_SRC	= libft
LIBFT		= $(LIBFT_SRC)/libft.a
OBJS_DIR 	= obj

INCLUDES	= -I $(LIBFT_SRC)

AR		= ar -rcs
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP
RM		= rm -rf

OBJS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_SRC)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_SRC) clean

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_SRC) fclean

re: fclean all 

-include $(DEPS)

.PHONY: all clean fclean re
