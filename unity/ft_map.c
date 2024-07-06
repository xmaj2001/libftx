/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:45:10 by xjose             #+#    #+#             */
/*   Updated: 2024/07/06 13:07:24 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"
#include <fcntl.h>

char	*ft_read(int fd)
{
	char	baffer;
	char	txt[1024];
	int		x;

	x = 0;
	baffer = ' ';
	while (read(fd, &baffer, 1) > 0)
	{
		txt[x++] = baffer;
	}
	txt[x] = '\0';
	return (ft_strdup(txt));
}

char	**ft_getmap(int fd)
{
	if (fd <= 0)
		return (NULL);
	return (ft_split(ft_read(fd), '\n'));
}

void	ft_put_imag_in_map(char *line, t_window *wind, t_map map, t_image *ig)
{
	int	x;

	ig->width = map.size_items.width;
	ig->height = map.size_items.height;
	while (line[x])
	{
		if (line[x] == '1')
		{
			ig->path = map.block_path;
			ft_create_imag(wind, ig, 1);
		}
		else if (line[x] == '0')
		{
			ig->path = map.empty_path;
			ft_create_imag(wind, ig, 1);
		}
		else if (line[x] == 'C')
		{
			ig->path = map.jaba_path;
			ft_create_imag(wind, ig, 1);
		}
		ig->x += map.size_items.width;
		x++;
	}
}

void	ft_create_map(t_window *wind, t_map map)
{
	t_image	ig;
	int		x;
	char	*line;

	while (*map.map)
	{
		line = *map.map;
		ft_put_imag_in_map(line, wind, map, &ig);
		ig.y += map.size_items.height;
		map.map++;
	}
}

t_size	ft_get_size_map_win(char **map, int size_img)
{
	t_size size;
	int i;

	i = 0;
	while (map[i])
		i++;
	size.width = ft_strlen(map[0]) * size_img;
	size.height = i * size_img;
	return (size);
}