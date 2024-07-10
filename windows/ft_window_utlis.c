/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:10 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 13:38:38 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

int	close_window(t_window *win)
{
	ft_clear_window(win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
}
