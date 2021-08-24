/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:54:02 by bahn              #+#    #+#             */
/*   Updated: 2021/08/24 15:08:16 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  int     sorting(t_frame *frame, int range)
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

static	void	pivoting(t_frame *frame, int range, int *ra, int *rb, int *pa)
{
	while (range--)
	{
		if (frame->b->element <= frame->small_pivot)
			*rb += rotate_b(frame);
		else
		{
			*pa += push_a(frame);
			if (length(frame->a) >= 2 && frame->a->element <= frame->big_pivot)
				*ra += rotate_a(frame);
		}
	}
}

void	b_to_a(t_frame *frame, int range, void (*call_out_func))
{
	int ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	
	if (sorting(frame, range) == TRUE)
        return ;
	select_pivot(frame, frame->b, range);
	ra_cnt = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	pivoting(frame, range, &ra_cnt, &rb_cnt, &pa_cnt);
	a_to_b(frame, pa_cnt - ra_cnt, b_to_a);
	revert(frame, ra_cnt, rb_cnt, call_out_func);
	a_to_b(frame, ra_cnt, b_to_a);
	b_to_a(frame, rb_cnt, call_out_func);
}