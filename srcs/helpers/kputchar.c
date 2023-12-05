/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kputchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:28:21 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/05 02:18:33 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"

void	kputchar(const char c) {
	if (c == '\n') {
		g_tty.column = 0;
		g_tty.row++;
		if (g_tty.row == VGA_HEIGHT)
			init_term();
		return ;
	}
	g_tty.buffer[(g_tty.row * 80) + g_tty.column] = c | g_tty.color << 8;
	g_tty.column++;
	if (g_tty.column == VGA_WIDTH) {
		g_tty.column = 0;
		g_tty.row++;
		if (g_tty.row == VGA_HEIGHT)
			g_tty.row = 0;
	}
}