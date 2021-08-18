/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:08:05 by bahn              #+#    #+#             */
/*   Updated: 2021/08/18 03:10:48 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_frame *frame;

	
	invalid_arg(argc, argv);
	frame = frame_init();
	stack_init(frame, argv);
	
	print_stack(frame);
	if (check_asc(frame->a) == TRUE && frame->b == NULL)
		return (0);
	a_to_b(frame, length(frame->a));
	print_command(frame->cmd_list);
	frame_free(frame);
	return (0);
}
