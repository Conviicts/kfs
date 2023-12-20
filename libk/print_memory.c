/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:22:19 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 20:21:16 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libk.h>
#include <stdbool.h>

void	print_memory(const void *addr, size_t size, int upper) {
	uint8_t	*ptr;
	char 	*base;
	size_t	i;
	size_t 	j;

	base = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	ptr = (uint8_t *)addr;
	i = 0;
	while (i < size) {
		j = -1;
		while (++j < 16 && i + j < size) {
			putchar(base[(*(ptr + i + j)/16) % 16]);
			putchar(base[*(ptr + i + j) % 16]);
			if (j % 2)
				putchar(' ');
		}
		while (j < 16) {
			putstr("  ");
			if (j++ % 2)
				putchar(' ');
		}
		j = -1;
		while (++j < 16 && i + j < size) {
			if (*(ptr + i + j) >= 32 && *(ptr + i + j) < 127)
				putchar(*(ptr + i + j));
			else
				putchar('.');
		}
		putchar('\n');
		i += 16;
	}
}
