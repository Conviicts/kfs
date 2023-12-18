/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:29:53 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 16:35:45 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libk.h>

void printk(char *s, ...) {
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