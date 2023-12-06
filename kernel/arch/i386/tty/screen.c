/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:59:33 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 15:18:37 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>

void	tty_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t i = y * VGA_WIDTH + x;

	tty.screen[i] = vga_entry(c, color);
	tty.vga_buffer[i] = vga_entry(c, color);
}

static void	tty_printchar(char c) {
	tty_putentryat(c, tty.color, tty.column, tty.row);
	if (++tty.column == VGA_WIDTH) {
		tty.column = 0;
		if (++tty.row == VGA_HEIGHT) {
			tty.row = 0;
		}
	}
}

static void	tty_newline() {
	if (tty.row == VGA_HEIGHT)
		tty.row = 0;
	else
		tty.row++;
	tty.column = 0;
}

void tty_putchar(char c) {
	if (isprint(c)) {
		tty_printchar(c);
	} else if (c == '\n') {
		tty_newline();
	}
}