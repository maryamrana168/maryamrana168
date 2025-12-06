.model small
.stack 100h

.data
lookupTable db 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
            db 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31
            db 32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47
            db 48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63
            db 64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79
            db 80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95
            db 96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111
            db 112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127

msg db 'Enter ASCII character: $'
show db 'Binary value: $'

.code
main proc
    mov ax, @data
    mov ds, ax

     
    mov dx, offset msg
    mov ah, 9
    int 21h

   
    mov ah, 1
    int 21h      

 
    mov bx, offset lookupTable
    xlat            
    mov dx, offset show
    mov ah, 9
    int 21h

     
    add al, 30h      
    mov dl, al
    mov ah, 2
    int 21h

     
    mov ah, 4Ch
    int 21h
main endp
end main
