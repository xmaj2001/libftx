/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:16:18 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 11:11:29 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

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
	t_size	size;
	int		i;

	i = 0;
	while (map[i])
		i++;
	size.width = ft_strlen(map[0]);
	size.height = i;
	return (size);
}
