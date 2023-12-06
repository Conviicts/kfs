/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:59:34 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 03:53:03 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel/tty.h"
#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*)0xB8000;
 
static size_t row;
static size_t column;
static uint8_t color;
static uint16_t* buffer;

void tty_initialize(void) {
	row = 0;
	column = 0;
	color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			buffer[index] = vga_entry(' ', color);
		}
	}
}

void tty_setcolor(uint8_t color) {
	color = color;
}

void tty_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	buffer[index] = vga_entry(c, color);
}
 
void tty_putchar(char c) {
	// int line;
	unsigned char uc = c;
 
	tty_putentryat(uc, color, column, row);
	if (++column == VGA_WIDTH) {
		column = 0;
		if (++row == VGA_HEIGHT) {
			// for(line = 1; line <= (int)VGA_HEIGHT - 1; line++) {
			// 	tty_scroll(line);
			// }
			// tty_delete_last_line();
			row = VGA_HEIGHT - 1;
		}
	}
}
 
void tty_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		tty_putchar(data[i]);
}
 
void tty_writestring(const char* data) {
	tty_write(data, strlen(data));
}
