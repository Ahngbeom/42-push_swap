/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:54:02 by bahn              #+#    #+#             */
/*   Updated: 2021/08/18 19:21:21 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  int     sorting(t_frame *frame, int range)
{
    if (range <= 3)
	{
		if (range == 1)
			push_a(frame);
		else if (range == 2)
		{	
			if (frame->b->element < frame->b->next->element)
				swap_b(frame);
			push_a(frame);
			push_a(frame);
		}
		else
		{
			if (length(frame->b) == 3)
			{
				while (check_desc(frame->b) == FALSE)
				{
					if (frame->b->element == min(frame->b, length(frame->b)))
						rotate_b(frame);
					else if (last_element(frame->b)->element == max(frame->b, length(frame->b)))
						reverse_rotate_b(frame);
					else
						swap_b(frame);
				}
			}
			else
			{
				if (frame->b->element == min(frame->b, range))
				{
					swap_b(frame);
					rotate_b(frame);
					swap_b(frame);
					reverse_rotate_b(frame);
					if (frame->b->next->element == max(frame->b, range))
						swap_b(frame);
				}
				else if (frame->b->next->element == min(frame->b, range))
				{
					rotate_b(frame);
					swap_b(frame);
					reverse_rotate_b(frame);
					if (frame->b->next->element == max(frame->b, range))
						swap_b(frame);
				}
				else if (frame->b->next->next->element == min(frame->b, range))
				{
					if (frame->b->next->element == max(frame->b, range))
						swap_b(frame);
				}
			}
            push_a(frame);
            push_a(frame);
            push_a(frame);
		}
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
	
	frame->big_pivot = select_pivot(frame->b, range);
	frame->small_pivot = select_pivot(frame->b, range / 2);

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
    // printf("range (pa_cnt - ra_cnt): %d\n", pa_cnt - ra_cnt);
	a_to_b(frame, pa_cnt - ra_cnt);
	while (i < ra_cnt || i < rb_cnt)
	{
		if (i >= rb_cnt)
			reverse_rotate_a(frame);
		else if (i >= ra_cnt)
			reverse_rotate_b(frame);
		else
			reverse_rotate_r(frame);
		i++;
	}
	a_to_b(frame, ra_cnt);
	b_to_a(frame, rb_cnt);
}