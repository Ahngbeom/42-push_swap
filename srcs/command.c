/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:12:46 by bahn              #+#    #+#             */
/*   Updated: 2021/08/22 21:17:21 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    add_command(t_frame *frame, char *cmd)
{
    char        *tmp;
    char        *cmd_lf;

    if (frame->cmd_list != NULL)
    {
        tmp = frame->cmd_list;
        cmd_lf = ft_strjoin("\n", cmd);
        frame->cmd_list = ft_strjoin(frame->cmd_list, cmd_lf);
        free(tmp);
        free(cmd_lf);
    }
    else
        frame->cmd_list = ft_strdup(cmd);
}