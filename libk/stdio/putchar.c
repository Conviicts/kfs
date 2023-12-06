/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:30:43 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 03:50:01 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>

int		putchar(int ic) {
	char c;

	c = (char)ic;
	tty_write(&c, sizeof(c));
	return (c);
}