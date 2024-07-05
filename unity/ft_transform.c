/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:23:27 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 13:49:29 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

void	ft_move(t_transform *t, t_basic_controller bc, int key)
{
	if (bc.key_up == key)
		t->position.x -= bc.speed;
	if (bc.key_down == key)
		t->position.x += bc.speed;
	if (bc.key_left == key)
		t->position.y -= bc.speed;
	if (bc.key_rigth == key)
		t->position.y += bc.speed;
}
