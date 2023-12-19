/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:07:33 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 10:25:52 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDT_H
#define IDT_H

#include <defines.h>

struct cpu_state {
	uint32_t	eax;
	uint32_t	ebx;
	uint32_t	ecx;
	uint32_t	edx;
	uint32_t	ebp; 
	uint32_t	esi; 
	uint32_t	edi; 
} __attribute__((packed));

struct stack_state {
	uint32_t	error_code;
	uint32_t	eip;
	uint32_t	cs;
	uint32_t	eflags;
} __attribute__((packed));

typedef struct __attribute__((packed)) idt_entry {
	uint16_t	offset_low;
	uint16_t	segment_selector;
	uint8_t		reserved;
	uint8_t		type_and_attr;
	uint16_t	offset_high;
} t_idt_entry;

typedef struct __attribute__((packed)) idt_ptr {
	uint16_t	size;
	uint32_t	address;
} t_idt_ptr;

/**
 * @brief       Load the Interrupt Descriptor Table (IDT) using the provided IDT pointer.
 * @description This function loads the IDT using the specified 32-bit linear address pointer.
 *              The IDT is a data structure used by the x86 architecture to define interrupt gates
 *              and handle interrupts and exceptions.
 *
 * @param ptr   The 32-bit linear address pointing to the IDT structure and its size.
 *              This parameter is typically a pointer to a structure containing the IDT's base address
 *              and the limit (size) of the IDT.
 *
 * @note        The IDT must be properly set up before calling this function.
 *              Ensure that the IDT pointer points to a valid IDT structure with appropriate interrupt gate descriptors.
 *
 * @warning     Improper use of this function may lead to undefined behavior or system instability.
 *              Ensure that the IDT is correctly configured and that you have the necessary permissions
 *              to perform low-level operations.
 */
extern void load_idt(uint32_t ptr);

/**
 * @brief       Interrupt handler for Interrupt 33.
 * @description This function serves as the interrupt handler for Interrupt 33.
 *              Interrupt handlers are functions that handle specific interrupts or exceptions.
 *              The exact functionality of this handler depends on the specific use case or operating system context.
 *
 * @note        Interrupt handlers are typically associated with specific interrupts or exceptions,
 *              and their behavior may vary based on the system's requirements.
 *
 * @warning     Implementing or modifying interrupt handlers requires a deep understanding of system architecture
 *              and operating system development. Improper handling may lead to system instability or crashes.
 */
extern void	interrupt_handler_33(void);

/**
 * @brief       Initialize the Interrupt Descriptor Table (IDT) with predefined entries.
 * @description This function sets up the IDT with predefined entries for handling interrupts.
 *              It associates Interrupt 33 with the provided interrupt handler and loads the IDT.
 *
 * @warning     Improper use of this function may lead to undefined behavior or system instability.
 *              Ensure that the IDT entries are correctly configured, and the interrupt handler is implemented
 *              to handle Interrupt 33 according to the system's requirements.
 */
void		init_idt(void);

#endif