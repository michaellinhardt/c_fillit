# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconnat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 15:26:45 by mconnat           #+#    #+#              #
#    Updated: 2015/12/27 00:35:26 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fillit	

SRCS	= 	convert_list.c \
			convert_list2.c \
			create_list.c \
			check_file.c \
			read_file.c \
			solveit.c \
			printit.c \
			main.c

HEADER	=	fillit.h

FLAGS	=	-Wall -Wextra -Werror

HDIR 	=	./includes/
LDIR 	= 	./libs/
SRCSDIR = 	./srcs/

H 		=	$(addprefix $(HDIR), $(HEADER))
SRC 	=	$(addprefix $(SRCSDIR), $(SRCS))

all		: $(NAME)

$(NAME)	:
	@gcc $(FLAGS) $(SRC) -o $(NAME) -I$(HDIR) -L$(LDIR) -lft

clean	:
	@rm -rf $(NAME)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

test	: fclean all
	./fillit sample/valid_four

.PHONY: all clean fclean re
