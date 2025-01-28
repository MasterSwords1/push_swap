CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BNAME = checker
SRCS := main.c parcing.c ft_split.c lst_utils.c lst_utils2.c lst_utils3.c \
		lst-manipulation.c operations.c operations2.c simple_sorts.c \
		advanced_sorts.c utils.c utils2.c
BSRCS = main.c parcing.c ft_split.c lst_utils.c lst_utils2.c lst_utils3.c \
		lst-manipulation.c operations.c operations2.c \
		utils.c utils2.c do_ops.c get_next_line.c
OBJS = $(addprefix srcs/, $(SRCS:.c=.o))
BOBJS = $(addprefix bonus/, $(BSRCS:.c=.o))

all: printf $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) srcs/ft_printf/libftprintf.a -o $(NAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD

printf:
	make -C srcs/ft_printf/

clean:
	make clean -C srcs/ft_printf/
	$(RM) $(OBJS) $(OBJS:.o=.d) $(BOBJS) $(BOBJS:.o=.d)

fclean: clean
	make fclean -C srcs/ft_printf/
	$(RM) $(NAME) $(BNAME)

re: fclean all

.PHONY: clean printf

-include $(OBJS:.o=.d)
-include $(BOBJS:.o=.d)