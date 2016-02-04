/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 00:29:53 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 13:17:44 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lsttostr() transforms a linked list to a string and
** free the linked list.
*/

#include "../libft.h"

char	*ft_lsttostr(t_list **list)
{
	t_list		*tmp;
	char		*str;

	str = ft_strnew((ft_lstcontentsize(*list)) + 1);
	tmp = *list;
	while (tmp)
	{
		str = ft_strncat(str, tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	ft_lstclr(list);
	return (str);
}
