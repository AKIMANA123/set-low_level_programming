section .data
    msg db "Hello, ALX", 10, 0   ; 10 is newline, 0 is null terminator

section .text
    extern printf               ; declare printf as external function
    global main                 ; make main visible to linker

main:
    push rbp                    ; set up stack frame
    mov rbp, rsp                ; base pointer = stack pointer
    
    lea rdi, [msg]              ; load address of msg into rdi (first argument)
    mov rax, 0                  ; no vector registers used for printf
    call printf                 ; call printf function
    
    mov rsp, rbp                ; restore stack pointer
    pop rbp                     ; restore base pointer
    mov rax, 0                  ; return 0
    ret
