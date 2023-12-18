/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:07:33 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 14:51:52 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDT_H
#define IDT_H

#include <defines.h>

extern void load_idt(uint32_t ptr);
extern void interrupt_handler_33(void);

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

void	init_idt(void);

#endif