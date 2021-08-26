/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:49:27 by bahn              #+#    #+#             */
/*   Updated: 2021/08/26 14:37:30 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  int    sorting(t_frame *frame, int range)
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

static	void	pivoting(t_frame *frame, int range, int *ra, int *rb, int *pb)
{
	while (range--)
	{
		if (frame->a->element > frame->big_pivot)
			*ra += rotate_a(frame);
		else
		{
			*pb += push_b(frame);
			if (frame->b->element > frame->small_pivot)
				*rb += rotate_b(frame);
		}
	}
}

void	a_to_b(t_frame *frame, int range, void (*call_out_func))
{
	int ra_cnt;
	int rb_cnt;
	int pb_cnt;

	if (sorting(frame, range) == TRUE)
		return ;
	select_pivot(frame, frame->a, range);
	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	pivoting(frame, range, &ra_cnt, &rb_cnt, &pb_cnt);
	revert(frame, ra_cnt, rb_cnt, call_out_func);
	a_to_b(frame, ra_cnt, call_out_func);
	b_to_a(frame, rb_cnt, a_to_b);
	b_to_a(frame, pb_cnt - rb_cnt, a_to_b);
}