/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 17:42:47 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 17:51:06 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdint.h>
#include <sys/types.h>

static ssize_t	ckd_mul(size_t a, size_t b)
{
	if (b && a > SIZE_MAX / b)
		return (-1);
	return (a * b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	ssize_t	n;
	void	*ptr;

	n = ckd_mul(nmemb, size);
	if (n == -1)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ptr = malloc(n);
	if (ptr)
		ft_memset(ptr, 0x0, n);
	return (ptr);
}
