/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:55:42 by bahn              #+#    #+#             */
/*   Updated: 2021/07/22 16:02:21 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     isInteger(char *str)
{
    int     i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
    ++i;
    while (str[i] != '\0')
    {
            if (!ft_isdigit(str[i]))
                    return (1);
            i++;
    }
    return (0);
}

int     invalid_arg(int argc, char *argv[])
{
        int     i;
	int	j;

        if (argc < 2)
        {
                printf("ERROR:::인자가 존재하지 않습니다.\n");
                exit(1);
        }
        i = 1;
        while (argv[i] != NULL)
        {
                if (isInteger(argv[i]))
                {
                        printf("ERROR:::인자가 올바르지 않습니다.\n");
                        exit(1);
                }
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strcmp(argv[i], argv[j]))
			{
                printf("ERROR:::중복되는 인자가 존재합니다.\n");
				exit(1);
			}
			j++;
		}
		i++;
        }
        return (i - 1);
}

int     check_asc(t_stack *stack)
{
    t_stack     *i;
    t_stack     *j;
    
    i = stack;
    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (i->element > j->element)
                return (FALSE);
            j = j->next;
        }
        i = i->next;
    }
    return (TRUE);
}

int     check_desc(t_stack *stack)
{
    t_stack     *i;
    t_stack     *j;
    
    i = stack;
    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (i->element < j->element)
                return (1);
            j = j->next;
        }
        i = i->next;
    }
    return (0);
}