TITLE Lab3 Part2C
; Author: Teh Ru Qian & Goe Jie Ying
; Date: 17 June 2024

include Irvine32.inc


.data
	message1 BYTE "Welcome to Simple Math Activities : ", 0dh, 0ah, 0dh, 0ah
	BYTE "Main Menu :", 0dh, 0ah, 0dh, 0ah
	BYTE "1. To calculate Perimeter Hexagon (Loop and ADD instructions)", 0dh, 0ah
	BYTE "2. To calculate SUM (unsign int) index [Odd or Even] in an Array Hello [6]", 0dh, 0ah, 0
	message2 BYTE "Select Your Input : ", 0
	inputOption DWORD ?
	promptBad BYTE "Invalid Input, please enter again", 0

	message3 BYTE "Calculate Perimeter 2-Hexagon (LOOP and ADD instructions) : ", 0dh, 0ah, 0dh, 0ah
	BYTE "Input Hexagon 1 (side length) : ", 0
	message3_1 BYTE "Input Hexagon 2 (side length) : ", 0

	sideHex1 DWORD ?
	sideHex2 DWORD ?

	message4 BYTE "Result of Perimeter Hexagon 1 and 2: ", 0dh, 0ah, 0
	Perimeter_hexagon1 dword ?
	Perimeter_hexagon2 dword ?

	message4_1 BYTE "Total Perimeter Hexagon 1 and 2: ", 0
	totalPerimeter dword ?

	message5 BYTE "Calculate SUM (unsign INT) index (Odd or Even) in array Hello[6] : ", 0dh, 0ah, 0
	stringNo BYTE "Input INT (unsign) : ", 0
	hello dword 6 dup(0h)

	int_message BYTE "Integer Input : ", 0

	sum_odd dword ?
	sum_even dword ?

	str_result_hello BYTE "Result Sum Hello[index] : ", 0dh, 0ah, 0
	str_result_odd BYTE "Sum Hello[odd] index location : ", 0
	str_result_even BYTE "Sum Hello[even] index location : ", 0

	stryn BYTE "Press 'y' to Main Menu or 'n' to Exit the benchmark : ", 0
	charIn BYTE ?
	charY dword "y"
	strbye BYTE "Thank you ... BYE!!", 0dh, 0ah, 0

