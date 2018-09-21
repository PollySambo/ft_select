/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:07:30 by psambo            #+#    #+#             */
/*   Updated: 2018/09/21 10:08:09 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	t_select	select;

	if (argc > 1)
	{
		if (ft_change_term_behavior(&(select.term)) == -1)
			return (-1);
		ft_handle_signals();
		ft_clear_terminal();
		ft_add_list(&select, argc - 1, &argv[1]);
		ft_save_and_load(&select, 0);
		ft_print_list(&select);
		ft_keyhook();
		ft_free_mem(&select);
		ft_reset_term_behavior(&(select.term));
	}
	return (0);
}
