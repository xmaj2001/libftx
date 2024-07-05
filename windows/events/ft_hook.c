/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:39:03 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 13:50:02 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftx.h"

void	ft_hook(t_window window, t_event event, int (*funct)(), void *param)
{
	mlx_hook(window.win, event.code, event.mask, funct, param);
}
