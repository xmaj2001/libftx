/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:45:10 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 13:49:22 by xjose            ###   ########.fr       */
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

// void	ft_put_imag_in_map(char *line, t_window *wind, t_image *ig)
// {
// 	int	x;

// 	x = 0;
// 	while (line[x])
// 	{
// 		if (line[x] == '1')
// 		{
// 			ig->path = "./assets/other_1.xpm";
// 			ft_create_imag(wind, &ig, 1);
// 		}
// 		else if (line[x] == '0')
// 		{
// 			ig->path = "./assets/other_0.xpm";
// 			ft_create_imag(wind, &ig, 1);
// 		}
// 		else if (line[x] == 'C')
// 		{
// 			ig->path = "./assets/tile_coin.xpm";
// 			ft_create_imag(wind, &ig, 1);
// 		}
// 		ig->x += ig->width;
// 		x++;
// 	}
// }

// void	ft_creat_map(t_window *wind, int size)
// {
// 	char	**map;
// 	int		i;
// 	int		x;
// 	t_image	ig;

// 	ig.width = size;
// 	ig.height = size;
// 	ig.x = 0;
// 	ig.y = 0;
// 	while (map[i])
// 	{
// 		x = 0;
// 		ig.x = 0;
// 		ft_put_imag_in_map(map[i], wind, &ig);
// 		ig.y += 100;
// 		i++;
// 	}
// }

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