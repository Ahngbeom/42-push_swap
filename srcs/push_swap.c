/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:08:05 by bahn              #+#    #+#             */
/*   Updated: 2021/08/16 15:29:02 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_frame *frame;

	invalid_arg(argc, argv);
	frame = frame_init();
	stack_init(frame, argv);
	
	// if (check_asc(frame->a) == TRUE && frame->b == NULL)
	// 	return (0);
	// else
	// {
		print_stack(frame);
		// fix_element(frame);
		a_to_b(frame, length(frame->a));
		// ascending(frame);
		// reverse_rotate_a(frame);
	// }
	print_command(frame->cmd_list);
	frame_free(frame);
	return (0);
}
