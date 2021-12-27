        .global length

length: push    {r4, r5, lr}        
        mov     r4, #0

loop:   ldrb    r5, [r0, r4]
        strb    r5, [r0, r4]
        
        cmp     r5, #0
        beq     end
        
        add     r4, r4, #1        @ increment character count
        b       loop

end:    mov     r0, r4
        pop     {r4, r5, lr}
        bx      lr

        .global copy

copy:   push    {r4, r5, r6, lr}
        mov     r4, #0
        mov     r5, #0

loop2:  ldrb    r6, [r1, r5]
        strb    r6, [r0, r4]
        
        cmp     r6, #0
        beq     end2

        add     r4, r4, #1
        add     r5, r5, #1
        b       loop2

end2:   pop     {r4, r5, r6, lr}
        bx      lr

        .global append

append: push    {r4, r5, r6, lr}
        mov     r4, #0
        mov     r5, #0

loop3:  ldrb    r6, [r0, r4]
        cmp     r6, #0
        beq     loop4

        add     r4, r4, #1
        b       loop3

loop4:  ldrb    r6, [r1, r5]
        strb    r6, [r0, r4]
        cmp     r6, #0
        beq     end3

        add     r4, r4, #1
        add     r5, r5, #1
        b       loop4

end3:   pop     {r4, r5, r6, lr}
        bx      lr

        .global duplicate

duplicate:  
        push    {r4, r5, r6, r7, r8, r9, lr}
        mov     r4, #0
        mov     r6, r0

loop5:  ldrb    r5, [r0, r4]
        strb    r5, [r0, r4]

        cmp     r5, #0
        beq     next

        add     r4, r4, #1
        b       loop5

next:   mov     r0, r4

        bl      malloc
        mov     r7, r0
        mov     r8, #0

loop6:  ldrb    r9, [r6, r8]
        strb    r9, [r0, r8]
        
        add     r8, r8, #1
        sub     r4, r4, #1

        cmp     r4, #0
        bne     loop6

end4:   mov     r0, r7
        pop     {r4, r5, r6, r7, r8, r9, lr}
        bx      lr

        .global compare

compare:
        push    {r4, r5, r6, lr}
        mov     r4, #0

loop7:  ldrb    r5, [r0, r4]
        strb    r6, [r1, r4]

        cmp     r5, r6
        bgt     great
        cmp     r5, r6
        blt     less
        cmp     r5, #0
        beq     zero

        add     r4, r4, #1
        b       loop7

great:  mov     r0, #1
        b       end5

less:   mov     r0, #-1
        b       end5

zero:   mov     r0, #0
        
end5:   pop     {r4, r5, r6, lr}
        bx      lr



        

