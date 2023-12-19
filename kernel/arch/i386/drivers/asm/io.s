global inb
global outb

; inb - returns a byte from the given I/O port
; 
; Input:    [esp + 4] - The address of the I/O port
; Output:   AL - The byte read from the I/O port
; Clobbers: DX - Used for storing the I/O port address
; 
; Description: Reads a byte from the specified I/O port and returns it.
; 
; Usage Example:
;   push 0x3F8        ; I/O port address for COM1 serial port
;   call inb          ; Call the inb function to read a byte
;   ; The read byte is now in the AL register
; 
inb:
    mov dx, [esp + 4]   ; Move the address of the I/O port to the DX register
    in  al, dx          ; Read a byte from the I/O port and store it in the AL register
    ret                 ; Return the read byte


; outb - send a byte to an I/O port
; 
; Input:    [esp + 8] - The data byte to be sent
;           [esp + 4] - The I/O port address
; Output:   None
; Clobbers: AL - Used for storing the data byte, DX - Used for storing the I/O port address
; 
; Description: Sends a byte to the specified I/O port.
; 
; Usage Example:
;   push 0x41         ; Data byte to be sent
;   push 0x3F8        ; I/O port address for COM1 serial port
;   call outb         ; Call the outb function to send the byte
;   ; The byte has been sent to the specified I/O port
; 
outb:
    mov al, [esp + 8]   ; Move the data to be sent into the AL register
    mov dx, [esp + 4]   ; Move the address of the I/O port into the DX register
    out dx, al          ; Send the data to the I/O port
    ret                 ; Return to the calling function
