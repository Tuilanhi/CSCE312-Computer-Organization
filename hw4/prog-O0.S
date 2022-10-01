"prog-O0.S" 184L, 3011C
        .file   "prog.c"
# This part has some definitions needed for counting instructions
# declare an integer called 'insn_count' it is initialized to 0
.data 
insn_count	word 0
# a constant string type will be used for 'printf'
# and will print out the number of instructions executed

.count_string:
		.string "%lld instructions executed\n"
.text
.globl  bubble_sort
.type   bubble_sort, @function
bubble_sort:

# basic block #1

.LFB2:
		addq	$6,insn_count(%rip) # 6 instructions in this block
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movq    %rdi, -24(%rbp)
        movl    %esi, -28(%rbp)
        movl    $0, -4(%rbp)
        jmp     .L2

# basic block #2

.L8:
		addq 	$3,insn_count(%rip) # 3 instructions in this block
        movl    $0, -12(%rbp)
        movl    $1, -8(%rbp)
        jmp     .L3

# basic block #3

.L5:
		addq 	$7,insn_count(%rip) # 7 instructions in this block
        movl    -8(%rbp), %eax
        cltq
        salq    $2, %rax
        leaq    -4(%rax), %rdx
        movq    -24(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %edx
        movl    -8(%rbp), %eax

# code to print out the instructions count

		movq insn_count,%eax
		pushq %eax
		pushq $.count_string
		call printf
		call exit