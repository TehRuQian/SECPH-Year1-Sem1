TITLE Project COA
; Group member:
; 1. Goe Jie Ying
; 2. Pok Lok Yee
; 3. Teh Ru Qian
; 4. Woo Cheng Shuan
; Date: 23 June 2024

include Irvine32.inc

.data
	msgWelcome BYTE "Welcome to CPU Benchmark Program", 0dh, 0ah, 0
	msgAlgorithm BYTE "Benchmark CPU time Using Equation y = (17*x^3) + (22*x^2) + (21*x) + 23", 0ah, 0dh
				 BYTE "(with delay coef1, coef2, coef3, coef4 = 17, 22, 21, 23 msec)", 0dh, 0ah, 0
	msgEnterN BYTE "Enter Number of Looping (N) = ", 0
	msgProgress BYTE "CPU time Stress Test in progress...", 0dh, 0ah, 0
	msgResult BYTE "Result: ", 0dh, 0ah, 0
	msgFirstCapture BYTE "First Capture Execution time in millisecond: ", 0
	msgSecondCapture BYTE "Second Capture Execution time in millisecond: ", 0
	msgDiffTime BYTE "Different Execution time in millisecond: ", 0
	msgSum BYTE "Value of Sum from the Stress Test (polynomial) = ", 0
	msgPrompt BYTE "Press 'y' to continue or 'n' to exit the benchmark: ", 0
	msgBye BYTE "Thank you ... BYE!!", 0dh, 0ah, 0

	coef1 DWORD 17; a = 17
	coef2 DWORD 22; b = 22
	coef3 DWORD 21; c = 21 
	coef4 DWORD 23; d = 23

	max_loop DWORD ?
	sum WORD ?
	capture_msec_before DWORD ?
	capture_msec_after DWORD ?
	elapsed_time DWORD ?

.code
	main PROC
	; Display welcome message
	call clrscr
	mov edx, offset msgWelcome
	call WriteString
	call crlf

	; Display the algorithm
	mov edx, offset msgAlgorithm
	call WriteString
	call crlf

	; Prompt for max loop value
	mov edx, offset msgEnterN
	call WriteString
	call ReadDec
	mov max_loop, eax

	; Display progress message
	mov edx, offset msgProgress
	call WriteString
	call crlf

	; Capture time before starting the loop
	call GetMseconds
	mov capture_msec_before, eax

	; Initialize sum to 0
	mov sum, 0

	; Set loop counter
	mov ecx, max_loop
	mov ebx, 1

	calc_loop:
	; Calculate y = (coef1 * x ^ 3) + (coef2 * x ^ 2) + (coef3 * x) + coef4
	; coef1* x ^ 3
	mov eax, coef1
	call Delay
	mul bx
	mul bx
	mul bx
	mov dx, ax					 ; Store in dx for adding later

	; coef2* x ^ 2
	mov eax, coef2
	call Delay
	mul bx
	mul bx
	add dx, ax					  ; add previous result

	; coef3* x
	mov eax, coef3
	call Delay
	mul bx
	add dx, ax						; add previous result

	;coef4
	mov eax, coef4
	call Delay
	add dx, ax						; add coef4

	; Add y to sum
	add sum, dx

	; Increment loop counter
	inc ebx
	loop calc_loop

	; Capture time after completing the loop
	call GetMseconds
	mov capture_msec_after, eax

	; Calculate elapsed time
	mov eax, capture_msec_after
	sub eax, capture_msec_before
	mov elapsed_time, eax

	; Display results
	mov edx, offset msgResult
	call WriteString
	call crlf

	mov edx, offset msgFirstCapture
	call WriteString
	mov eax, capture_msec_before
	call WriteDec
	call crlf

	mov edx, offset msgSecondCapture
	call WriteString
	mov eax, capture_msec_after
	call WriteDec
	call crlf

	mov edx, offset msgDiffTime
	call WriteString
	mov eax, elapsed_time
	call WriteDec
	call crlf

	mov edx, offset msgSum
	call WriteString
	mov ax, sum
	call WriteDec
	call crlf

	; Prompt to continue pr exit
	mov edx, offset msgPrompt
	call WriteString
	call ReadChar

	cmp al, 'y'
	je main
	
	call crlf
	mov edx, offset msgBye
	call WriteString

;Exit program
exit
	
	main ENDP

END main
