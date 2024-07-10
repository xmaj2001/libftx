/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:43:19 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 19:51:08 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftx.h"

char	ft_move_player_right(t_window *win, t_map *mp, t_point point)
{
	char	**map;

	map = mp->map;
	if (map[point.y][point.x + 1] != '1')
	{
		if (map[point.y][point.x + 1] == 'E' && mp->items.jaba == 0)
			close_window(win);
		else if (map[point.y][point.x + 1] != 'E')
		{
			map[point.y][point.x] = '0';
			map[point.y][point.x + 1] = 'P';
			mp->move++;
		}
	}
	// else if (map[point.y][point.x + 2] == '0')
	// {
	// 	map[point.y][point.x] = '0';
	// 	map[point.y][point.x + 1] = 'P';
	// 	map[point.y][point.x + 2] = '1';
	// 	mp->move++;
	// }
	return (map[point.y][point.x]);
}

char	ft_move_player_left(t_window *win, t_map *mp, t_point point)
{
	char	**map;

	map = mp->map;
	if (map[point.y][point.x - 1] != '1')
	{
		if (map[point.y][point.x - 1] == 'E' && mp->items.jaba == 0)
			close_window(win);
		else if (map[point.y][point.x - 1] != 'E')
		{
			map[point.y][point.x] = '0';
			map[point.y][point.x - 1] = 'P';
			mp->move++;
		}
	}
	// else if (map[point.y][point.x - 2] == '0')
	// {
	// 	map[point.y][point.x] = '0';
	// 	map[point.y][point.x - 1] = 'P';
	// 	map[point.y][point.x - 2] = '1';
	// 	mp->move++;
	// }
	return (map[point.y][point.x]);
}

char	ft_move_player_top(t_window *win, t_map *mp, t_point point)
{
	char	**map;

	map = mp->map;
	if (map[point.y - 1][point.x] != '1')
	{
		if (map[point.y - 1][point.x] == 'E' && mp->items.jaba == 0)
			close_window(win);
		else if (map[point.y - 1][point.x] != 'E')
		{
			map[point.y][point.x] = '0';
			map[point.y - 1][point.x] = 'P';
			mp->move++;
		}
	}
	// else if (map[point.y - 2][point.x] == '0')
	// {
	// 	map[point.y][point.x] = '0';
	// 	map[point.y - 1][point.x] = 'P';
	// 	map[point.y - 2][point.x] = '1';
	// 	mp->move++;
	// }
	return (map[point.y][point.x]);
}

char	ft_move_player_down(t_window *win, t_map *mp, t_point point)
{
	char	**map;

	map = mp->map;
	if (map[point.y + 1][point.x] != '1')
	{
		if (map[point.y + 1][point.x] == 'E' && mp->items.jaba == 0)
			close_window(win);
		else if (map[point.y + 1][point.x] != 'E')
		{
			map[point.y][point.x] = '0';
			map[point.y + 1][point.x] = 'P';
			mp->move++;
		}
	}
	// else if (map[point.y + 1][point.x] == '1' && map[point.y
	// 	+ 2][point.x] == '0')
	// {
	// 	map[point.y][point.x] = '0';
	// 	map[point.y + 1][point.x] = 'P';
	// 	map[point.y + 2][point.x] = '1';
	// 	mp->move++;
	// }
	return (map[point.y][point.x]);
}
