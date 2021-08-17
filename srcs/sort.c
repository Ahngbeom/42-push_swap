/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:59:01 by bahn              #+#    #+#             */
/*   Updated: 2021/08/17 17:19:10 by bahn             ###   ########.fr       */
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
        a_to_b(frame, length(frame->a));
    }
}

