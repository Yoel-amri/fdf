# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 19:06:40 by yel-amri          #+#    #+#              #
#    Updated: 2019/10/18 19:06:48 by yel-amri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = fdf
OBJECTS = draw.o main.o get_board_info.o \
			draw_cntl.o
LIBFT = libft/libft.a
FDF_VAR = /usr/local/lib -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	@gcc $(FLAGS)  $(OBJECTS) $(LIBFT) -L $(FDF_VAR) -o $(NAME)
	@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"
	@echo "\033[0;32m| >>>>>>>>>>>>>>>>>>>>>>>>>> Compiled Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
	@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"
%.o : %.c
	@gcc $(FLAGS) -g -c $< -o $@
$(LIBFT):
	@make -C libft/
clean :
	@make clean -C libft/
	@rm -f $(OBJECTS)
	@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"
	@echo "\033[1;33m| >>>>>>>>>>>>>>>>>>>>>>>>>>  Cleaned Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
	@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"
fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all
