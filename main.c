/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:33 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 19:13:43 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <fcntl.h>

t_map	g_map;

int	move_player(int key, t_window *win)
{
	if (KEY_W == key)
		g_map.map = ft_find_player(win, &g_map, 2);
	else if (KEY_S == key)
		g_map.map = ft_find_player(win, &g_map, 4);
	else if (KEY_D == key)
		g_map.map = ft_find_player(win, &g_map, 1);
	else if (KEY_A == key)
		g_map.map = ft_find_player(win, &g_map, 3);
	ft_get_item_map(&g_map);
	free(ft_setdraw(win, (t_size){win->width, 20}, 10, 1, BLACK));
	ft_put_text(win, "JABA: ", (t_point){20, 20}, WHITE);
	ft_put_text(win, ft_itoa(g_map.items.jaba), (t_point){55, 20}, LIME);
	ft_put_text(win, "steps: ", (t_point){win->width - 100, 20}, WHITE);
	ft_put_text(win, ft_itoa(g_map.move), (t_point){win->width - 55, 20},
		LIME);
	ft_inc_map(win, g_map, CENTER, false);
}

int	main(void)
{
	t_window	*window;
	int			fd;

	fd = open("./map", 0);
	ft_getmap(fd, window, &g_map);
	g_map.block = WHITE;
	g_map.empty = BLACK;
	g_map.player = RED;
	g_map.jaba = YELLOW;
	g_map.exit = GREEN;
	g_map.igw = 40;
	g_map.igh = 40;
	window = ft_create_window("LIBFTX", 1000, 800, BLACK);
	ft_inc_map(window, g_map, CENTER, true);
	ft_keyup(window, move_player, window);
	ft_destroy_event(window, close_window, window);
	ft_start_window(window);
	return (0);
}
