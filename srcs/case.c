/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:02:38 by bahn              #+#    #+#             */
/*   Updated: 2021/08/14 21:35:27 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_frame *frame, t_stack *stack)
{
	if (frame->a == stack)
	{
		while (check_asc(frame->a) == FALSE)
		{
			if (frame->a->element == max(frame->a))
				rotate_a(frame);
			else if (last_element(frame->a)->element == min(frame->a))
				reverse_rotate_a(frame);
			else
				swap_a(frame);
		}
	}
	
	if (frame->b == stack)
	{
		while (check_desc(frame->b) == FALSE)
		{
			if (frame->b->element == min(frame->b))
				rotate_b(frame);
			else if (last_element(frame->b)->element == max(frame->b))
				reverse_rotate_b(frame);
			else
				swap_b(frame);
		}
	}
}

void	case_5(t_frame *frame)
{
	frame->pivot_a = median(frame->a, length(frame->a));
	if (check_asc(frame->a) == FALSE)
	{
		while (length(frame->a) != 3 && min(frame->a) != frame->pivot_a)
		{
			if (frame->a->element < frame->pivot_a)
				push_b(frame);
			else if (last_element(frame->a)->element < frame->pivot_a)
				reverse_rotate_a(frame);
			else 
				rotate_a(frame);
		}
		case_3(frame, frame->a);
		while (length(frame->a) != 5)
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

void	div_by_pivot_to_b(t_frame *frame, int count)
{	
	int	i;
	int	ra_cnt;
	int	rb_cnt;
	int pb_cnt;
	
	printf("A to B (count : %d)\n", count);
	if (count < 3)
	{
		if (swap_check(frame, frame->a) == TRUE)
			swap_a(frame);
		printf("END\n");
		return ;
	}
	frame->pivot_a = median(frame->a, length(frame->a));
	frame->pivot_b = median(frame->a, length(frame->a) / 2);
	i = 0;
	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	while (i++ < count)
	{
		if (frame->pivot_a <= frame->a->element)
			ra_cnt += rotate_a(frame);
		else
		{
			pb_cnt += push_b(frame);
			// if (length(frame->b) > 2 && frame->pivot_b <= frame->b->element)
			if (length(frame->b) >= 2 && frame->pivot_b <= frame->b->element)
				rb_cnt += rotate_b(frame);
		}
	}
	printf("END\n");
	
	after_div_restore(frame, ra_cnt, rb_cnt);

	printf("div_by_pivot_to_b(frame, ra_cnt : %d);\n", ra_cnt);
	div_by_pivot_to_b(frame, ra_cnt);
	
	printf("div_by_pivot_to_a(frame, rb_cnt : %d);\n", rb_cnt);
	div_by_pivot_to_a(frame, rb_cnt);
	
	printf("div_by_pivot_to_a(frame, pb_cnt - rb_cnt : %d - %d);\n", \
				pb_cnt, rb_cnt);
	div_by_pivot_to_a(frame, pb_cnt - rb_cnt);
}

void	div_by_pivot_to_a(t_frame *frame, int count)
{
	int	i;
	int	rb_cnt;
	int	ra_cnt;
	int pa_cnt;
	
	printf("B to A (count : %d)\n", count);
	if (count < 3)
	{
		if (swap_check(frame, frame->b) == TRUE)
			swap_b(frame);
		push_a(frame);
		return ;
	}
	frame->pivot_b = median(frame->b, length(frame->b));
	frame->pivot_a = median(frame->b, length(frame->b) / 2);
	i = 0;
	rb_cnt = 0;
	ra_cnt = 0;
	pa_cnt = 0;
	while (i++ < count)
	{
		if (frame->pivot_b > frame->b->element)
			rb_cnt += rotate_b(frame);
		else
		{
			pa_cnt += push_a(frame);
			if (length(frame->a) > 2 && frame->pivot_a > frame->a->element)
				ra_cnt += rotate_a(frame);
		}
	}
	printf("END\n");

	printf("div_by_pivot_to_b(frame, pa_cnt - ra_cnt : %d - %d);\n", \
					pa_cnt, ra_cnt);
	div_by_pivot_to_b(frame, pa_cnt - ra_cnt);
	
	after_div_restore(frame, ra_cnt, rb_cnt);
	
	printf("div_by_pivot_to_b(frame, ra_cnt : %d);\n", ra_cnt);
	div_by_pivot_to_b(frame, ra_cnt);
	
	printf("div_by_pivot_to_a(frame, rb_cnt : %d);\n", rb_cnt);
	div_by_pivot_to_a(frame, rb_cnt);

}

// void	fix_range(t_frame *frame)
// {
	
// }

void	a_to_b(t_frame *frame, int count)
{
	int	i	= 0;
	int	ra_cnt = 0;
	int	rb_cnt = 0;
	int	pb_cnt = 0;
	
	printf("a to b\n");
	if (count < 3)
	{
		if (frame->a->element > frame->a->next->element)
			swap_a(frame);
		return ;
	}
	frame->pivot_a = select_pivot(frame->a, count);
	frame->pivot_b = select_pivot(frame->a, count / 2);

	while (count--)
	{
		if (frame->a->element >= frame->pivot_a)
			ra_cnt += rotate_a(frame);
		else
		{
			pb_cnt += push_b(frame);
			if (length(frame->b) >= 2 && frame->b->element >= frame->pivot_b)
				rb_cnt += rotate_b(frame);
		}
	}

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
	while (last_element(frame->b)->element >= frame->pivot_b)
		reverse_rotate_b(frame);

	printf("\t ra : %d, rb : %d, pb : %d\n", ra_cnt, rb_cnt, pb_cnt);
	a_to_b(frame, ra_cnt);
	b_to_a(frame, rb_cnt);
	b_to_a(frame, pb_cnt - rb_cnt);
}

void	b_to_a(t_frame *frame, int count)
{
    int	i	= 0;
	int	ra_cnt = 0;
	int	rb_cnt = 0;
	int	pa_cnt = 0;

	printf("b to a\n");
	if (count < 3)
	{
		if (length(frame->b) >= 2 && frame->b->element < frame->b->next->element)
			swap_b(frame);
		push_a(frame);
		return ;
	}
	frame->pivot_b = select_pivot(frame->b, count);
	frame->pivot_a = select_pivot(frame->b, count / 2);

	while (count--)
	{
		if (frame->b->element < frame->pivot_b)
			rb_cnt += rotate_b(frame);
		else
		{
			pa_cnt += push_a(frame);
			if (length(frame->a) >= 2 && frame->b->element < frame->pivot_a)
				ra_cnt += rotate_a(frame);
		}
	}
	printf("\t ra : %d, rb : %d, pa : %d\n", ra_cnt, rb_cnt, pa_cnt);
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