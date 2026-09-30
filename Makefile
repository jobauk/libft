# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaukes <jaukes@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2026/09/28 14:03:36 by jaukes        #+#    #+#                  #
#    Updated: 2026/09/30 17:07:18 by jaukes        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

all:
	cc -Wall -Wextra -Werror -c *.c

clean:
	rm -f *.o

fclean:

re:

