/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 06:25:03 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/31 23:12:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_game.h"

int		ft_numbers_right(int g_s, int *grid, int r, int k)
{
	int		i;
	int		y;

	while (k--)
		r = ft_mv_right(g_s, grid, r);
	i = g_s * g_s;
	while (i >= 0)
	{
		y = i - 1;
		if (y % g_s != g_s - 1 && grid[i] == grid[y] && grid[i] != 0)
		{
			grid[i] += grid[y];
			grid[y] = 0;
			r = 1;
		}
		i--;
	}
	r = ft_mv_right(g_s, grid, r);
	return (r);
}
