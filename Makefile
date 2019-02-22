# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtudes <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 00:02:56 by vtudes            #+#    #+#              #
#    Updated: 2018/03/09 04:24:21 by vtudes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
EXEC = fractol

INCLUDES = includes

MLX = mlx
LIBFT = libft

SRCS =	srcs/main.c\
		srcs/hooks.c\
		srcs/interface.c\
		srcs/mandelbrot.c\
		srcs/multithread.c\
		srcs/burningship.c\
		srcs/julia.c\
		srcs/hugulus.c\
		srcs/pmicelius.c\
		srcs/bacrozus.c\

OBJS = $(addprefix ./objs/,$(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
LFLAGS = -L$(MLX) -L$(LIBFT) -lft -lmlx -framework OpenGl -framework Appkit

all: $(EXEC)

$(EXEC): $(OBJS)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(OBJS) -o $(EXEC) $(LFLAGS)

$(OBJS): ./objs/%.o: %.c
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -f $(OBJS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make clean -C libft/


re: fclean all


.PHONY: all fclean