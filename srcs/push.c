/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:25:48 by bahn              #+#    #+#             */
/*   Updated: 2021/08/20 20:59:53 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     push_a(t_frame *frame)
{
    t_stack     *temp;
    
    if ((temp = (frame->b)->next) != NULL)
        temp->prev = NULL;
    if (frame->a != NULL)
        (frame->a)->prev = frame->b;
    (frame->b)->next = frame->a;
    frame->a = frame->b;
    frame->b = temp;
    add_command(frame, "pa");
    return (1);
}

int     push_b(t_frame *frame)
{
    t_stack     *temp;

    if ((temp = (frame->a)->next) != NULL)
        temp->prev = NULL;
    if (frame->b != NULL)
        (frame->b)->prev = frame->a;
    (frame->a)->next = frame->b;
    frame->b = frame->a;
    frame->a = temp;
    add_command(frame, "pb");
    return (1);
}

