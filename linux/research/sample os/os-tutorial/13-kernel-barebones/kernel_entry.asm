[BITS 32]
[global start]
[extern main]

SECTION .text
start: 
        cli
	    call _begin
	    jmp $
_begin:
