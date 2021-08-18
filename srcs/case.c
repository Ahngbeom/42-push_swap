/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:02:38 by bahn              #+#    #+#             */
/*   Updated: 2021/08/18 12:54:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_frame *frame, t_stack *stack)
{
	if (frame->a == stack)
	{
		while (check_asc(frame->a) == FALSE)
		{
			if (frame->a->element == max(frame->a, length(frame->a)))
				rotate_a(frame);
			else if (last_element(frame->a)->element == min(frame->a, length(frame->a)))
				reverse_rotate_a(frame);
			else
				swap_a(frame);
		}
	}
	
	if (frame->b == stack)
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
		push_a(frame);
		push_a(frame);
		push_a(frame);
	}
}

void	case_5(t_frame *frame)
{
	frame->big_pivot = median(frame->a, length(frame->a));
	printf("check\n");
	if (check_asc(frame->a) == FALSE)
	{
		while (min(frame->a, length(frame->a)) != frame->big_pivot)
		{
			if (frame->a->element < frame->big_pivot)
				push_b(frame);
			else if (last_element(frame->a)->element < frame->big_pivot)
				reverse_rotate_a(frame);
			else 
				rotate_a(frame);
		}
		case_3(frame, frame->a);
		while (frame->b != NULL)
		{
			if (check_desc(frame->b) == FALSE)
				swap_b(frame);
			else
				push_a(frame);
		}
		if (swap_check(frame, frame->a))
			swap_a(frame);
	}
}

void	after_div_restore(t_frame *frame, int ra, int rb)
{
	// 초기에 인자로 들어온 스택에서 이미 정렬되어져있는 부분을 고정하기위함
	int 	ra_cnt;
	int		rb_cnt;

	ra_cnt = ra;
	rb_cnt = rb;
	while (ra_cnt > 0 || rb_cnt > 0)
	{
		if (ra_cnt > 0 && rb_cnt <= 0)
			reverse_rotate_a(frame);
		else if (ra_cnt <= 0 && rb_cnt > 0)
			reverse_rotate_b(frame);
		else
			reverse_rotate_r(frame);
		ra_cnt--;
		rb_cnt--;
	}
}