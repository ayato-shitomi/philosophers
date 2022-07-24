/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:04:13 by ashitomi          #+#    #+#             */
/*   Updated: 2022/06/18 19:04:13 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

/*
	Do init
	lanch
*/

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		ret;

	if (!(argc == 5 || argc == 6))
		return (err_hub(1));
	ret = init_all(&rules, argv);
	if (ret != 0)
		return (err_hub(ret));
	if (launcher(&rules))
		return (err_hub(11));
	return (0);
}
