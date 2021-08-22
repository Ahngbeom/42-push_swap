/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:49:27 by bahn              #+#    #+#             */
/*   Updated: 2021/08/22 19:28:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  int    sorting(t_frame *frame, int range)
{
    if (range <= 3)
	{
		if (range == 2)
		{
			if (frame->a->element > frame->a->next->element)
				swap_a(frame);
		}
        else if (range == 3)
        {
            if (length(frame->a) == 3)
            {
                while (check_asc(frame->a) == FALSE)
                {
                    if (frame->a->element == max(frame->a, range))
                        rotate_a(frame);
                    else if (frame->a->next->element == max(frame->a, range))
                        reverse_rotate_a(frame);
                    else
                        swap_a(frame);
                }
            }
            else
            {
               	if (frame->a->element == max(frame->a, range))
				{
					swap_a(frame);
					rotate_a(frame);
					swap_a(frame);
					reverse_rotate_a(frame);
					if (frame->a->element > frame->a->next->element)
						swap_a(frame);
				}
				else if (frame->a->next->element == max(frame->a, range))
				{
					rotate_a(frame);
					swap_a(frame);
					reverse_rotate_a(frame);
					if (frame->a->element > frame->a->next->element)
						swap_a(frame);
				}
				else if (frame->a->next->next->element == max(frame->a, range))
				{
					if (frame->a->element > frame->a->next->element)
						swap_a(frame);
				}
            }
        }
        return (TRUE);
	}
    else 
        return (FALSE);
}

void	a_to_b(t_frame *frame, int range, void (*call_out_func))
{
	int	i;
	int ra_cnt = 0;
	int rb_cnt = 0;
	int pb_cnt = 0;

	if (sorting(frame, range) == TRUE)
		return ;
	
	frame->big_pivot = select_big_pivot(frame->a, range);
	frame->small_pivot = select_small_pivot(frame->a, range);

	while (range--)
	{
		if (frame->a->element > frame->big_pivot)
			ra_cnt += rotate_a(frame);
		else
		{
			pb_cnt += push_b(frame);
			if (frame->b->element > frame->small_pivot)
				rb_cnt += rotate_b(frame);
		}
	}

	i = 0;
	if (call_out_func == NULL)
	{
		while (i++ < rb_cnt)
			reverse_rotate_b(frame);
	}
	else
	{
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
	}
	
	a_to_b(frame, ra_cnt, call_out_func);
	b_to_a(frame, rb_cnt);
	b_to_a(frame, pb_cnt - rb_cnt);
}