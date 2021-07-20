/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:08:05 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 20:33:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_frame *frame;

	invalid_arg(argc, argv);
	frame = frame_init();
	stack_init(frame, argv);
	
	if (check_asc(frame->a) == 0 && frame->b == NULL)
		return (0);
	else
	{
		print_stack(frame);
		ascending(frame);
	}
	print_command(frame->cmd_list);
	frame_free(frame);
	return (0);
}
