/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:01:17 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 13:48:53 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

void	ft_start_window(t_window *window)
{
	mlx_loop(window->mlx);
}

t_window	*ft_create_windows(t_window *window)
{
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (NULL);
	window->win = mlx_new_window(window->mlx, window->width, window->height,
			window->title);
	if (window->win == NULL)
		return (NULL);
	ft_set_color(window, window->background);
	return (window);
}
