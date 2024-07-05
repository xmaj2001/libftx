/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:51:28 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 13:49:51 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftx.h"

void	ft_hook_keyup(t_window window, int (*funct)(), void *param)
{
	mlx_key_hook(window.win, funct, param);
}

void	ft_hook_keypress(t_window window, int (*funct)(), void *param)
{
	ft_hook(window, KeyPress_EVENT, funct, param);
}

void	ft_hook_keyrelease(t_window window, int (*funct)(), void *param)
{
	ft_hook(window, KeyRelease_EVENT, funct, param);
}