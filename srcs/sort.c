/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:59:01 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 17:43:48 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ascending(t_frame *frame)
{
    if (length(frame->a) == 2)
        swap_a(frame);
    else if (length(frame->a) == 3)
        case_3(frame);
    else if (length(frame->a) <= 5)
        case_5(frame);
    else
    {
	    frame->pivot_b = median(frame->a, length(frame->a) / 2);
        case_other(frame);
    }
}

