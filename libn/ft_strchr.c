/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:42:06 by ibenhaim          #+#    #+#             */
/*   Updated: 2022/11/25 16:29:17 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t				i;
	unsigned char		cc;

	i = 0;
	cc = (unsigned char)c;
	while (s[i] && s[i] != cc)
		i++;
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (0);
}
