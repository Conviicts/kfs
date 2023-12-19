/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:47:55 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 11:12:20 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GDT_H
#define GDT_H

#include <defines.h>

#define GDT_SIZE 7

#define SEG_DESCTYPE(x)  ((uint8_t)((x) << 0x04)) // Descriptor type (0 for system, 1 for code/data)
#define SEG_PRES(x)      ((uint8_t)((x) << 0x07)) // Present
#define SEG_SAVL(x)      ((uint8_t)((x) << 0x0C)) // Available for system use
#define SEG_LONG(x)      ((uint8_t)((x) << 0x0D)) // Long mode
#define SEG_SIZE(x)      ((uint8_t)((x) << 0x0E)) // Size (0 for 16-bit, 1 for 32)
#define SEG_GRAN(x)      ((uint8_t)((x) << 0x0F)) // Granularity (0 for 1B - 1MB, 1 for 4KB - 4GB)
#define SEG_PRIV(x)      ((uint8_t)(((x) &  0x03) << 0x05))   // Set privilege level (0 - 3)

#define SEG_DATA_RD        0x00 // Read-Only
#define SEG_DATA_RDA       0x01 // Read-Only, accessed
#define SEG_DATA_RDWR      0x02 // Read/Write
#define SEG_DATA_RDWRA     0x03 // Read/Write, accessed
#define SEG_DATA_RDEXPD    0x04 // Read-Only, expand-down
#define SEG_DATA_RDEXPDA   0x05 // Read-Only, expand-down, accessed
#define SEG_DATA_RDWREXPD  0x06 // Read/Write, expand-down
#define SEG_DATA_RDWREXPDA 0x07 // Read/Write, expand-down, accessed
#define SEG_CODE_EX        0x08 // Execute-Only
#define SEG_CODE_EXA       0x09 // Execute-Only, accessed
#define SEG_CODE_EXRD      0x0A // Execute/Read
#define SEG_CODE_EXRDA     0x0B // Execute/Read, accessed
#define SEG_CODE_EXC       0x0C // Execute-Only, conforming
#define SEG_CODE_EXCA      0x0D // Execute-Only, conforming, accessed
#define SEG_CODE_EXRDC     0x0E // Execute/Read, conforming
#define SEG_CODE_EXRDCA    0x0F // Execute/Read, conforming, accessed

#define GDT_CODE_PL0 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(0)     | SEG_CODE_EXRD

#define GDT_DATA_PL0 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(0)     | SEG_DATA_RDWR

#define GDT_STACK_PL0 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(0)     | SEG_DATA_RDWREXPD

#define GDT_CODE_PL3 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(3)     | SEG_CODE_EXRD

#define GDT_DATA_PL3 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(3)     | SEG_DATA_RDWR

#define GDT_STACK_PL3 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(3)     | SEG_DATA_RDWREXPD

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