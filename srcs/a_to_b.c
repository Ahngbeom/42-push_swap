/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:49:27 by bahn              #+#    #+#             */
/*   Updated: 2021/08/20 18:32:47 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  int    sorting(t_frame *frame, int range)
{
	// printf("range : %d\n", range);
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
				// printf("max of range : %d\n", max(frame->a, range));
               	if (frame->a->element == max(frame->a, range))
				{
					// printf("max : index 0\n");
					swap_a(frame);
					rotate_a(frame);
					swap_a(frame);
					reverse_rotate_a(frame);
					if (frame->a->element > frame->a->next->element)
						swap_a(frame);
				}
				else if (frame->a->next->element == max(frame->a, range))
				{
					// printf("max : index 1\n");
					rotate_a(frame);
					swap_a(frame);
					reverse_rotate_a(frame);
					if (frame->a->element > frame->a->next->element)
						swap_a(frame);
				}
				else if (frame->a->next->next->element == max(frame->a, range))
				{
					// printf("max : index 2\n");
					if (frame->a->element > frame->a->next->element)
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
		// printf("call out function is NULL !\n");
		while (i++ < rb_cnt)
			reverse_rotate_b(frame);
	}
	else
	{
		// printf("call out function is NOT NULL !\n");
		while (i < ra_cnt || i < rb_cnt)
		{
			// printf("check ra : %d, rb : %d\n", ra_cnt, rb_cnt);
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
    // printf("range (pb_cnt - rb_cnt): %d\n", pb_cnt - rb_cnt);
	b_to_a(frame, pb_cnt - rb_cnt);
}