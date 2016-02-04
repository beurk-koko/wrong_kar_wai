/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:19:12 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/27 15:52:55 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_itoa_base() function converts the initial int representation by a
** string pointed to by n, according to the base.
*/

#include "../libft.h"

static void			ft_convert_base(int n, int base, char *s, int *index)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (n < base)
	{
		s[*index] = str[n];
		*index += 1;
	}
	else
	{
		ft_convert_base(n / base, base, s, index);
		ft_convert_base(n % base, base, s, index);
	}
}

static int			ft_nbrlen_base(int n, int base)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char				*ft_itoa_base(int n, int base)
{
	char	*s;
	int		len;
	int		sign;

	if (n == -2147483648)
		return ("-2147483648");
	len = ft_nbrlen_base(n, base);
	sign = n < 0 ? 1 : 0;
	n = sign == 1 ? -n : n;
	s = ft_strnew(len + 1);
	sign ? s[0] = '-' : 0;
	ft_convert_base(n, base, s, &sign);
	return (s);
}
