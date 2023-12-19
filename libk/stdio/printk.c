/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:29:53 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 11:51:34 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libk.h>

void	get_hex(char *res, int n, int size, int upper) {
	char	*hex;
	int		len;

	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";

	len = size - 1;
    memset(res, '0', size);
    res[size - 1] = 0;
	while (n != 0) {
		res[--len] = hex[n % 16];
		n = n / 16;
	}
}

void printk(char *s, ...) {
	char	buffer[10];
	int		*arg_nb;
	char	*args;
	int		i;

	arg_nb = (int *)(&s);
	args = (char *)(*arg_nb++);
	i = 0;
	while (args[i]) {
		if (args[i] == '%') {
			i++;
			if (args[i] == 'c')
				putchar(*arg_nb++);
			else if (args[i] == 's')
				putstr(*((char **)arg_nb++));
			else if (args[i] == 'd') {
				putnbr(*arg_nb++);
			} else if (args[i] == 'x' || args[i] == 'p') {
				memset(buffer, 0, sizeof(buffer));
				get_hex(buffer, *arg_nb++, sizeof(buffer), 0);
				putstr("0x");
				putstr(buffer);
			} else if (args[i] == 'X') {
				memset(buffer, 0, sizeof(buffer));
				get_hex(buffer, *arg_nb++, sizeof(buffer), 1);
				putstr("0X");
				putstr(buffer);
			}
			else {
				putchar('%');
				putchar(args[i]);
			}
		}
		else
			putchar(args[i]);
		i++;
	}
}