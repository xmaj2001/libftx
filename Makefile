# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 19:07:10 by jwon              #+#    #+#              #
#    Updated: 2024/07/05 13:43:38 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftcm.a

SRC				= ./windows/*.c \
				  ./windows/events/*.c \
				  ./unity/*.c 
LIBFT			= ./libft/*.c

MINILIBX				= ./libx/minilibx

		
FLAGS		= -Wall -Werror -Wextra

CP			= gcc

all:
	$(CP) -o app main.c $(LIBFT) $(SRC) -I ./includes -L$(MINILIBX) -lmlx -lXext -lX11 -lm