/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:12:46 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 20:34:23 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  t_command   *create_command(char *cmd)
{
    t_command   *new;

    if (!(new = (t_command*)malloc(sizeof(t_command))))
        return (NULL);
    new->cmd = ft_strdup(cmd);
    new->prev = NULL;
    new->next = NULL;
    return (new);
}

void    add_command(t_frame *frame, char *cmd)
{
    t_command   *ptr;
    
    if (frame->cmd_list != NULL)
    {
        ptr = frame->cmd_list;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = create_command(cmd);
        ptr->next->prev = ptr;
    }
    else
        frame->cmd_list = create_command(cmd);
}