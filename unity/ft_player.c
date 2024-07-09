/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:15 by xjose             #+#    #+#             */
/*   Updated: 2024/07/09 22:54:56 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"


static char	ft_move_player_x(char **map, t_point point, int move)
{
	if (move == 1)
	{
		if (map[point.y][point.x + 1] != '1')
		{
			map[point.y][point.x] = '0';
			map[point.y][point.x + 1] = 'P';
		}
	}
	else if (move == 3)
	{
		if (map[point.y][point.x - 1] != '1')
		{
			map[point.y][point.x] = '0';
			map[point.y][point.x - 1] = 'P';
		}
	}
	return (map[point.y][point.x]);
}

static char	ft_move_player_y(char **map, t_point point, int move)
{
	if (move == 4)
	{
		if (map[point.y + 1][point.x] != '1')
		{
			map[point.y][point.x] = '0';
			map[point.y + 1][point.x] = 'P';
		}
	}
	else if (move == 2)
	{
		if (map[point.y - 1][point.x] != '1')
		{
			map[point.y][point.x] = '0';
			map[point.y - 1][point.x] = 'P';
		}
	}
	return (map[point.y][point.x]);
}

char	**ft_find_player(t_window *window, char **map, int move)
{
	t_point	point;

	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x] && map[point.y][point.x] != 'P')
			point.x++;
		if (map[point.y][point.x] == 'P')
		{
			if (move == 1 || move == 3)
				map[point.y][point.x] = ft_move_player_x(map, point, move);
			else if (move == 2 || move == 4)
				map[point.y][point.x] = ft_move_player_y(map, point, move);
			break ;
		}
		point.y++;
	}
	return (map);
}
