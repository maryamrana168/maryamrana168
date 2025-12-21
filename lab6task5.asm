.model small
.stack 100h
.data
    string1  db "Enter  a number: $"
    string2  db  " Enter  a number: $"
     
    array1  db 8 DUP(00)        
     array2  db 8 DUP(00)   
.code
main proc
    mov ax, @data
    mov ds, ax
    mov dx, offset string 1
    mov ah,09
    int 21h

    mov dx, offset array1
    mov ch,8
    again: mov ah,01
    int 21h
   cmp ah,01
   jle insert
   jmp exit
   insert: mov dx,ah
   jnz again
   dec ch

mov dx, offset string 2
    mov ah,09
    int 21h

  mov dx, offset array2
    mov cl,8
    aa: mov ah,01
    int 21h
   cmp ah,01
   jle pro
   jmp exit
   pro: mov dx,ah
   jnz aa
   dec cl
   


mov ch,8
start: mov di,offset array1
mov si,offset array2
mov bl,[si]
add bl,[di]
mov dl,bl
mov ah, 02
int 21h
inc si
inc di
dec ch
jnz start
jz exit

exit: mov ah,4ch
int 21h




