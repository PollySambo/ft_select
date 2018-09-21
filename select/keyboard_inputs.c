/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:10:07 by psambo            #+#    #+#             */
/*   Updated: 2018/09/21 10:23:45 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_go_up(t_select *select)
{
	int		current;
	int		max;
	int		min;

	current = select->pos;
	max = select->n_items;
	min = 0;
	if (current == min)
		select->pos = max - 1;
	else
		select->pos = select->pos - 1;
	ft_save_and_load(select, 0);
	ft_print_list(select);
}

void		ft_enter(t_select *select)
{
	int	i;

	i = 0;
	ft_reset_term_behavior(&(select->term));
	while (select->n_items > i)
	{
		if ((select->selected)[i] == 1)
		{
			ft_put_str_fd((select->items)[i], 1);
			ft_put_char_fd(' ', 1);
		}
		i++;
	}
	ft_put_char_fd('\n', 1);
	exit(0);
}

void		ft_go_down(t_select *select)
{
	int		current;
	int		max;
	int		min;

	current = select->pos;
	max = select->n_items;
	min = 0;
	if (current == (max - 1))
		select->pos = min;
	else
		select->pos = select->pos + 1;
	ft_save_and_load(select, 0);
	ft_print_list(select);
}

void		ft_select_item(t_select *select)
{
	int		pos;

	pos = select->pos;
	if (select->selected[pos] == 1)
		select->selected[pos] = -1;
	else
		select->selected[pos] = 1;
	if (select->pos == select->n_items - 1)
		select->pos = 0;
	else
		select->pos += 1;
	ft_save_and_load(select, 0);
	ft_print_list(select);
}

void		ft_keyhook(void)
{
	char	key[5];

	key[4] = '\0';
	while (1)
	{
		ft_clr(key);
		read(0, key, 4);
		if (key[0] == 27 && key[1] == '\0' && key[2] == '\0')
			return ;
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'A')
			ft_go_up(ft_save_and_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'B')
			ft_go_down(ft_save_and_load(NULL, 1));
		else if (key[0] == 32 && key[1] == '\0' && key[2] == '\0')
			ft_select_item(ft_save_and_load(NULL, 1));
		else if (key[0] == 10 && key[1] == '\0' && key[2] == '\0')
			ft_enter(ft_save_and_load(NULL, 1));
		/*else if (key[0] == 127 && key[1] == '\0' && key[2] == '\0')
			ft_remove_item(ft_save_and_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 51)
			ft_remove_item(ft_save_and_load(NULL, 1));*/
	}
}
