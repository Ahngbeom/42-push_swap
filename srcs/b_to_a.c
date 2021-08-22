/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:54:02 by bahn              #+#    #+#             */
/*   Updated: 2021/08/23 03:02:17 by bahn             ###   ########.fr       */
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

void	b_to_a(t_frame *frame, int range)
{
    int	i	= 0;
	int ra_cnt = 0;
	int	rb_cnt = 0;
	int	pa_cnt = 0;
	
	if (sorting(frame, range) == TRUE)
        return ;
	frame->big_pivot = select_big_pivot(frame->b, range);
	frame->small_pivot = select_small_pivot(frame->b, range);
	while (range--)
	{
		if (frame->b->element <= frame->small_pivot)
			rb_cnt += rotate_b(frame);
		else
		{
			pa_cnt += push_a(frame);
			if (length(frame->a) >= 2 && frame->a->element <= frame->big_pivot)
				ra_cnt += rotate_a(frame);
		}
	}
	a_to_b(frame, pa_cnt - ra_cnt, b_to_a);
	while (i < ra_cnt || i < rb_cnt)
	{
		if (i >= rb_cnt || length(frame->b) < 2)
			reverse_rotate_a(frame);
		else if (i >= ra_cnt || length(frame->a) < 2)
			reverse_rotate_b(frame);
		else
			reverse_rotate_r(frame);
		i++;
	}
	a_to_b(frame, ra_cnt, b_to_a);
	b_to_a(frame, rb_cnt);
}