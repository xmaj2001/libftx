/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:33 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 13:38:09 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <fcntl.h>

t_map2	g_map;

int	move_player(int key, t_window *win)
{
	if (KEY_W == key)
		g_map.map = ft_find_player (win, g_map.map, 2);
	else if (KEY_S == key)
		g_map.map = ft_find_player (win, g_map.map, 4);
	else if (KEY_D == key)
		g_map.map = ft_find_player (win, g_map.map, 1);
	else if (KEY_A == key)
		g_map.map = ft_find_player (win, g_map.map, 3);
	ft_inc_map2(win, g_map, CENTER, false);
}


int	main(void)
{
	t_window	*window;
	int			fd;

	g_map.block = WHITE;
	g_map.empty = BLACK;
	g_map.player = RED;
	g_map.jaba = YELLOW;
	g_map.exit = DARK_GRAY;
	fd = open("./map", 0);
	g_map.map = ft_getmap(fd);
	g_map.igw = 40;
	g_map.igh = 40;
	window = ft_create_window("LIBFTX", 1000, 800, BLACK);
	ft_inc_map2(window, g_map, CENTER, true);
	ft_key_hook(window, move_player, window);
	ft_destroy_event(window, close_window, window);
	ft_start_window(window);
	return (0);
}
