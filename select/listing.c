/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:11:54 by psambo            #+#    #+#             */
/*   Updated: 2018/09/22 15:42:49 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		free_memory(t_pick *pick)
{
	int	i;

	i = 0;
	while ((pick->items)[i] != '\0')
	{
		free((pick->items)[i]);
		i++;
	}
	free(pick->items);
	free(pick->selected);
}

int			ft_get_longest_item(t_pick *pick)
{
	int		j;
	int		length;
	int		i;

	j = 0;
	if (pick->n_items <= 0)
		return (0);
	length = ft_strlen((pick->items)[0]);
	while ((pick->items)[j] != '\0')
	{
		i = strlen((pick->items)[j]);
		if (length <= i)
			length = i;
		j++;
	}
	return (length);
}

static int	ft_check_winsize(t_pick *pick)
{
	int		i;

	i = ft_get_longest_item(pick);
	if (pick->win.ws_row <= pick->n_items || pick->win.ws_col <= i)
	{
		if (pick->win.ws_row <= pick->n_items)
			ft_putendl("* Window height is too small.");
		if (pick->win.ws_col <= i)
			ft_putendl("* Window width is too small.");
		return (-1);
	}
	return (1);
}

void		ft_print_list(t_pick *pick)
{
	int	i;

	i = 0;
	clear_iterm();
	if (ft_check_winsize(pick) == -1)
		return ;
	while ((pick->items)[i] != '\0')
	{
		if (pick->pos == i)
				underline((pick->items)[i], yellow);
		else
		{
			if (pick->selected[i] == 1)
				highlight((pick->items)[i], yellow);
			else
				ft_putendl((pick->items)[i]);
		}
		i++;
	}
}

void		ft_add_list(t_pick *pick, int n, char **list)
{
	int	i;

	i = 0;
	pick->items = (char**)malloc(sizeof(char*) * (n + 1));
	pick->selected = (int*)malloc(sizeof(int) * (n + 1));
	if (pick->items == NULL || pick->selected == NULL)
		return ;
	(pick->items)[n] = (char*)'\0';
	(pick->selected)[n] = (int)'\0';
	pick->n_items = n;
	pick->pos = 0;
	while (i < n)
	{
		(pick->items)[i] = ft_strdup(list[i]);
		i++;
	}
	ioctl(FILE_DS, TIOCGWINSZ, &(pick->win));
}
