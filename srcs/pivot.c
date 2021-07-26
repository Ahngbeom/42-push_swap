/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/07/23 13:56:55 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     less_than_to_pivot(t_frame *frame)
{
    while (check_asc(frame->a) != 0 && length(frame->a) > 3 && min(frame->a) < frame->pivot_a)
    {
        if (frame->a->element < frame->pivot_a)
        {
            push_b(frame);
            if (rotate_check(frame, frame->b))
                rotate_b(frame);
            if (swap_check(frame, frame->b))
                swap_b(frame);
        }
        else if (frame->a->element > frame->pivot_a)
            rotate_a(frame);
        else if (last_element(frame->a)->element < frame->pivot_a)
            reverse_rotate_a(frame);
        else if (frame->a->element > frame->a->next->element)
            swap_a(frame);
        else
            rotate_a(frame);
        print_stack(frame);
    }
}

// void    greater_than_or_eq_to_pivot(t_frame *frame)
// {
//     frame->pivot_b = median(frame->a, length(frame->a) / 1.5);
//     while (max(frame->a) >= frame->pivot_a)
//     {
//         if (frame->a->element >= frame->pivot_a)
//         {
//             push(frame, 'B');
//             if (length(frame->b) >= 2 && frame->b->element > frame->pivot_b)
//             {
//                 rotate(frame, 'B');
//             }
//         }
//         else
//             rotate(frame, 'A');
//         print_stack(frame);
//     }
// }

// void    pop_in_the_b(t_frame *frame)
// {
//     while (frame->b != NULL)
//     {
//         if (frame->b->element == min(frame->b))
//         {
//             push(frame, 'A');
//             if (length(frame->b) > 1 && frame->b->element == max(frame->b))
//                 rotate(frame, 'R');
//             else
//                 rotate(frame, 'A');
//         }
//         else if (frame->b->next->element == min(frame->b))
//         {
//             if (frame->a->element > frame->a->next->element)
//                 swap(frame, 'S');
//             else
//                 swap(frame, 'B');
//         }
//         else if (last_element(frame->b)->element == min(frame->b))
//         {
//             reverse_rotate(frame, 'B');
//         }
//         else
//             rotate(frame, 'B');
//         print_stack(frame);
//     }
// }