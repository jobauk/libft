/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 14:14:14 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/11 21:37:43 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// #include <stdio.h>

// int main() {
// 	printf("%d", ft_isalpha('a'));
// 	printf("%d", ft_isalpha('D'));
// 	printf("%d", ft_isalpha('0'));
// 	printf("%d", ft_isalpha('.'));
// }
