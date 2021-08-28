/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:47:22 by bahn              #+#    #+#             */
/*   Updated: 2021/08/28 00:22:32 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revert(t_frame *frame, int ra, int rb, void (*call_out_func))
{
	int	i;

	i = 0;
	if (call_out_func == NULL)
	{
		while (i++ < rb)
			reverse_rotate_b(frame);
	}
	else
	{
		while (i < ra || i < rb)
		{
			if (i >= rb || length(frame->b) < 2)
				reverse_rotate_a(frame);
			else if (i >= ra || length(frame->a) < 2)
				reverse_rotate_b(frame);
			else
				reverse_rotate_r(frame);
			i++;
		}
	}
}
