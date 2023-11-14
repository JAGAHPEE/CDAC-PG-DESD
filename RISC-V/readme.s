//get 4th bit
.section .text
.global main

main:
li a0,0x12345ff
li a1,0x8
and a1,a0,a1
srli a1,a1,3
ret

// Clear 12th bit
.section .text
.global main
main:
li a0,0x12fff
li a1,0x1
slli a1,a1,0xb
not a3,a1
and a4,a3,a0
ret


.section .text
.global main

// Multiplication
mul:
li a2,0x0
loop:
add a2,a2,a0
addi a1,a1,-1
bne a1,zero,loop
ret

main:
li a0, 0x3
li a1,0x3
jal mul
ret


// Set Clear and Toggle a bit
.section .text
.global main
main:
li a0,0x10101

// Set the 4th Bit
li a1,0x1
slli a2,a1,3
or a3,a2,a0

// clear the 4th bit  shift not and

not a4,a2
and a5,a4,a0

// Toggle the bit
xor a6,a0,a2

ret






/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

.section .text
.global main
main:
li t0,0xffffffff
li t1,0xfff0f000
addi t0,zero,4
addi t1,zero,6
add t2,t0,t1

sub t2,t2,t1

addi t2,t2,-3

ADD t2,t2,t1

OR t3,t2,t1
slt t2,t0,t1
slt t1,t2,-2

sltu t2,t0,t1
li t0,0x7bcdef12
li t1,0x76543219
ADD t2,t1,t0

li t4,0x8bcdef12
li t5,0xa6543219

ADD t3,t5,t4

slti t3,t5,0

/*when overflow happens
 */

bne t3,t4,overflow
ret;
overflow:
nop

Trap

la t0,0x84000000
li t0,0x123
sw t0,-0x56(t0)






// Multiplication

mul:
li a2,0x0	//SUM = 0
loop:
add a2,a2,a0 // SUM = SUM + i
addi a1,a1,-1 // i--
bne a1,zero,loop  // if a1 != 0 return loop
ret

main:
li a0,4
li a1,0x4
jal mul
re
main:
li a0,0x12345ff
srli a1,a0,4
andi a0,a1,0x1
ret
// Set Toggle Reset
main:
li t0,0xaa
li t1,0x1
slli t1,t1,0x4
or t2,t1,t0			// To Set the 4th bit from 0

not t3,t1
and t4,t3,t0		// To Reset the 4th Bit from 0
xor t5,t1,t0		// Toggle the 4th Bit from 0

ret


main:
li t0,0xaaaa
li t1,0x1
slli t1,t1,0xc
