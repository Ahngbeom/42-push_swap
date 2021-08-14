/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:59:01 by bahn              #+#    #+#             */
/*   Updated: 2021/08/14 17:03:03 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ascending(t_frame *frame)
{
    if (length(frame->a) == 2)
        swap_a(frame);
    else if (length(frame->a) == 3)
        case_3(frame, frame->a);
    else if (length(frame->a) <= 5)
        case_5(frame);
    else
    {
        // div_by_pivot_to_b(frame, length(frame->a));
        // div_by_pivot_to_a(frame);
        a_to_b(frame, length(frame->a));
    }
}

void    descending(t_frame *frame)
{
    if (length(frame->a) == 2)
        swap_b(frame);
    else if (length(frame->a) == 3)
        case_3(frame, frame->a);
    else
    {
        // div_by_pivot_to_a(frame);
        div_by_pivot_to_b(frame, length(frame->a));
    }
}

