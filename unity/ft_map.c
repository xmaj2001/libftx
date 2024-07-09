/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:45:10 by xjose             #+#    #+#             */
/*   Updated: 2024/07/09 21:18:31 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"
#include <fcntl.h>

void	ft_put_img_map(t_window *win, stringg line, t_map map, t_point p)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '1')
			ft_put_image(win, map.block_path, map.igw, map.igh, p.x, p.y);
		else if (line[i] == '0')
			ft_put_image(win, map.empty_path, map.igw, map.igh, p.x, p.y);
		else if (line[i] == 'C')
			ft_put_image(win, map.jaba_path, map.igw, map.igh, p.x, p.y);
		else if (line[i] == 'P')
			ft_put_image(win, map.player_path, map.igw, map.igh, p.x, p.y);
		else if (line[i] == 'E')
			ft_put_image(win, map.exit_path, map.igw, map.igh, p.x, p.y);
		p.x += map.igw;
	}
}

void	ft_put_map2(t_window *win, stringg line, t_map2 mp, t_point p, bool a)
{
	int		i;
	void	*ig;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '1')
			ig = ft_setdraw(win, (t_size){mp.igw, mp.igh}, p.x, p.y, mp.block);
		else if (line[i] == '0')
			ig = ft_setdraw(win, (t_size){mp.igw, mp.igh}, p.x, p.y, mp.empty);
		else if (line[i] == 'C')
			ig = ft_setdraw(win, (t_size){mp.igw, mp.igh}, p.x, p.y, mp.jaba);
		else if (line[i] == 'P')
			ig = ft_setdraw(win, (t_size){mp.igw, mp.igh}, p.x, p.y, mp.player);
		else if (line[i] == 'E')
			ig = ft_setdraw(win, (t_size){mp.igw, mp.igh}, p.x, p.y, mp.exit);
		p.x += mp.igw + 1;
		if (a)
			usleep(5500);
		ft_destroy_image(win, ig);
	}
}

void	ft_inc_map2(t_window *window, t_map2 map, enum e_postion postion, bool a)
{
	t_point	point;
	t_point	ps;
	t_size	size;
	int		idx;
	int		i;

	idx = 0;
	size = ft_get_size_map(map.map);
	size.width *= map.igw;
	size.height *= map.igh;
	ps = ft_postion(window, size, postion);
	point.y = ps.y;
	while (*map.map)
	{
		i = 0;
		point.x = ps.x;
		ft_put_map2(window, *map.map, map, point, a);
		map.map++;
		point.y += map.igh;
	}
}

void	ft_inc_map(t_window *window, t_map map, enum e_postion postion)
{
	t_point	point;
	t_point	ps;
	t_size	size;
	int		idx;
	int		i;

	idx = 0;
	size = ft_get_size_map(map.map);
	size.width *= map.igw;
	size.height *= map.igh;
	ps = ft_postion(window, size, postion);
	point.y = ps.y;
	while (*map.map)
	{
		i = 0;
		point.x = ps.x;
		ft_put_img_map(window, *map.map, map, point);
		map.map++;
		point.y += map.igh;
	}
}
