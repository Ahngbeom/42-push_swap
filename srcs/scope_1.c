/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:47:04 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 15:03:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scope_1(t_frame *frame, t_stack *stack)
{
	if (stack == frame->b)
		push_a(frame);
}