.code

	main proc

	startProg :

		call clrscr							; clear screen
		mov edx, offset message1			; reg edx store address of message1
		call WriteString					; print message1
		call crlf							; end line

		mov edx, offset message2			; reg edx store address of message2
		call WriteString					; print message2 

	; read input Main Menu
	read_inOption :
		call ReadDec						; read user input
		jnc  goodInOption					; jump if not carry CF = 0 (means it is valid decimal number)

		mov edx, offset promptBad			; reg edx store address of promptBad
		call WriteString					; print promptBad
		jmp  read_inOption					; go input again

	goodInOption :
		mov inputOption, eax				; store user input in decNumInOption

		call crlf							; end line

		mov ebx, 1							; initial ebx with 1
		mov eax, inputOption				; store user input in eax
		cmp eax, ebx						; compare user input in eax with ebx
		je periHex_loopAdd					; jump to periHex_loopAdd, if they are equal (=1)

		mov ebx, 2							; initial ebx with 2
		mov eax, inputOption				; store user input in eax
		cmp eax, ebx						; compare user input in eax with ebx
		je calSum_oddeven					; jump to calSum_oddeven, if they are equal (=2)

	periHex_loopAdd :
		call clrscr							; clear screen
		mov edx, offset message3			; reg edx store address of message3
		call WriteString					; print message3

	read_inOptionHex1:
		call ReadDec						; read user input
		jnc  goodInOptionHex1				; jump if not carry CF = 0 (means it is valid decimal number)

		mov edx, offset promptBad			; reg edx store address of promptBad
		call WriteString					; print promptBad
		jmp read_inOptionHex1				; go input again

	goodInOptionHex1 :
		mov sideHex1, eax				; store user input in decNumInHex1

	; read input Hex2(side_length)
	mov edx, offset message3_1				; reg edx store message3_1
	call WriteString						; print message3_1

	read_inOptionHex2 :
		call ReadDec						; read user input
		jnc goodInOptionHex2				; jump if not carry CF = 0 (means it is valid decimal number)

		mov edx, offset promptBad			; reg edx store promptBad
		call WriteString					; print promptBad
		jmp read_inOptionHex2				; go input again

	goodInOptionHex2 :
		mov sideHex2, eax				; store good value
		call crlf							; end line

		mov ecx, 6							; initial counter loop with 6
		mov eax, 0							; initial eax with 0
		mov ebx, 0							; initial ebx with 0

	loopAddHex:
		add eax, sideHex1				; add decNumInHex1 to eax
		add ebx, sideHex2				; add decNumInHex2 to ebx
		loop loopAddHex

		mov Perimeter_hexagon1, eax
		mov Perimeter_hexagon2, ebx

	; Calculate sum of both perimeter
	mov eax, Perimeter_hexagon1
	mov ebx, Perimeter_hexagon2
	add eax, ebx							; add sumHex1and sumHex2
	mov totalPerimeter, eax					; store result in totalPerimeter

	mov edx, offset message4				; reg edx store messsge4
	call WriteString						; print message4
	mov eax, Perimeter_hexagon1
	call WriteDec							; print sumHex1
	call crlf
	mov eax, Perimeter_hexagon2
	call WriteDec							; print sumHex2
	call crlf
	call crlf

	mov edx, offset message4_1
	call WriteString						; print message4_1
	mov eax, totalPerimeter
	call WriteDec							; print totalPerimeter
	call crlf

	mov edx, offset stryn
	call WriteString						; print stryn

	call ReadChar							; read user input
	mov charIn, AL							; move user input into charIn

	call WriteChar							; print user input

	call crlf
	call crlf

	mov EBX, charY
	cmp BL, charIn							; compare 'y' with user input

	JE startProg							; jump to startProg if equal

	mov edx, offset strbye
	call WriteString						; print strbye


	calSum_oddeven :
		call clrscr
		mov edx, offset message5
		call WriteString					; print message5

		call crlf

	; read 6 integer no.
	mov ecx, 6								; initial counter loop with 6
	mov ebx, 0

	loopL1:
		read_inOption2:
			mov edx, offset int_message
			call WriteString				; print int_message
			call ReadDec					; read user input
			jnc goodInOption2				; jump if not carry CF = 0 (means it is valid decimal number)
			mov edx, offset promptBad
			call WriteString				; print promptBad
			jmp read_inOption2				; go input again

		goodInOption2 :

			mov hello[ebx], eax				; store the read value at index[ebx]

			mov eax, hello[ebx]				; move the stored value back into eax
			add ebx, 4						; increment ebx to point to the next dword(4 bytes)
		loop loopL1

	call crlf
	call crlf

	; calculate hello[] even location
	mov ecx, 3								; initial counter loop with 3
	mov ebx, 0
	mov eax, 0
	loopL2:
		add eax, hello[ebx]					; add the value at hello[ebx] to eax
		add ebx, 8							; move to the next even index(0, 8, 16 in bytes, corresponds to indices 0, 2, 4)
	loop loopL2
	mov sum_even, eax						; store final sum in sum_even

	; calculate hello[] odd location
	mov ecx, 3								; initial counter loop with 3
	mov ebx, 4
	mov eax, 0

	loopL3:
		add eax, hello[ebx]					; add the value at hello[ebx] to eax
		add ebx, 8							; move to the next odd index(4, 12, 20 in bytes, corresponds to indices 1, 3, 5)
	loop loopL3
	mov sum_odd, eax						; store final sum in sum_odd

	; output result sum evenand odd hello[]
	mov edx, offset str_result_hello
	call WriteString
	call crlf
	mov edx, offset str_result_even
	call WriteString
	mov eax, sum_even
	call WriteDec
	call crlf

	mov edx, offset str_result_odd
	call WriteString
	mov eax, sum_odd
	call WriteDec
	call crlf
	call crlf

	mov edx, offset stryn
	call WriteString

	call ReadChar							; read user input
	mov charIn, AL							; move user input into charIn

	call WriteChar

	call crlf
	call crlf

	mov EBX, charY
	cmp BL, charIn							; compare 'y' with user input

	JE startProg							; jump if equal

	mov edx, offset strbye
	call WriteString

	exit

		main ENDP

	END main
