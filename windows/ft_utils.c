/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:44:22 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 13:48:47 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

void	ft_destroy_image(t_window *window, void *img)
{
	mlx_destroy_image(window->mlx, img);
}

void	ft_clear_window(t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
}