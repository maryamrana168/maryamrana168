.model small
.stack 100h

.data
 
BinaryTable db 128 dup(0)

prompt  db 'Enter ASCII character: $'
result  db 13,10,'Binary value: $'

newline db 13,10,'$'

.code
main proc
    mov ax, @data
    mov ds, ax
 
    mov cx, 128        
    mov si, offset BinaryTable
    mov bl, 0

FillTable:
    mov [si], bl        
    inc si
    inc bl
    loop FillTable

    
    mov dx, offset prompt
    mov ah, 09h
    int 21h

    mov ah, 01h        
    int 21h
    mov al, al        I

    
    xor bx, bx
    mov bl, al          

    
    mov si, offset BinaryTable
    xlat                

   
    mov dx, offset newline
    mov ah, 09h
    int 21h

    mov dx, offset result
    mov ah, 09h
    int 21h

    mov bl, al         
    mov cx, 8          
PrintBits:
    shl bl, 1           
    jc Print1
Print0:
    mov dl, '0'
    mov ah, 02h
    int 21h
    jmp NextBit
Print1:
    mov dl, '1'
    mov ah, 02h
    int 21h
NextBit:
    loop PrintBits
    mov ah, 4Ch
    int 21h

main endp
end main
