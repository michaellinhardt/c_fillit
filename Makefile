# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 15:26:45 by mconnat           #+#    #+#              #
#    Updated: 2016/01/04 17:56:05 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fillit
SRCS	= 	create_tab.c \
			convert_tab.c \
			convert_tab2.c \
			check_file.c \
			solve_it.c \
			read_file.c \
			main.c

HEADER	=	fillit.h

FLAGS	=	-Wall -Wextra -Werror

HDIR 	=	./includes/
LDIR 	= 	./libs/
SRCSDIR = 	./srcs/

H 		=	$(addprefix $(HDIR), $(HEADER))
SRC 	=	$(addprefix $(SRCSDIR), $(SRCS))

# DETECT PROJECT FOLDER
PATH_CURR		= $(shell /bin/pwd)
ifneq ($(wildcard $(PATH_CURR)/.path_root), )
	PATH_PROJET = $(PATH_CURR)
else
ifneq ($(wildcard $(PATH_CURR)/../.path_root), )
	PATH_PROJET = $(PATH_CURR)/..
else
	PATH_PROJET = 0
endif
endif

# COLOR VAR
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
BLANK			= \033[0;38m
OK				= $(BLANK)[ $(GREEN)OK $(BLANK)]
FAIL			= $(BLANK)[ $(RED)FAIL $(BLANK)]

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

# FOLLOWING RULE ARE FOR WORKING CONFORT ! MAKING GIT MANAGEMENT MORE EASY
# CAN BE DELETED WHEN PROJECT IS OVER OR KEEP HERE, NO MATER !

# VERIFY IF WE ARE IN A PROJECT FOLDER (IS .path_root FILE HERE)
-is-project-folder:
ifeq ($(PATH_PROJET),0)
	$(error Cant find .path_root file to define folder project)
endif

# GITMAX CHECKOUT MIKA BRANCH
-gitmax-setbranch:
	@echo "$(OK)$(YELLOW) Set branch mika on gitmax..$(BLANK)"
	@-cd $(PATH_PROJET)/gitmax && git checkout -b mika
	@-cd $(PATH_PROJET)/gitmax && git checkout mika
	@-cd $(PATH_PROJET)/gitmax && git push origin mika

# SAVE CONTENT OF DEV FOLDER TO GIT42 GITMAX & GITNEST
save-dev: -is-project-folder -gitmax-setbranch
	@echo "$(OK)$(YELLOW) Delete & Create swap folder..$(BLANK)"
	@rm -rf $(PATH_PROJET)/swap
	@mkdir -p $(PATH_PROJET)/swap
	@echo "$(OK)$(YELLOW) Clear gitmax folder..$(BLANK)"
	@touch $(PATH_PROJET)/gitmax/prevent_mv_bug
	@mv $(PATH_PROJET)/gitmax/* $(PATH_PROJET)/swap/
	@rm -rf $(PATH_PROJET)/swap
	@mkdir -p $(PATH_PROJET)/swap
	@echo "$(OK)$(YELLOW) Clear gitnest folder..$(BLANK)"
	@touch $(PATH_PROJET)/gitnest/prevent_mv_bug
	@mv $(PATH_PROJET)/gitnest/* $(PATH_PROJET)/swap/
	@rm -rf $(PATH_PROJET)/swap
	@echo "$(OK)$(YELLOW) Copy dev folder to both gitmax and gitnest..$(BLANK)"
	@cp -r $(PATH_PROJET)/dev/* $(PATH_PROJET)/gitmax/
	@cp -r $(PATH_PROJET)/dev/* $(PATH_PROJET)/gitnest/

status: -is-project-folder save-dev -status
-status:
ifeq ($(wildcard $(PATH_PROJET)/gitmax/.git), )
	@echo "$(FAIL)$(YELLOW) $(PATH_PROJET)/gitmax/ is not a git repository.$(BLANK)"
else
	@-cd $(PATH_PROJET)/gitmax && echo "$(OK) $(YELLOW)$(PATH_PROJET)/gitmax/ git status $(BLANK)" && git status -s
endif
ifeq ($(wildcard $(PATH_PROJET)/gitnest/.git), )
	@echo "$(FAIL)$(YELLOW) $(PATH_PROJET)/gitnest/ is not a git repository.$(BLANK)"
else
	@-cd $(PATH_PROJET)/gitnest && echo "$(OK) $(YELLOW)$(PATH_PROJET)/gitnest/ git status$(BLANK)" && git status -s
endif

#PUSH TO BOTH GITMAX AND GITNEST
push: -is-project-folder -push-var-verif push-gitmax push-gitnest -status
#VERIF IF CORRECT VAR ARE GIVIN TO THE PUSH RULE
-push-var-verif:
ifeq ($(ADD), )
	$(error Syntaxe ex: push ADD="main.c ou -A" COMMIT="commit message")
endif
ifeq ($(COMMIT), )
	$(error Syntaxe ex: push ADD="main.c ou -A" COMMIT="commit message")
endif

#PUSH TO GITMAX
push-gitmax: -is-project-folder -push-var-verif -gitmax-setbranch
ifeq ($(wildcard $(PATH_PROJET)/gitmax/.git), )
	@echo "$(FAIL)$(YELLOW) $(PATH_PROJET)/gitmax/ is not a git repository.$(BLANK)"
else
	@echo "$(OK)$(YELLOW) $(PATH_PROJET)/gitmax/ push$(BLANK)"
	@-cd $(PATH_PROJET)/gitmax && git add $(ADD) && git commit -m "$(COMMIT)"
	@-cd $(PATH_PROJET)/gitmax && git add $(ADD) && git push
endif

#PUSH TO GITNEST
push-gitnest: -is-project-folder -push-var-verif
ifeq ($(wildcard $(PATH_PROJET)/gitnest/.git), )
	@echo "$(FAIL)$(YELLOW) $(PATH_PROJET)/gitnest/ is not a git repository.$(BLANK)"
else
	@echo "$(OK)$(YELLOW) $(PATH_PROJET)/gitnest/ push$(BLANK)"
	@-cd $(PATH_PROJET)/gitnest && git add $(ADD) && git commit -m "$(COMMIT)"
	@-cd $(PATH_PROJET)/gitnest && git add $(ADD) && git push
endif
