/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:52:28 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 19:10:06 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
#define IO_H

#include <defines.h>

/**
 * @brief       Read a byte from an I/O port.
 * @description This function reads a byte from the specified I/O port address.
 *
 * @param port  The address of the I/O port from which to read the byte.
 *              The port parameter should be of type uint16_t.
 *
 * @return      The byte read from the specified I/O port.
 *              The return type is unsigned char.
 *
 * @note        This function is typically used for low-level I/O operations,
 *              and it's important to ensure that the port address is valid
 *              and corresponds to a device or register that supports byte
 *              read operations.
 *
 * @warning     Improper use of this function may lead to system instability.
 *              Ensure that you have the necessary permissions to perform
 *              I/O operations, and use this function responsibly.
 */
unsigned char inb(uint16_t port);

/**
 * @brief       Sends the given data to the specified I/O port.
 * @description This function sends a byte of data to the specified I/O port address.
 *              It is typically used for low-level I/O operations.
 *
 * @param port  The I/O port to which the data will be sent.
 *              The port parameter should be of type uint16_t.
 *
 * @param data  The byte of data to be sent to the I/O port.
 *              The data parameter should be of type uint8_t.
 *
 * @note        Ensure that the provided port address is valid and corresponds
 *              to a device or register that supports byte write operations.
 *
 * @warning     Improper use of this function may lead to system instability.
 *              Ensure that you have the necessary permissions to perform
 *              I/O operations, and use this function responsibly.
 */
void outb(uint16_t port, uint8_t data);

void outw(uint16_t port, uint16_t value);

#endif