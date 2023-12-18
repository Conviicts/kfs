/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:19:43 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 14:55:33 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/io.h>
#include <kernel/interrupts/pic.h>

void	pic_acknowledge(unsigned int interrupt) {
	if (interrupt < 0x20 || interrupt > 0x30-1)
		return;
	if (interrupt < 0x28)
		outb(0x20, 0x20);
	else
		outb(0xA0, 0x20);
}

void	pic_remap(int offset1, int offset2) {
	outb(0x20, 0x11);		// starts the initialization sequence (in cascade mode)
	outb(0xA0, 0x11);
	outb(0x21, offset1);	// ICW2: Master PIC vector offset
	outb(0xA1, offset2);	// ICW2: Slave PIC vector offset
	outb(0x21, 0x04);		// ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
	outb(0xA1, 0x02);		// ICW3: tell Slave PIC its cascade identity (0000 0010)

	outb(0x21, 0x01);
	outb(0xA1, 0x01);

	// Setup Interrupt Mask Register (IMR)
	outb(0x21, 0xFD);
	outb(0xA1, 0xFF);

	asm("sti");				// Enable interrupts.
}