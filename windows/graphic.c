/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:31:41 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 13:48:56 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

void	*ft_create_imag(t_window *window, t_image *img, bool put)
{
	void	*ig;
	int		x;
	int		y;

	x = img->x;
	y = img->y;
	ig = mlx_xpm_file_to_image(window->mlx, img->path, &img->width,
			&img->height);
	if (ig == NULL)
		return (NULL);
	if (put == true)
		mlx_put_image_to_window(window->mlx, window->win, ig, x, y);
	return (ig);
}

void	ft_set_color(t_window *window, enum e_color cor)
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;

	x = 0, y = 0;
	img_ptr = mlx_new_image(window->mlx, window->width, window->height);
	if (img_ptr == NULL)
		return ;
	data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	while (y++ < window->height)
	{
		x = 0;
		while (x++ < window->width)
			data[y * (size_line / 4) + x] = cor;
	}
	mlx_put_image_to_window(window->mlx, window->win, img_ptr, 0, 0);
}

void	ft_draw(t_window *window, t_size size, enum e_color cor, t_point point)
{
	void *img_ptr;
	int *data;
	int bpp;
	int size_line;
	int endian;

	int x = 0, y = 0;
	img_ptr = mlx_new_image(window->mlx, size.width, size.height);
	if (img_ptr == NULL)
		return ;
	data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	while (y++ < size.height)
	{
		x = 0;
		while (x++ < size.width)
			data[y * (size_line / 4) + x] = cor;
	}
	mlx_put_image_to_window(window->mlx, window->win, img_ptr, point.x,
		point.y);
}