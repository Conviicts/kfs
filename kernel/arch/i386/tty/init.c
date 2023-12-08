/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:59:34 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 15:16:10 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>
#include <vga.h>

t_tty	tty;

void tty_draw(t_tty *t) {
	for (size_t y = 0; y < VGA_HEIGHT; ++y) {
		for (size_t x = 0; x < VGA_WIDTH; ++x) {
			const size_t i = y * VGA_WIDTH + x;
			t->vga_buffer[i] = t->screen[i];
		}
	}
}

void tty_clear(t_tty *t) {
	t->row = 0;
	t->column = 0;
	for (size_t y = 0; y < VGA_HEIGHT; ++y) {
		for (size_t x = 0; x < VGA_WIDTH; ++x) {
			t->screen[(y * VGA_WIDTH) + x] = vga_entry(' ', t->color);
		}
	}
	tty_draw(t);
}

void tty_initialize(void) {
	tty.color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	tty.vga_buffer = (uint16_t *)0xB8000;
	tty_clear(&tty);
}
