# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olahsini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 15:17:32 by olahsini          #+#    #+#              #
#    Updated: 2018/11/07 15:17:39 by olahsini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./*.c
FLAG = -Wall -Wextra -Werror
OBJ = ./*.o

all : $(NAME)

$(NAME):
	gcc  -c $(FLAG) $(SRC)
	ar rc $(NAME) $(OBJ)
   
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
