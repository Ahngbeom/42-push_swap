/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:54:02 by bahn              #+#    #+#             */
/*   Updated: 2021/08/28 13:35:13 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	sorting(t_frame *frame, int range)
{
	if (range <= 3)
	{
		if (range == 1)
			scope_1(frame, frame->b);
		else if (range == 2)
			scope_2(frame, frame->b);
		else
			scope_3(frame, frame->b, range);
		return (TRUE);
	}
	else
		return (FALSE);
}

static	void	pivoting(t_frame *frame, int range, t_op_cnt *op_cnt)
{
	op_cnt->ra = 0;
	op_cnt->rb = 0;
	op_cnt->pa = 0;
	while (range--)
	{
		if (frame->b->element <= frame->small_pivot)
			op_cnt->rb += rotate_b(frame);
		else
		{
			op_cnt->pa += push_a(frame);
			if (frame->a->element <= frame->big_pivot)
				op_cnt->ra += rotate_a(frame);
		}
	}
}

void	b_to_a(t_frame *frame, int range, void (*call_out_func))
{
	t_op_cnt	op_cnt;

	if (sorting(frame, range) == TRUE)
		return ;
	select_pivot(frame, frame->b, range);
	pivoting(frame, range, &op_cnt);
	a_to_b(frame, op_cnt.pa - op_cnt.ra, b_to_a);
	revert(frame, op_cnt.ra, op_cnt.rb, call_out_func);
	a_to_b(frame, op_cnt.ra, b_to_a);
	b_to_a(frame, op_cnt.rb, call_out_func);
}
