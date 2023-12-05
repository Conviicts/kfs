# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 20:57:26 by jode-vri          #+#    #+#              #
#    Updated: 2023/12/05 02:26:02 by jode-vri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	kfs
ISO			=	$(NAME).iso

CC			=	gcc
CFLAGS		+=	-m32 -nostdlib -nodefaultlibs -fno-builtin -fno-exceptions -fno-stack-protector -Wall -Wextra -g3

NASM		=	nasm
NASM_FLAGS	=	-f elf32 -g -F dwarf

LD			=	ld
LINKER		=	srcs/arch/i386/linker.ld

HEADERS		=	incs
ISO_DIR		=	iso

BOOT		=	srcs/arch/i386/boot.asm
BOOT_OBJ	=	srcs/arch/i386/boot.o

SRCS		=	$(shell find srcs -type f -name '*.c')
SRCS_ASM	=	$(shell find srcs/arch/i386/ -type f -name '*.s')

OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS		+=	$(patsubst %.asm,%.o,$(SRCS_ASM))

%.o: %.c $(HFILES)
	@echo "Creating $@ ..."
	@$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

%.o: %.asm
	@echo "Creating $@ ..."
	@$(NASM) -f elf32 -g -F dwarf $< -o $@

all: boot $(OBJS) linker iso

boot:	$(BOOT)
	echo "Creating $(BOOT_OBJ)..."
	$(NASM) -f elf32 $(BOOT) -o $(BOOT_OBJ)

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
	@grub-file --is-x86-multiboot $(ISO_DIR)/boot/$(NAME)
	@grub-mkrescue -o $(ISO) --compress=xz $(ISO_DIR)

clean:
	@echo "Cleaning Objs ..."
	@rm -rf $(OBJS) $(BOOT_OBJ) $(ISO_DIR)

fclean: clean
	@echo "Cleaning kfs ..."
	@rm -rf $(NAME) $(ISO)

re: fclean all

.PHONY: all boot kernel linker iso clean
