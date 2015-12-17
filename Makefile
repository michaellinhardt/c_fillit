# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconnat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 15:26:45 by mconnat           #+#    #+#              #
#    Updated: 2015/12/09 16:24:08 by mconnat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fillit	

SRCS	= 	convert_list.c \
			convert_list2.c \
			create_list.c \
			check_file.c \
			read_file.c \
		  	main.c \
		  	libft.a \

HEADER	= 	fillit.h \

FLAGS	=	-Wall -Wextra -Werror

HDIR 	= 	./includes/ 

SRCSDIR = 	./srcs/

H 		=	$(addprefix $(HDIR), $(HEADER))

SRC 	=	$(addprefix $(SRCSDIR), $(SRCS))



all		: $(NAME)

$(NAME)	:
	@gcc $(FLAGS) $(SRC) -o $(NAME) -I $(HDIR) 

clean	:
	@rm -rf $(NAME)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY: all make clean fclean re
