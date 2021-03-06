import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
pins = [24, 25, 8, 7, 12, 16, 20, 21]


def lightUp (ledNumber, period):
    pin =  pins [ledNumber]
    GPIO.setup (pin, GPIO.OUT)
    GPIO.output (pin, 1)
    time.sleep (period)
    GPIO.output (pin, 0)
    GPIO.cleanup (pin)
    

# lightUp (5, 1) 

def blink (ledNumber, blinkCount, blinkPeriod):
    pin =  pins [ledNumber]
    GPIO.setup (pin, GPIO.OUT)

    for i in range (blinkCount):
        GPIO.output (pin, 1)
        time.sleep (blinkPeriod)
        GPIO.output (pin, 0)
        time.sleep (blinkPeriod)
    GPIO.cleanup (pin)

# blink (4, 8, 1)

def runningLight (count, period):
    GPIO.setup (pins, GPIO.OUT)

    for i in range (count):
        GPIO.output (pins[i%8], 1)
        time.sleep (period)
        GPIO.output (pins[i%8], 0)
        GPIO.output (pins[(i + 1)%8], 1)
        time.sleep (period)
        GPIO.output (pins[(i + 1)%8], 0)
    GPIO.cleanup (pins)

# runningLight(20, 0.1)

def runningDark (count, period):
    GPIO.setup (pins, GPIO.OUT)

    for i in range (count):
        GPIO.output (pins[i%8], 0)
        time.sleep (period)
        GPIO.output (pins[i%8], 1)
        GPIO.output (pins[(i + 1)%8], 0)
        time.sleep (period)
        GPIO.output (pins[(i + 1)%8], 1)
    GPIO.cleanup (pins)

# runningDark(20, 0.1)

def decToBinList(decNumber):
    mass = [0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(8):
        if (decNumber % 2 == 1):
            mass[7-i] = 1
        decNumber //= 2
    return mass

print (decToBinList(219))

def lightNumber(number):
    GPIO.setup (pins, GPIO.OUT)
    mass = decToBinList(number)[::-1]
    GPIO.output(pins, mass)
    time.sleep(1)

lightNumber(0)

def runningPattern (pattern, direction):
    GPIO.setup (pins, GPIO.OUT)
    for i in range ()
    lightNumber(pattern)
    if direction == 0:
        first = pattern // 128
        pattern = pattern << 1
        pattern = (pattern % 256) + first 
    if direction == 1:
        last = pattern % 2
        pattern = pattern >> 1
        pattern = (pattern // 256) + (last * 128) 
    lightNumber(pattern)

runningPattern (3, 1)

def SHIM ()
  GPIO.setmode(GPIO.BOARD)
  GPIO.setup(12, GPIO.OUT)

  p = GPIO.PWM(12, 50)  
  p.start(0)
  try:
    while 1:
        for dc in range(0, 101, 5):
            p.ChangeDutyCycle(dc)
            time.sleep(0.1)
        for dc in range(100, -1, -5):
            p.ChangeDutyCycle(dc)
            time.sleep(0.1)
  except KeyboardInterrupt:
      pass
  p.stop()
  GPIO.cleanup()
SHIM()


import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
pins = [10, 9, 11, 5, 6, 13, 19, 26]


print("Введите число (-1 для выхода)")

value = int(input())
    

def num2dac(value):
    mass = [0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(8):
        if (value % 2 == 1):
            mass[7-i] = 1
        value //= 2
    return mass
def lightNumber(number):
    GPIO.setup (pins, GPIO.OUT)
    mass = num2dac(number)[::-1]
    GPIO.output(pins, mass)
    time.sleep(1)

lightNumber(value)


import numpy as np
import script1 as sc1

print ("Введите число повторений")

repetitionsNumber = int(input())

for i in range(repetitionsNumber):
    for j in range(256):
        sc1.num2dac(j)
        sc1.lightNumber(j)

    for j in range(255):
        sc1.num2dac(255 - j)
        sc1.lightNumber(255-j)
        
        import numpy as np
import matplotlib.pyplot as plt

print("Введите 3 числа (time, frequency, samplingFrequency)")

time = int(input())
frequency = int(input())
samplingFrequency = int(input())

X = np.arange(0, time, 1 / samplingFrequency)

ndarray = list(map(int, 127.5 * (np.sin(2 * np.pi * X * frequency) +1)))
plt.figure(figsize = (13, 13))

plt.plot(X, ndarray)

plt.savefig("/home/student/Desktop/New/graph.png")

print (X,ndarray)
