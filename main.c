#include <msp430.h> 

char message[12]="Hello world";
unsigned int position;

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5; //enable gpios
	UCA3CTLW0 |= UCSWRST;
	/*
	 * UCOS16 = 0
	 * UCABRW = 8 --PRESCALER
	 * UCA3MCTLW = UCBRSx | UCBRFx | UCOS16
	 * */
	UCA3CTLW0 |= UCSSEL__SMCLK; //BRCLK = ACLK
	UCA3BRW =6 ; //PRESCALAR
	UCA3MCTLW |= 0x2081 ;
	P6SEL1 &= ~BIT0 |BIT1;
	P6SEL0 |= BIT0 | BIT1;
	UCA3CTLW0 &= ~UCSWRST;

	// Ports
	P5DIR &= ~BIT6;
	P5REN |= BIT6;
	P5OUT |= BIT6;
	P5IES |= BIT6;
	P5IE |= BIT6;
	P5IFG &= ~BIT6;
	__enable_interrupt();

	for(;;){
	}

}

#pragma vector = PORT5_VECTOR
__interrupt void ISR_PORT5_S1(void){
    position = 0;
    UCA3IE|= UCTXCPTIE;
    UCA3IFG &= ~UCTXCPTIFG;
    UCA3TXBUF= message[position];
    P5IFG &= ~BIT6;
    }


#pragma vector = EUSCI_A3_VECTOR
__interrupt void ISR_EUSCI_A3(void){
    if(position == sizeof(message)){
       UCA3IE &= ~UCTXCPTIE;
    }else{
        position++;
        UCA3TXBUF = message[position];
    }
    UCA3IFG &= ~UCTXCPTIFG;

}
