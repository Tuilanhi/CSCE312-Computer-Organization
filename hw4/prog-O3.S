"prog-O3.S" 138L, 2156C
        .file   "prog.c"
        .text
        .p2align 4,,15
        .globl  bubble_sort
        .type   bubble_sort, @function
bubble_sort:
.LFB20:
        .cfi_startproc
        testl   %esi, %esi
        jle     .L1
        leal    -2(%rsi), %eax
        cmpl    $1, %esi
        leaq    4(%rdi,%rax,4), %r8
        jne     .L17
.L1:
        rep ret
.L17:
        xorl    %r10d, %r10d
        .p2align 4,,10
        .p2align 3
.L4:
        movq    %rdi, %rax
        xorl    %r9d, %r9d
        .p2align 4,,10
        .p2align 3
.L8:
        movl    (%rax), %ecx
        movl    4(%rax), %edx
        cmpl    %edx, %ecx