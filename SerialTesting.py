import array
import time
import math

import busio

uart = busio.UART(board.TX, board.RX, baudrate=115200)

myChar = 'a'

While True:
    uart.write(bytes(myChar))

    print(uart.read())

    time.sleep(1)
