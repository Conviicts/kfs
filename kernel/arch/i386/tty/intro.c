/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:19:10 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 15:22:05 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>

static void	print_centered(const char *s) {
	size_t	len;
	size_t	diff;

	len = strlen(s);
	diff = VGA_WIDTH - len;
	for (size_t index = 0; index < diff / 2; index++)
		putchar(' ');
	putstr(s);
	for (size_t index = 0; index < diff / 2; index++)
		putchar(' ');
}

void	print_intro(void) {
	tty_color(vga_entry_color(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK));
	print_centered("------------------------------------------------------");
	print_centered("|    _____ ________    ____  __.____________________ |");
	print_centered("|   /  |  |\\_____  \\  |    |/ _|\\_   _____/   _____/ |");
	print_centered("|  /   |  |_/  ____/  |      <   |    __) \\_____  \\  |");
	print_centered("| /    ^   /       \\  |    |  \\  |     \\  /        \\ |");
	print_centered("| \\____   |\\_______ \\ |____|__ \\ \\___  / /_______  / |");
	print_centered("|      |__|        \\/         \\/     \\/ jode-vri \\/  |");
	print_centered("------------------------------------------------------");
	putchar("\n");
	tty.column = 0;
	tty_color(vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK));
}
