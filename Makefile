# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 19:07:10 by jwon              #+#    #+#              #
#    Updated: 2024/07/05 17:12:53 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftcm.a

SRC				= ./windows/*.c \
				  ./windows/events/*.c \
				  ./unity/*.c 
LIBFT			= ./libft/

MINILIBX				= ./minilibx

		
FLAGS		= -Wall -Werror -Wextra

CP			= gcc

all:
	$(CP) -o app main.c $(SRC) -I ./includes -L$(MINILIBX) -lmlx -lXext -lX11 -lm -L$(LIBFT) -lft