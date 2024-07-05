/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:25:46 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 13:49:58 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftx.h"

void	ft_hook_mousepress(t_window window, int (*funct)(), void *param)
{
	ft_hook(window, KeyPress_EVENT, funct, param);
}

void	ft_hook_mouserelease(t_window window, int (*funct)(), void *param)
{
	ft_hook(window, KeyRelease_EVENT, funct, param);
}