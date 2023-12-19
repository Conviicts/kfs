/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:20:50 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 10:27:49 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIC_H
#define PIC_H

#include <defines.h>

/**
 * @brief       Acknowledge an interrupt from the Programmable Interrupt Controller (PIC).
 * @description This function acknowledges an interrupt from the PIC by sending an acknowledgment
 *              command to the appropriate PIC port. It is commonly used to inform the PIC that
 *              the interrupt has been successfully handled and can be acknowledged.
 *
 * @param interrupt The interrupt number to acknowledge.
 *
 * @note        The function checks if the interrupt number is within the valid range (0x20 to 0x2F),
 *              corresponding to IRQs handled by the PIC. If the interrupt is outside this range,
 *              the function returns without performing any action.
 *
 * @warning     Improper use of this function may lead to issues in interrupt handling.
 *              Ensure that the interrupt number is valid and corresponds to a handled IRQ.
 */
void pic_acknowledge(uint32_t interrupt);

/**
 * @brief       Remap the Programmable Interrupt Controllers (PICs) to change default interrupt offsets.
 * @description This function remaps the PICs to change the default interrupt offsets.
 *              It initializes both the master and slave PICs and sets their interrupt vectors.
 *              Additionally, it configures the Interrupt Mask Registers (IMR) to enable or disable specific interrupts.
 *
 * @param offset1   The interrupt vector offset for the master PIC.
 * @param offset2   The interrupt vector offset for the slave PIC.
 *
 * @note        This function is typically called during the initialization of the Interrupt Descriptor Table (IDT)
 *              to ensure that interrupt handlers are called at the correct vectors. The offsets provided should
 *              be chosen carefully to avoid conflicts with system-defined vectors.
 *
 * @warning     Improper use of this function may lead to issues in interrupt handling.
 *              Ensure that the offsets are valid and chosen appropriately for the system's requirements.
 */
void pic_remap(int offset1, int offset2);

#endif