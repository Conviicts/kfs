/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:20:50 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 14:50:50 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIC_H
#define PIC_H

#include <defines.h>

void pic_acknowledge(uint32_t interrupt);
void pic_remap(int offset1, int offset2);

#endif