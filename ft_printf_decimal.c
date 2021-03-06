/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:09:51 by ibalbako          #+#    #+#             */
/*   Updated: 2022/04/04 11:09:52 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen(long int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	size_t		i;
	long int	nb;

	nb = (long int)n;
	len = ft_intlen(nb);
	str = (char *)(malloc(sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	if (nb < 0)
	{
		str[i++] = '-';
		nb = -nb;
	}
	while (i < len)
	{
		str[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

int	ft_print_decimal(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_str(num);
	free(num);
	return (len);
}
