.model small
.stack 100h
.data
  
 table1   db 65 dup (0)
       db 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
         db 166 dup(0)

table2    db 65 dup(0)
       db 'FVXCHSAIYQWGOTBNZKMJPLURDE'
         db 166 dup(0)

array1 db    41 dup (0)
         db '$'

newlinemsg db 13,10,'$'

        
.code
newline proc
  mov dx, offset  newlinemsg
    mov ah ,09
int 21h
ret 
newline endp

main proc
     mov ax,@data
     mov ds,ax
     mov si ,offset array1

   again: mov ah,01
     int 21h
     mov [si],al
     cmp al,'$'
     je encrypt
     inc si
     jmp again
 

 encrypt:mov bx, offset table1
    mov si ,offset array1
   aa: mov  al,[si]
   cmp al,'$'
je print
     XLAT
 mov [si],al
inc si
    jmp aa

print:call newline
 mov dx, offset array1
     mov ah ,09
     int 21h
call newline


mov bx, offset table2
    mov si ,offset array1
   ff: mov  al,[si]
 cmp al,'$'
je print2
     XLAT
mov [si],al
     inc si
    jmp ff

print2:call newline
 mov dx, offset array1
     mov ah ,09
     int 21h
call newline

mov ah,4ch
int 21h
main endp
end main





  
 
