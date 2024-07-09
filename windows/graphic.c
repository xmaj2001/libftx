/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:31:41 by xjose             #+#    #+#             */
/*   Updated: 2024/07/09 21:43:49 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

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

void	*ft_setdraw(t_window *window, t_size size, int px, int py,
		enum e_color cor)
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;

	x = 0, y = 0;
	img_ptr = mlx_new_image(window->mlx, size.width, size.height);
	if (img_ptr == NULL)
		return (NULL);
	data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	while (y++ < size.height)
	{
		x = 0;
		while (x++ < size.width)
			data[y * (size_line / 4) + x] = cor;
	}
	mlx_put_image_to_window(window->mlx, window->win, img_ptr, px, py);
	return (img_ptr);
}
void	ft_set_font(t_window *wind, stringg font)
{
	void	*mlx;
	void	*win;

	mlx = wind->mlx;
	win = wind->win;
	mlx_set_font(mlx, win, font);
}

void	ft_put_text(t_window *win, stringg texto, enum e_postion postion,
		enum e_color cor)
{
	t_point	point;

	point = ft_postion(win, (t_size){20, 20}, postion);
	mlx_string_put(win->mlx, win->win, point.x, point.y, cor, texto);
}
