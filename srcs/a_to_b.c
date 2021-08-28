/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:49:27 by bahn              #+#    #+#             */
/*   Updated: 2021/08/28 13:34:41 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	sorting(t_frame *frame, int range)
{
	if (range <= 3)
	{
		if (range == 2)
			scope_2(frame, frame->a);
		else if (range == 3)
			scope_3(frame, frame->a, range);
		return (TRUE);
	}
	else
		return (FALSE);
}

static	void	pivoting(t_frame *frame, int range, t_op_cnt *op_cnt)
{
	op_cnt->pb = 0;
	op_cnt->ra = 0;
	op_cnt->rb = 0;
	while (range--)
	{
		if (frame->a->element > frame->big_pivot)
			op_cnt->ra += rotate_a(frame);
		else
		{
			op_cnt->pb += push_b(frame);
			if (frame->b->element > frame->small_pivot)
				op_cnt->rb += rotate_b(frame);
		}
	}
}

void	a_to_b(t_frame *frame, int range, void (*call_out_func))
{
	t_op_cnt	op_cnt;

	if (sorting(frame, range) == TRUE)
		return ;
	select_pivot(frame, frame->a, range);
	pivoting(frame, range, &op_cnt);
	revert(frame, op_cnt.ra, op_cnt.rb, call_out_func);
	a_to_b(frame, op_cnt.ra, call_out_func);
	b_to_a(frame, op_cnt.rb, a_to_b);
	b_to_a(frame, op_cnt.pb - op_cnt.rb, a_to_b);
}
