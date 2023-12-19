/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:47:55 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 10:43:13 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GDT_H
#define GDT_H

#include <defines.h>

#define GDT_SIZE 7

typedef struct  __attribute__((packed)) gdt_entry {
	uint16_t	limit_low;
	uint16_t	base_low;
	uint8_t		base_middle;
	uint8_t		access;
	uint8_t		granularity;
	uint8_t		base_high;
}  t_gdt_entry;

typedef struct  __attribute__((packed)) gdt_ptr {
   uint16_t		limit;
   uint32_t		base;
} t_gdt_ptr;

/**
 * @brief       Load the Global Descriptor Table (GDT) using the provided GDT pointer.
 * @description This function initiates a new GDT by loading it using the specified GDT pointer.
 *              The GDT is a data structure used by the x86 architecture to define memory segments.
 *
 * @param gdt_ptr The 32-bit linear address pointing to the GDT structure and its size.
 *                This parameter is typically a pointer to a structure containing the GDT's base address
 *                and the limit (size) of the GDT.
 *
 * @note        The GDT must be properly set up before calling this function.
 *              Ensure that the GDT pointer points to a valid GDT structure with appropriate segment descriptors.
 *
 * @warning     Improper use of this function may lead to undefined behavior or system instability.
 *              Ensure that the GDT is correctly configured and that you have the necessary permissions
 *              to perform low-level operations.
 */
extern void gdt_flush(uint32_t gdt_ptr);

/**
 * @brief       Initialize the Global Descriptor Table (GDT) with predefined segment entries.
 * @description This function sets up the GDT with predefined segment entries for a basic
 *              kernel and user mode configuration. It then loads the GDT using the `gdt_flush` function.
 *
 * @note        Ensure that the necessary structures (`gdt_ptr`, `gdt_entries`) and functions
 *              (`create_entry`, `gdt_flush`) are properly defined before calling this function.
 *
 * @warning     Improper use of this function may lead to undefined behavior or system instability.
 *              Ensure that the GDT entries are correctly configured for your operating system's requirements.
 */
void    init_gdt();

#endif