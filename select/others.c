/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:12:11 by psambo            #+#    #+#             */
/*   Updated: 2018/09/21 10:14:12 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_clr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}

int			ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = ft_strlen(str);
	dest = (char*)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	dest[i] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}

t_select	*ft_save_and_load(t_select *select, int mode)
{
	static t_select	*tmp = NULL;

	if (mode == 0)
		tmp = select;
	return (tmp);
}
