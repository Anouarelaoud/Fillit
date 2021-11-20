# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olahsini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 11:32:34 by olahsini          #+#    #+#              #
#    Updated: 2019/01/17 11:49:48 by olahsini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Werror -Wextra
all : $(NAME)

$(NAME) : *.c
	gcc $(FLAGS) -c maps.c u_function.c valide_file.c recursive.c libft/*.c -I.
	gcc $(FLAGS) main.c *.o -o $@
clean :
	rm -f *.o
	@make -C libft clean
fclean : clean
	rm -f fillit
	@make -C libft fclean
re : fclean all
