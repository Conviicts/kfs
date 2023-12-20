/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:45:31 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/20 19:08:59 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>
#include <kernel/gdt.h>
#include <kernel/interrupts/idt.h>
#include <kernel/interrupts/keyboard.h>
#include <libk.h>
#include <kfs.h>

void	kmain(void) {
	int	tab[15] = {0, 1, 2, 3, 4, 5, 9, 85, 888, 999, 9999, 10000, 15000, 4774, 4242};

	tty_initialize();
	init_gdt();
	init_idt();
	print_intro();
	print_memory(tab, sizeof(tab), 0);
	shell();
}