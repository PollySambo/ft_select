/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:10:20 by psambo            #+#    #+#             */
/*   Updated: 2018/09/22 15:22:49 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				wind_change(void)
{
	t_pick	*tmp;

	tmp = ft_save_and_load(NULL, 1);
	ioctl(FILE_DS, TIOCGWINSZ, &(tmp->win));
	ft_save_and_load(tmp, 0);
	ft_print_list(tmp);
}

static void			handle(int num)
{
	t_pick	*pick;
	char		ch[2];

	if (num == SIGINT)
		exiting();
	else if (num == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		pick = ft_save_and_load(NULL, 1);
		reset_iterm(&(pick->term));
		ch[0] = pick->term.c_cc[VSUSP];
		ch[1] = '\0';
		ioctl(0, TIOCSTI, ch);
	}
	else if (num == SIGCONT)
	{
		signal(SIGTSTP, handle);
		pick = ft_save_and_load(NULL, 1);
		change_iterm(&(pick->term));
		ft_print_list(pick);
	}
	else if (num == SIGWINCH)
		wind_change();
	else
		exiting();
}

void				signals_handle(void)
{
	int	i;

	i = 1;
	while (i <= 31)
	{
		signal(i, handle);
		i++;
	}
}
