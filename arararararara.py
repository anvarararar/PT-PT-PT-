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

# def runningPattern (pattern, direction):
#     GPIO.setup (pins, GPIO.OUT)
#     for i in range ()
#     lightNumber(pattern)
#     if direction == 0:
#         pattern = pattern << 1
#     if direction == 1:
#         pattern = pattern >> 1
#     lightNumber(pattern)

# runningPattern (3, 1)

