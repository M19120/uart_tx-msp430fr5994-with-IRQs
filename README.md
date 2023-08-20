# uart_tx-msp430fr5994-with-IRQs


https://github.com/M19120/uart_tx-msp430fr5994-with-IRQs/assets/77844733/e5b5dab6-de90-4838-a8d3-25631a4cdea6

# UART COMMUNICATION 
In msp430, UART (Universal Asynchronous Receiver Transmitter) is one of the most used device-to-device communication protocols.
Communication protocol plays a big role in organizing communication between devices. It is designed in different ways based on system requirements,
and these protocols have a specific rule agreed upon between devices to achieve successful communication.

Inside msp430, exists a user guide, in this user guide you can see the baud rate, and you can config in differents ways and manners. The msp430fr5994
contains 1 eUSCI register that you can use to connect devices among them. Inside this repository, you can use UCA3TX to transmitt a char to the terminal 
inside Code Composer Studio, it was used Interrupts or IRQs to have a fast response, scalabilty and take care about rare events. 

As support it was used a usb to TTL serial converter (CH340), its setup consists in 5 pins: RX,TX,VCC,GND,5V and 3.3V

![CONVERTIDOR_USB_A_TTL_CH340_C5-removebg-preview-min](https://github.com/M19120/uart_tx-msp430fr5994-with-IRQs/assets/77844733/0d201dd6-02e1-4a22-a45d-25448911ffd8)

