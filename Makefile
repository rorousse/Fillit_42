#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 03:14:08 by rorousse          #+#    #+#              #
#    Updated: 2016/08/04 20:10:27 by rorousse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
HEADERS = headers/
SRC_PATH=./sources/
OBJ_PATH=./objs/
SRC = 	fillit.c	\
		affichage.c	\
		error.c		\
		load.c		\
		resolve.c	\
		unif.c		\

LIBS = libft/libft.a
OBJNAME= $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJNAME))
FLAGS = -Wall -Wextra -O0 -g -Wmissing-prototypes -Werror

all: create_obj $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) libft/libft.a -o $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	gcc $(FLAGS) -I $(HEADERS) -c $< -o $@

create_obj :
	make -C libft/
	mkdir -p $(OBJ_PATH)

clean:
	make clean -C libft/
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re:	fclean  all
