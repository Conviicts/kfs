# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 20:57:26 by jode-vri          #+#    #+#              #
#    Updated: 2023/12/19 17:25:05 by jode-vri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	kfs
ISO			=	$(NAME).iso

CC			=	gcc
CFLAGS		+=	 -nostdlib -nodefaultlibs -fno-builtin -fno-exceptions -fno-stack-protector -Wall -Wextra -Werror -g3

NASM		=	nasm
NASM_FLAGS	=	-f elf32

LD			=	ld
LINKER		=	kernel/arch/i386/linker.ld

HEADERS		=	include
ISO_DIR		=	iso

BOOT		=	kernel/arch/i386/boot/boot.asm
BOOT_OBJ	=	kernel/arch/i386/boot/boot.o

SRCS		=	$(shell find kernel -type f -name '*.c')
SRCS		+=	$(shell find libk -type f -name '*.c')
SRCS_ASM	=	$(shell find kernel/arch/i386 -type f -name '*.s')

OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS		+=	$(patsubst %.s,%.o,$(SRCS_ASM))

%.o: %.c $(HFILES)
	@echo "Creating $@ ..."
	@$(CC) -m32 $(CFLAGS) -I$(HEADERS) -c $< -o $@

%.o: %.s
	@echo "Creating $@ ..."
	@$(NASM) $(NASM_FLAGS) $< -o $@

all: boot $(OBJS) linker iso

build: boot $(OBJS) linker

boot:	$(BOOT)
	@echo "Creating $(BOOT_OBJ)..."
	@$(NASM) -f elf32 $(BOOT) -o $(BOOT_OBJ)

linker: $(LINKER) $(BOOT_OBJ) $(OBJS)
	@echo "Linking ..."
	@$(LD) -m elf_i386 -T $(LINKER) -o $(NAME) $(BOOT_OBJ) $(OBJS)
	@echo "$(NAME) binary is ready !"

iso:
	@echo "Creating the $(ISO_DIR) directory"
	@mkdir -pv $(ISO_DIR)/boot/grub
	@cp $(NAME) $(ISO_DIR)/boot
	@cp grub.cfg $(ISO_DIR)/boot/grub
	@echo "Creating the $(ISO) file"
	@grub-mkrescue -o $(ISO) --compress=xz $(ISO_DIR)

run:
	@qemu-system-i386 -cdrom $(ISO)

clean:
	@echo "Cleaning Objs ..."
	@rm -rf $(OBJS) $(BOOT_OBJ) $(ISO_DIR)

fclean: clean
	@echo "Cleaning kfs ..."
	@rm -rf $(NAME) $(ISO)

re: fclean all

.PHONY: all boot kernel linker iso clean
