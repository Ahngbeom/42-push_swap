/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:54:42 by bahn              #+#    #+#             */
/*   Updated: 2021/08/31 00:35:36 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame	*frame_init(t_frame **frame)
{
	*frame = (t_frame *)malloc(sizeof(t_frame));
	if (*frame == NULL)
		ft_puterr();
	(*frame)->a = NULL;
	(*frame)->b = NULL;
	(*frame)->cmd = NULL;
	return (*frame);
}

void	frame_free(t_frame *frame)
{
	void	*temp;

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
	if (frame->cmd != NULL)
		free(frame->cmd);
	free(frame);
}
