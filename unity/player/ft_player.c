/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:15 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 18:06:49 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftx.h"

char	**ft_find_player(t_window *window, t_map *mp, int move)
{
	t_point	point;
	char	**map;

	point.y = 0;
	map = mp->map;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x] && map[point.y][point.x] != 'P')
			point.x++;
		if (map[point.y][point.x] == 'P')
		{
			if (move == 1)
				map[point.y][point.x] = ft_move_player_right(window, mp, point);
			else if (move == 2)
				map[point.y][point.x] = ft_move_player_top(window, mp, point);
			else if (move == 3)
				map[point.y][point.x] = ft_move_player_left(window, mp, point);
			else if (move == 4)
				map[point.y][point.x] = ft_move_player_down(window, mp, point);
			break ;
		}
		point.y++;
	}
	return (map);
}
