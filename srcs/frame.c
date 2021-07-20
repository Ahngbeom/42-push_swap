/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:54:42 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 20:34:11 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame    *frame_init()
{
    t_frame *frame;
    if (!(frame = (t_frame *)malloc(sizeof(t_frame))))
        exit(1);
    frame->a = NULL;
    frame->b = NULL;
    frame->cmd_list = NULL;
    return (frame);
}

void        frame_free(t_frame *frame)
{
    // t_stack *temp;
    void    *temp;
    
    while (frame->a != NULL)
    {
        temp = frame->a->next;
        free(frame->a);
        frame->a = temp;
    }
    while (frame->b != NULL)
    {
        temp = frame->b->next;
        free(frame->b);
        frame->b = temp;
    }
    while (frame->cmd_list != NULL)
    {
        temp = frame->cmd_list->next;
        free(frame->b);
        frame->cmd_list = temp;
    }
    free(frame);
}