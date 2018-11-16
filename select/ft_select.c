/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:07:30 by psambo            #+#    #+#             */
/*   Updated: 2018/09/22 15:38:48 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	t_pick	pick;

	if (argc > 1)
	{
		if (change_iterm(&(pick.term)) == -1)
			return (-1);
		signals_handle();
		clear_iterm();
		ft_add_list(&pick, argc - 1, &argv[1]);
		ft_save_and_load(&pick, 0);
		ft_print_list(&pick);
		keyboard();
		free_memory(&pick);
		reset_iterm(&(pick.term));
	}
	return (0);
}
