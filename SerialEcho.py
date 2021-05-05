# SerialEcho.py

import supervisor
import board
import busio
import digitalio


uart = busio.UART(board.TX, board.RX, baudrate=9600)
print("listening...")

while True:
    if supervisor.runtime.serial_bytes_available:
        value = input().strip()
        # Sometimes Windows sends an extra (or missing) newline - ignore them
        if value == "":
            continue
        print("RX: {}".format(value))
        # uart.write(.format(value))