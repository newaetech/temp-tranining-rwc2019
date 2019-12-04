write_bytes:
        push    {r4, r5, r6, lr}
        subs    r5, r1, #0
        beq     .L1
        sub     r4, r0, #4
        add     r5, r4, r5, lsl #2
.L3:
        ldr     r0, [r4, #4]!
        bl      uart_write
        cmp     r5, r4
        bne     .L3
.L1:
        pop     {r4, r5, r6, lr}
        bx      lr