/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:40:14 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 13:49:00 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

static int	action_key(int key, void *param)
{
	if (key == ((t_key_action *)param)->key)
		((t_key_action *)param)->action();
	return (0);
}

void	ft_key_hook(t_window window, int (*func)(), void *param)
{
	mlx_key_hook(window.win, func, param);
}

void	ft_key_action(t_window window, t_key_action *tlc)
{
	mlx_key_hook(window.win, action_key, tlc);
}