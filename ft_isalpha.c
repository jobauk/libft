/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 14:14:14 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/28 16:16:25 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

// #include <stdio.h>

// int main() {
// 	printf("%d", ft_isalpha('a'));
// 	printf("%d", ft_isalpha('D'));
// 	printf("%d", ft_isalpha('0'));
// 	printf("%d", ft_isalpha('.'));
// }