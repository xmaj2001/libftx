/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:45:10 by xjose             #+#    #+#             */
/*   Updated: 2024/07/09 14:48:01 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"
#include <fcntl.h>

char	*ft_read(int fd)
{
	static char	buffer;
	char		map[4024];
	int			read_size;
	int			x;

	x = 0;
	while (x < 4024)
		map[x++] = '\0';
	x = 0;
	read_size = 1;
	while (1)
	{
		read_size = read(fd, &buffer, 1);
		if (read_size == 0)
			break ;
		map[x] = buffer;
		x++;
	}
	map[x] = '\0';
	return (ft_strdup(map));
}

char	**ft_getmap(int fd)
{
	if (fd < 0)
		return (NULL);
	return (ft_split(ft_read(fd), '\n'));
}

static void	ft_put_img_map(t_window *win, stringg line, t_map map, t_point p)
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

static void	ft_put_map(t_window *win, stringg line, t_map map, t_point p)
{
	int		i;
	void	*ig;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '1')
			ig = ft_setdraw(win, (t_size){map.igw, map.igh}, p.x, p.y, WHITE);
		else if (line[i] == '0')
			ig = ft_setdraw(win, (t_size){map.igw, map.igh}, p.x, p.y, BLACK);
		else if (line[i] == 'C')
			ig = ft_setdraw(win, (t_size){map.igw, map.igh}, p.x, p.y, GOLD);
		else if (line[i] == 'P')
			ig = ft_setdraw(win, (t_size){map.igw, map.igh}, p.x, p.y, RED);
		else if (line[i] == 'E')
			ig = ft_setdraw(win, (t_size){map.igw, map.igh}, p.x, p.y, DARK_GRAY);
		p.x += map.igw + 1;
		ft_destroy_image(win, ig);
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
	ps = ft_postion_image(window, size, postion);
	point.y = ps.y;
	while (*map.map)
	{
		i = 0;
		point.x = ps.x;
		ft_put_map(window, *map.map, map, point);
		map.map++;
		point.y += map.igh;
	}
}

char	**ft_find_player(t_window *window, t_map the_map, int move)
{
	t_point	point;
	char	**map;

	map = the_map.map;
	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x] && map[point.y][point.x] != 'P')
			point.x++;
		if (map[point.y][point.x] == 'P')
		{
			if (move == 1)
			{
				if (map[point.y][point.x + 1] != '1')
				{
					map[point.y][point.x] = '0';
					map[point.y][point.x + 1] = 'P';
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
			else if (move == 3)
			{
				if (map[point.y][point.x - 1] != '1')
				{
					map[point.y][point.x] = '0';
					map[point.y][point.x - 1] = 'P';
				}
			}
			else if (move == 4)
			{
				if (map[point.y + 1][point.x] != '1')
				{
					map[point.y][point.x] = '0';
					map[point.y + 1][point.x] = 'P';
				}
			}
			printf("PX%d PY%d \n", point.x + 1, point.y + 1);
			break ;
		}
		point.y++;
	}
	return (map);
}

t_size	ft_get_size_map_win(char **map, int size_img)
{
	t_size	size;
	int		i;

	i = 0;
	while (map[i])
		i++;
	size.width = ft_strlen(map[0]) * size_img;
	size.height = i * size_img;
	return (size);
}

t_size	ft_get_size_map(char **map)
{
	t_size size;
	int i;

	i = 0;
	while (map[i])
		i++;
	size.width = ft_strlen(map[0]);
	size.height = i;
	return (size);
}