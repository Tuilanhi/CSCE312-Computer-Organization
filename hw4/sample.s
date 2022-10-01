	.file	"sample.c"
	.version	"01.01"

# this section has some definitions needed for counting instructions

# declare an integer called 'insn_count'.  it is automatically initialied to 0
# by the assembler
	.comm	insn_count,4,4
# a constant string used for the 'printf' call that will print out
# the number of instructions executed

.count_string:
	.string	"%d instructions executed\n"

gcc2_compiled.:
.section	.rodata
.LC0:
	.string	"%d\n"

.text
	.align 4
.globl main
	.type	 main,@function

# basic block #1
main:
	addl $6,insn_count # six instructions in this block
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	movl $1,-8(%ebp)
	movl $1,-12(%ebp)
	movl $0,-4(%ebp)
	.p2align 4,,7
# basic block #2
.L3:
	addl $2,insn_count # two instructions in this block
	cmpl $13,-4(%ebp)
	jle .L6

# basic block #3
	addl $1,insn_count # one instruction in this block
	jmp .L4
	.p2align 4,,7
# basic block #4

.L6:
	addl $4,insn_count # four instructions in this block
	movl -12(%ebp),%eax
	addl %eax,-8(%ebp)
	movl -8(%ebp),%eax
	addl %eax,-12(%ebp)
# basic block #5
.L5:
	addl $2,insn_count # two instructions in this block
	incl -4(%ebp)
	jmp .L3
	.p2align 4,,7
# basic block #6
.L4:
	addl $9,insn_count # nine instructions up to 'call exit' in this block
	addl $-8,%esp
	movl -8(%ebp),%eax
	pushl %eax
	pushl $.LC0
	call printf
	addl $16,%esp
	addl $-12,%esp

# code to print out the instruction count

	movl insn_count,%eax
	pushl %eax
	pushl $.count_string
	call printf
	addl $16,%esp

	pushl $0
	call exit
	addl $16,%esp
	.p2align 4,,7
.L2:
	leave
	ret
.Lfe1:
	.size	 main,.Lfe1-main
	.ident	"GCC: (GNU) 2.95.4 20011002"