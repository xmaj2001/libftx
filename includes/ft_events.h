/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:45:06 by xjose             #+#    #+#             */
/*   Updated: 2024/06/29 14:42:01 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define KeyPress_EVENT (t_event) {2, 1L << 0 }
#define KeyRelease_EVENT (t_event){ 3, 1L << 1}

#define MousePress_EVENT (t_event) {4, 1L << 2 }
#define MouseRelease_EVENT (t_event){ 5, 1L << 3}

#define MouseMove_EVENT (t_event){ 6, 1L << 6}
#define MouseEnter_EVENT (t_event){ 7, 1L << 4}
#define MouseLeave_EVENT (t_event){ 8, 1L << 5}
