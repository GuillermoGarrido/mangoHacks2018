import serial
import time

ArduinoSerial = serial.Serial('com5', 9600)
time.sleep(2)

while 1:
    incoming = str(ArduinoSerial.readline())  # read the serial data and print it as line
    print incoming

    if 'Play/Pause' in incoming:
        pyautogui.typewrite(['space'], 0.2)

    if 'Rewind' in incoming:
        pyautogui.hotkey('ctrl', 'left')

    if 'Forward' in incoming:
        pyautogui.hotkey('ctrl', 'right')

    if 'V up' in incoming:
        pyautogui.hotkey('ctrl', 'down')

    if 'V down' in incoming:
        pyautogui.hotkey('ctrl', 'up')

    incoming = "";
