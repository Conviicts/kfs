#ifndef KERNEL_H
#define KERNEL_H

#include "vga.h"

typedef struct s_tty {
	unsigned long	columns[10];
	unsigned long	rows[10];
	unsigned long	row;
	unsigned long	column;
	unsigned char	color;
	unsigned short	*buffer;
}	t_tty;
extern t_tty g_tty;

void			init_term();
void			khello(void);
unsigned long	kstrlen(const char *s);
void			kputchar(const char c);
void			kputstr(const char *s);

#endif