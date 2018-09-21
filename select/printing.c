/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:11:32 by psambo            #+#    #+#             */
/*   Updated: 2018/09/21 09:51:22 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_put_char(int c)
{
	return (write(FILE_DS, &c, 1));
}

int		ft_put_char_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_put_char((int)str[i]);
		i++;
	}
}

void	ft_put_str_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_put_char_fd(str[i], fd);
		i++;
	}
}

void	ft_put_endl(char *str)
{
	ft_put_str(str);
	ft_put_char((int)'\n');
}
