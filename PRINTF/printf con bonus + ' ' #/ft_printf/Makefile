# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 13:18:06 by jbaringo          #+#    #+#              #
#    Updated: 2020/01/13 13:25:40 by jbaringo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Werror -Wall -Wextra

LFLAGS = -c

FILES = check_flag.c check_length_precision.c find_percent.c ft_printf.c if_char.c if_hexadecimal.c if_int.c if_int_2.c if_percent.c if_pointer.c if_string.c if_unsigned.c print_ptr.c set_init.c ft_strlen.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_isdigit.c

OBJ = ${FILES:.c=.o}


all : $(NAME)

$(NAME): $(FILES)
	gcc $(CFLAGS) $(LFLAGS) $(FILES)
	ar rc $(NAME) $(OBJ)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re