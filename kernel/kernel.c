/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:45:31 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 15:19:11 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>
#include <libk.h>

void	print_intro(void) {
	tty_color(vga_entry_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK));
	putstr("   _____ ________    ____  __.____________________\n");
	putstr("  /  |  |\\_____  \\  |    |/ _|\\_   _____/   _____/\n");
	putstr(" /   |  |_/  ____/  |      <   |    __) \\_____  \\ \n");
	putstr("/    ^   /       \\  |    |  \\  |     \\  /        \\\n");
	putstr("\\____   |\\_______ \\ |____|__ \\ \\___  / /_______  /\n");
	putstr("     |__|        \\/         \\/     \\/ jode-vri \\/ \n");
	tty_color(vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK));
}

void	kmain(void) {
	tty_initialize();
	print_intro();
}