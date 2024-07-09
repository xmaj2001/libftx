/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:33 by xjose             #+#    #+#             */
/*   Updated: 2024/07/08 19:39:13 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <fcntl.h>

t_map	g_map;

int	move_plyar(int key, t_window *window)
{
	if (KEY_D == key)
		g_map.map = ft_find_player(window, g_map, 1);
	else if (KEY_W == key)
		g_map.map = ft_find_player(window, g_map, 2);
	else if (KEY_A == key)
		g_map.map = ft_find_player(window, g_map, 3);
	else if (KEY_S == key)
		g_map.map = ft_find_player(window, g_map, 4);
	ft_inc_map(window, g_map, CENTER);
}
int	main(void)
{
	t_window	*window;
	int			fd;

	fd = open("./map", 0);
	g_map.map = ft_getmap(fd);
	window = ft_create_window("LIBFTX", 1000, 800, BLACK);
	g_map.igw = 40;
	g_map.igh = 40;
	ft_inc_map(window, g_map, CENTER);
	ft_key_hook(window, move_plyar, window);
	ft_start_window(window);
	return (0);
}
