        .global main
        .text

main:   push    {lr}
            
        mov     r4, #0      @ character count
        mov     r5, #0      @ newline characters
        mov     r6, #0      @ whitespace characters
        mov     r7, #0      @ letters
        mov     r8, #0      @ decimal digits
        mov     r9, #0      @ hexadecimal digits
        mov     r10, #0     @ arithmetic operators

        

loop:   bl      getchar     @ read one character

        cmp     r0, #-1     @ compare char to EOF
        beq     end         @ exit loop if EOF

        bl      putchar     @ display character
        
        add     r4, r4, #1  @ increment character count
        
if1:    cmp     r0, #0x0a   @ compare char to newline
        bne     endif1      @ skips over if not a newline

then1:  add     r5, r5, #1  @ increment newline count
        add     r6, r6, #1  @ increment whitespace count

endif1: 

if2:    cmp     r0, #0x09   @ compare char to tab
        bne     endif2      @ skips over if not a tab
        
then2:  add     r6, r6, #1  @ increment whitespace count
        
endif2:  

if3:    cmp     r0, #0x20   @ compare char to space
        bne     endif3      @ skips over if not a space

then3:  add     r6, r6, #1  @ increment whitespace count

endif3:

if4:    cmp     r0, #0x41   @ compare char to 'A'
        blt     endif4      @ skip if <
        cmp     r0, #0x5a   @ compare char to 'Z'
        bgt     endif4      @ skip if >

then4:  add     r7, r7, #1  @ increment letter count

endif4:

if5:    cmp     r0, #0x61   @ compare char to 'a'
        blt     endif5      @ skip if <
        cmp     r0, #0x7a   @ compare char to 'z'
        bgt     endif5      @ skip if >

then5:  add     r7, r7, #1  @ increment letter count

endif5:

if6:    cmp     r0, #0x30   @ compare char to '0'
        blt     endif6      @ skip if <
        cmp     r0, #0x39   @ compare char to '9'
        bgt     endif6      @ skip if >

then6:  add     r8, r8, #1  @ increment decimal digit count
        add     r9, r9, #1  @ increment hexadecimal digit count

endif6:

if7:    cmp     r0, #0x41   @ compare char to 'A'
        blt     endif7      @ skip if <
        cmp     r0, #0x46   @ compare char to 'F'
        bgt     endif7      @ skip if >

then7:  add     r9, r9, #1  @ increment hexadecimal digit count

endif7:

if8:    cmp     r0, #0x61   @ compare char to 'a'
        blt     endif8      @ skip if <
        cmp     r0, #0x66   @ compare char to 'f'
        bgt     endif8      @ skip if >

then8:  add     r9, r9, #1  @ increment hexadecimal digit count

endif8:

if9:    cmp     r0, #0x2b     @ compare char to '+'
        bne     endif9        @ skip if not '+'

then9:  add     r10, r10, #1  @ increment arithmetic count
        
endif9:

if10:   cmp     r0, #0x2d     @ compare char to '-'
        bne     endif10       @ skip if not '-'

then10: add     r10, r10, #1  @ increment arithmetic count

endif10:

if11:   cmp     r0, #0x2a     @ compare char to '*'
        bne     endif11       @ skip if not '*'

then11: add     r10, r10, #1  @ increment arithmetic count

endif11:

if12:   cmp     r0, #0x2f     @ compare char to '/'
        bne     endif12       @ skip if not '/'

then12: add     r10, r10, #1  @ increment arithmetic count

endif12: b      loop

end:    ldr     r0, =fmt1   @ print num characters
        mov     r1, r4      
        bl      printf

        ldr     r0, =fmt2   @ print num newline 
        mov     r1, r5
        bl      printf

        ldr     r0, =fmt3   @ print num whitespace 
        mov     r1, r6
        bl      printf
        
        ldr     r0, =fmt4   @ print num letters
        mov     r1, r7
        bl      printf
        
        ldr     r0, =fmt5   @ print num decimal digits 
        mov     r1, r8
        bl      printf

        ldr     r0, =fmt6   @ print num hex digits
        mov     r1, r9
        bl      printf
        
        ldr     r0, =fmt7   @ print num arithmetic operators
        mov     r1, r10
        bl      printf

        pop     {lr}
        bx      lr

fmt1:   .asciz  "\nTotal number of characters: %d\n"
fmt2:   .asciz  "Number of newline characters: %d\n"
fmt3:   .asciz  "Number of whitespace characters: %d\n"
fmt4:   .asciz  "Number of letters: %d\n"
fmt5:   .asciz  "Number of decimal digits: %d\n"
fmt6:   .asciz  "Number of hexadecimal digits: %d\n"
fmt7:   .asciz  "Number of arithmetic operators: %d\n"
