/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:27:04 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 15:54:01 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <defines.h>

#define KEYBOARD_DATA_PORT 0x60

uint8_t keyboard_read(void);
uint8_t keyboard_get_char(uint8_t code);

#endif