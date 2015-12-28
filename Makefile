# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 15:26:45 by mconnat           #+#    #+#              #
#    Updated: 2015/12/28 07:29:40 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fillit	

SRCS	= 	convert_list.c \
			convert_list2.c \
			create_list.c \
			check_file.c \
			read_file.c \
			main.c

HEADER	=	fillit.h

FLAGS	=	-Wall -Wextra -Werror

HDIR 	=	./includes/
LDIR 	= 	./libs/
SRCSDIR = 	./srcs/

H 		=	$(addprefix $(HDIR), $(HEADER))
SRC 	=	$(addprefix $(SRCSDIR), $(SRCS))

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -o $(NAME) -I$(HDIR) -L$(LDIR) -lft

clean:
	@/bin/rm -rf $(NAME)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

test: re all
	@./fillit sample/valid_four

.PHONY: all clean fclean re test
