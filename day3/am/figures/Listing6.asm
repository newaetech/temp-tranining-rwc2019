main:
        push    {r4, lr}
        mov     r4, #0
        mov     r0, r4
        bl      load_image
        bl      random
        bl      delay
        mov     r0, r4
        bl      verify_image
        cmp     r0, r4
        bne     .L8
.L5:
        b       .L5
.L8:
        mov     r0, r4
        bl      jump_to_image
        b       .L5