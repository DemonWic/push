/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:39:23 by ahintz            #+#    #+#             */
/*   Updated: 2018/12/01 16:25:33 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	int num;
	int i;

	num = (int)'0';
	i = 0;
	while (i++ <= 9)
		if (c == num++)
			return (1);
	return (0);
}
