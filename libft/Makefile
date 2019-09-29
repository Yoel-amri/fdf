# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-amri <yel-amri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 20:04:02 by yel-amri          #+#    #+#              #
#    Updated: 2019/09/29 21:35:46 by yel-amri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra *.c
	@ar rc libft.a *.o
clean:
	@rm -f *.o
fclean: clean
	@rm -f libft.a

re: fclean all	
