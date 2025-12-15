.model small
.stack 100h

.data
msgBin db 13,10,'Binary: $'
msgDec db 13,10,'Decimal: $'
msgHex db 13,10,'Hex: $'

num1   dw ?
num2   dw ?
result dw ?

.code
main:
    mov ax, @data
    mov ds, ax

    ; PSP command line starts at 81h
    mov si, 81h

    call ReadNumber
    mov num1, ax

    call SkipSpace
    call ReadNumber
    mov num2, ax

    call SkipSpace
    lodsb              ; operation
