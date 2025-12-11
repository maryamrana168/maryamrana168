.model small
.stack 100h
.data
array1 db 21h,32h,45h,12h,13h,34h,67h,98h,76h,10h,21h,32h,45h,12h,13h,34h
.code
main proc
    mov ax, @data
    mov ds,ax
    mov si,offset array1
    mov di,offset array1
    inc di
    mov cl,15
    again3:mov si,offset array1
    mov di,offset array1
    inc di
    call  bubble_sort 
    dec cl
    jnz again3
    mov cx,16
   repeat: mov bx,[si]
   call  hex_out
   inc si
   dec cx
  jnz repeat 
 mov ah,4ch
 int 21h
main endp

bubble_sort proc
    
    mov ch,15
    again1: mov al,[si]
    mov bl,[di]
    cmp al,bl
    ja aa2
    jmp exit2
    aa2: xchg [si],bl
    mov [di],bl 
    exit2:dec ch
    inc  di
   jnz again1
  
   ret  
bubble_sort endp
    

hex_out proc
 push  cx
 mov dx,bx
 mov ch,4
mov cl,4
 again2: rol bx,cl
 and dl,0fdh
 cmp dl,'9'
jle aa
add dl,37h
mov ah,02
int 21
jmp exit1
aa: add dl,030h
mov ah,02
int 21h
exit1 : dec ch
jnz again2
pop cx
ret 
hex_out endp

end main

 

