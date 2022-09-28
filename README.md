
	What is the address of your main() function, and what is the size in bytes of your delay() function?  [+1 point]
0000071c  - start address of the main function
40- delay size in bytes


	Show the full disassembly of your delay() function, adding comments to each line to explain the functionality.  [+4 points]
0000065c <Call_Delay>:                  // DELAY FUNCTION 
     65c:	b580      	push	{r7, lr}        // push to stack r7 register the value in lr
     65e:	b082      	sub	sp, #8            // subtract from the stack pointer 8bit (1 byte) 
     660:	af00      	add	r7, sp, #0        // store addition of stack pointer value  and 0 in register 7 
     662:	6078      	str	r0, [r7, #4]    // value found at r0 stored in address r7 + 4
     664:	e003      	b.n	66e <Call_Delay+0x12>
     666:	4b07      	ldr	r3, [pc, #28]	; (684 <Call_Delay+0x28>)  // loads address to r3 found at program counter at offest 28
     668:	0018      	movs	r0, r3        // mov r3 to r0
     66a:	f002 fd34 	bl	30d6 <Delay>
     66e:	687b      	ldr	r3, [r7, #4]      //load in register r3 , 4 being offset
     670:	1e5a      	subs	r2, r3, #1      // r2= r3-#1
     672:	607a      	str	r2, [r7, #4]      // value found at r0 stored in address r7 + 4
     674:	2b00      	cmp	r3, #0        // compares r3 with 0
     676:	d1f6      	bne.n	666 <Call_Delay+0xa>
     678:	46c0      	nop			; (mov r8, r8)    // nop
     67a:	46c0      	nop			; (mov r8, r8)  //nop 
     67c:	46bd      	mov	sp, r7      // stiore r7 value in stack pointer
     67e:	b002      	add	sp, #8      // add a byte in stack pointer 
     680:	bd80      	pop	{r7, pc}      // this pops r7 from program counter
     682:	46c0      	nop			; (mov r8, r8)    // no operation
     684:	000186a0 	.word	0x000186a0

     
     /* Code of Vapa8623 reviewed by me */


1. Comments can be more descriptive
2. Magic numbers are used in the code
3. Difficult readiability, need logic descitption
4. Need modularity to make the code compact
5. redundandt and not required functionns present (Basically need to clean up the code)
6. Delay not working properly
7. Functionality is proper
8. Required output is obtained
9.  Had separate files for RUN and DEBUG, need to merge it to one
10. ESE Code guidelines violations present (minor) like ddescription of files, etc
