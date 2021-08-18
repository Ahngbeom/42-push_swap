/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:49:27 by bahn              #+#    #+#             */
/*   Updated: 2021/08/18 19:21:36 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  int    sorting(t_frame *frame, int range)
{
    if (range <= 3)
	{
		// if (range == 1)
		// 	return (TRUE);
		// else if (range == 2)
		if (range == 2)
		{
			if (frame->a->element > frame->a->next->element)
				swap_a(frame);
			// return (TRUE);
		}
        // else 
        else if (range == 3)
        {
            if (length(frame->b) == 3)
            {
                if (check_asc(frame->a) == FALSE)
                {
                    if (frame->a->element == max(frame->a, length(frame->a)))
                        rotate_a(frame);
                    else if (last_element(frame->a)->element == min(frame->a, length(frame->a)))
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
					if (frame->a->next->element == min(frame->a, range))
						swap_b(frame);
				}
				else if (frame->a->next->element == max(frame->a, range))
				{
					rotate_a(frame);
					swap_a(frame);
					reverse_rotate_a(frame);
					if (frame->a->next->element == min(frame->a, range))
						swap_a(frame);
				}
				else if (frame->a->next->next->element == max(frame->a, range))
				{
					if (frame->a->next->element == min(frame->a, range))
						swap_a(frame);
				}
            }
			// return (TRUE);
        }
        return (TRUE);
	}
    else 
        return (FALSE);
}

void	a_to_b(t_frame *frame, int range)
{
	int	i;
	int ra_cnt = 0;
	int rb_cnt = 0;
	int pb_cnt = 0;

	if (sorting(frame, range) == TRUE)
		return ;
	
	frame->big_pivot = select_pivot(frame->a, range);
	frame->small_pivot = select_pivot(frame->a, range / 2);

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
	// while (i < ra_cnt || i < rb_cnt)
	while (i < rb_cnt)
	{
		// if (i < ra_cnt && i >= rb_cnt)
		// 	reverse_rotate_a(frame);
		// else if (i >= ra_cnt && i < rb_cnt)
			reverse_rotate_b(frame);
		// else
		// 	reverse_rotate_r(frame);
		i++;
	}
	
	a_to_b(frame, ra_cnt);
	b_to_a(frame, rb_cnt);
    // printf("range (pb_cnt - rb_cnt): %d\n", pb_cnt - rb_cnt);
	b_to_a(frame, pb_cnt - rb_cnt);
}