#include <avr/io.h>
#include <util/delay.h>
#include "alphabet.h"
int main(){
	
	int  letter_index=0,i=0,j=0,k=0;
	
	DDRC=0xff; 					// All pins of PortC as output
	DDRB=0xff;					// All pins of PortB as output
	DDRD=0xff;					// All pins of PortD as output
	
	while(1){
		
		for(letter_index=0;letter_index<26;letter_index++){
			for(i=0;i<200;i++){
				
				for(j=0;j<4;j++){
					PORTB =(1<<j);
					PORTD =~alphabet[letter_index][j];
					_delay_us(500);
				}
				PORTB=0x00;
				
				for(k=0;k<4;k++){
					PORTC =(1<<k);
					PORTD =~alphabet[letter_index][4+k];
					_delay_us(500);
				}
				PORTC=0x00;						
			}
				
		}		
				_delay_ms(120);	
				_delay_ms(120);
                _delay_ms(120);
	}

return 0;
}