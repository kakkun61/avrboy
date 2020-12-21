NAME:=main

PORT:=/dev/cu.usbmodem14101

PROGRAMMER:=avrboy -P $(PORT) -b 9600 -p attiny10 -U

$(NAME).hex: $(NAME).c
	avr-gcc -I. -I. -g -mmcu=attiny10 -DF_CPU=1000000UL -Os -fno-tree-loop-ivcanon -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -Wstrict-prototypes -Wa,-ahlms=$(NAME).lst -c $(NAME).c -o $(NAME).o
	avr-gcc -Wl,-Map,$(NAME).out.map -mmcu=attiny10 -lm  -o $(NAME).out $(NAME).o 
	avr-objcopy -j .text \
	  -j .data \
	  -O ihex $(NAME).out $(NAME).hex
	avr-objcopy -j .eeprom \
	  --change-section-lma .eeprom=0 \
	  -O ihex $(NAME).out $(NAME).ee.hex

flash: $(NAME).hex
	$(PROGRAMMER) $(NAME).hex

clean:
	@ rm -f *.{lst,out,map,elf,hex,o}
