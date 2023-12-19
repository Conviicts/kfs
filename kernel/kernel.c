/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:45:31 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 17:23:37 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>
#include <kernel/gdt.h>
#include <kernel/interrupts/idt.h>
#include <kernel/interrupts/keyboard.h>
#include <libk.h>
#include <kfs.h>

void	kmain(void) {
	tty_initialize();
	init_gdt();
	init_idt();
	print_intro();
	shell();
}