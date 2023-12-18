/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:45:31 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 16:33:04 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>
#include <kernel/gdt.h>
#include <kernel/interrupts/idt.h>
#include <libk.h>

void	kmain(void) {
	tty_initialize();
	init_gdt();
	init_idt();
	print_intro();
	putstr("kfs> ");
	printk("Hello %s, %d, %c, %s, %d\n", "world", 42, 'c', "test", 123);
}