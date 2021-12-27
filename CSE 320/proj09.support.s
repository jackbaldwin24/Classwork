        
        .global negate

negate:
        push    {r4, r5, lr}

        mov     r4, r0
        mov     r5, #0
        sub     r4, r5, r4

        mov     r0, r4
        
        pop     {r4, r5, lr}
        bx      lr

        
        .global absolute

absolute:
        push    {r4, r5, lr}

        mov     r4, r0
        mov     r5, #0

        cmp     r4, #0
        bge     pos

neg:
        sub     r4, r5, r4

pos:
        mov     r0, r4

        pop     {r4, r5, lr}
        bx      lr

        
        .global add

add:
        push    {r4, r5, lr}

        mov     r4, r0
        mov     r5, r1

        adds    r4, r4, r5

        bvs     error
        
        mov     r0, r4
        b       end
error:
        mov     r0, #0x80000000

end:
        pop     {r4, r5, lr}
        bx      lr

        
        .global sub

sub:
        push    {r4, r5, lr}

        mov     r4, r0
        mov     r5, r1

        subs    r4, r4, r5

        bvs     error1

        mov     r0, r4
        b       end1

error1:
        mov     r0, #0x80000000

end1:
        pop     {r4, r5, lr}
        bx      lr

        
        .global mul
mul:
        push    {r4, r5, lr}

        mov     r4, r0
        mov     r5, r1

        smull   r4, r5, r4, r5

        cmp     r4, #0
        blt     neg2

        cmp     r5, #0                @ checks if all the bits are 0s
        bne     error2

        b       valid2

neg2:
        cmp     r5, #0xffffffff       @ checks if all the bits are 1s
        beq     valid2

error2:
        mov     r0, #0x80000000
        b       end2
valid2:
        mov     r0, r4
end2:
        pop     {r4, r5, lr}
        bx      lr


        .global divide
        .text
divide:
        push    {r4, r5, lr}

        mov     r4, r0
        mov     r5, r1

        cmp     r5, #0
        beq     error3

        sdiv    r4, r4, r5

        mov     r0, r4
        b       end3

error3:
        mov     r0, #0x80000000
        
end3:
        pop     {r4, r5, lr}
        bx      lr
    
        .global power
power:
        push    {r4, r5, r6, r7, lr}

        mov     r4, r0
        mov     r5, r1
        mov     r6, #1
        
        cmp     r5, #0            @ anything raised to 0 will be 1 if +, -1 if -
        beq     one

        cmp     r5, #0            @ cannot be raised to negative
        blt     error4

        b       loop

one:
        cmp     r4, #0            @ cannot raise 0^0
        beq     error4

        cmp     r4, #0
        blt     negone

        mov     r0, #1

        b       end4

negone:
        mov     r0, #-1

        b       end4

loop:
        cmp     r5, #0
        beq     valid4            @ stop the loop if 0
        
        smull   r6, r7, r6, r4

        cmp     r6, #0            @ check for overflow
        blt     neg4

        cmp     r7, #0
        bne     error4

        sub     r5, r5, #1        @ decrement r5

        b       loop

neg4:
        cmp     r7, #0xffffffff
        beq     loop

error4:
        mov     r0, #0x80000000
        b       end4

valid4:
        mov     r0, r6
        
end4:
        pop     {r4, r5, r6, r7, lr}
        bx      lr

        
        .global factorial

factorial:
        push    {r4, r5, r6, lr}

        mov     r4, r0          
        mov     r5, #1
        
        cmp     r4, #0          @ cannot be negative
        blt     error5

        cmp     r4, #0
        beq     valid5

floop:
        cmp     r4, #1
        beq     valid5

        smull   r5, r6, r5, r4

        cmp     r6, #0
        bne     error5

        sub     r4, r4, #1

        b       floop

error5:
        mov     r0, #0x80000000
        b       end5
valid5:
        mov     r0, r5
end5:
        pop     {r4, r5, r6, lr}
        bx      lr

