# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 00:30:08 by ydahni            #+#    #+#              #
#    Updated: 2022/06/25 19:52:00 by ydahni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -Werror 
SRC = philo_utl.c main.c philo_utl_init.c philo_thread.c
OBJ = ${SRC:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)
	@tput setaf 2; echo "PHILO IS READY"
	
clean:
	@rm -f $(OBJ)
	@tput setaf 1; echo "CLEAN COMPLET"
fclean: clean 
	@rm -f $(NAME)
	@tput setaf 1; echo "FCLEAN COMPLET"

re: fclean all