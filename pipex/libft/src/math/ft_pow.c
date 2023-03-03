/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:29:32 by soohong           #+#    #+#             */
/*   Updated: 2023/02/20 16:30:19 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int n, unsigned int power)
{
	if (power == 0)
		return (1);
	else if (power == 1)
		return (n);
	else
		return (n * ft_pow(n, power - 1));
}
