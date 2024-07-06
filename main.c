/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:33 by xjose             #+#    #+#             */
/*   Updated: 2024/07/06 19:03:51 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	main(void)
{
	t_window	windo;

	windo.title = "LIBFTX";
	windo.background = BLACK;
	windo.width = 1000;
	windo.height = 600;
	ft_create_windows(&windo);
	ft_start_window(&windo);
	return (0);
}
