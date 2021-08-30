/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:08:05 by bahn              #+#    #+#             */
/*   Updated: 2021/08/31 00:36:17 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_frame	*frame;

	invalid_arg(argc, argv);
	frame_init(&frame);
	stack_init(frame, argv);
	if (check_asc(frame->a) == FALSE)
		a_to_b(frame, length(frame->a), NULL);
	if (frame->cmd != NULL)
		ft_putendl_fd(frame->cmd, 1);
	frame_free(frame);
	return (0);
}
