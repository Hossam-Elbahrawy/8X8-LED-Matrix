 
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o run.o *.c
avr-gcc -mmcu=atmega328p run.o -o run
avr-objcopy -O ihex -R .eeprom run run.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:run.hex
 
