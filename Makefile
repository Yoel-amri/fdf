NAME = fdf

SRCS +=	main.c
SRCS +=	test.c
SRCS +=	get_next_line/get_next_line.c


FLAGS = -Wall -Werror -Wextra 

OBJ = $(SRCS:.c=.o)

INC = inc/
LIBT = libft.a
LIB_PATH = libft/
FDF_SHIT = /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: LBT $(NAME)

$(NAME): $(OBJ) $(LIB_PATH)$(LIBT)
	@gcc  $(FLAGS) -I $(INC) $(OBJ) -L $(FDF_SHIT) $(LIB_PATH)$(LIBT) -o $(NAME)

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

LBT:
	@make -C $(LIB_PATH)

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)

re: fclean all