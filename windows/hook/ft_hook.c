/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:39:03 by xjose             #+#    #+#             */
/*   Updated: 2024/07/08 14:09:30 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftx.h"

static int	action_key(int key, t_action *action)
{
	if (key == action->key)
		action->f();
	return (0);
}
void	ft_action(t_window *window, t_action *action)
{
	mlx_key_hook(window->win, action_key, action);
}

void	ft_hook(t_window *window, t_event event, int (*funct)(), void *param)
{
	mlx_hook(window->win, event.code, event.mask, funct, param);
}
