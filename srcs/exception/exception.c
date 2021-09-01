/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:55:42 by bahn              #+#    #+#             */
/*   Updated: 2021/09/01 13:24:08 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_nbrlen(int num)
{
	int	i;
	int	n;

	i = 1;
	n = num;
	if (num >= 0)
	{
		while ((n / 10) > 0)
		{
			i++;
			n = n / 10;
		}
	}
	else
	{
		++i;
		while ((n / 10) * -1 > 0)
		{
			i++;
			n = n / 10;
		}
	}
	return (i);
}

static	void	isInteger(char **arr)
{
	int	i;
	int	j;

	i = 1;
	while (arr[i] != NULL)
	{
		if (ft_strlen(arr[i]) != ft_nbrlen(ft_atoi(arr[i])))
			ft_puterr();
		j = 0;
		while (arr[i][j] != '\0')
		{
			if ((arr[i][j] != '-' && arr[i][j] != '+') && \
					ft_isdigit(arr[i][j]) == 0)
				ft_puterr();
			j++;
		}
		i++;
	}
}

static	void	duplicate_checker(char **arr)
{
	int	i;
	int	j;

	i = 1;
	while (arr[i] != NULL)
	{
		j = i + 1;
		while (arr[j] != NULL)
		{
			if (ft_strncmp(arr[i], arr[j], ft_strlen(arr[i])) == 0)
			{
				if (ft_strlen(arr[i]) == ft_strlen(arr[j]))
					ft_puterr();
			}
			j++;
		}
		i++;
	}
}

void	ft_puterr(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
}

void	invalid_arg(int argc, char *argv[])
{
	if (argc < 2)
		exit(1);
	isInteger(argv);
	duplicate_checker(argv);
}
