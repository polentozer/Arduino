#!/usr/bin/python3

# Mandatory imports
import serial
import time
import datetime as dt


# Defining writer function for logging values w/ time
def writer(fname, s):
    t = dt.datetime.now()
    data = str(t)[-15:] + ',' + s + '\n'
    with open(fname, 'a') as fout:
        fout.write(data)


# Setting port and baud
uno = '/dev/ttyACM0'
ser = serial.Serial(port=uno, baudrate=9600)

# Setting filename of .log file
exp_date = dt.date.today()
exp_time = time.strftime('%H-%M')
fname = str(exp_date) + '_' + str(exp_time) + '.log'

# Setting read/write loop + throw away first few lines
print('Python3.x logging script...')
n = 0
while n < 10:
    n += 1
    x = ser.readline()
    time.sleep(0.2)
else:
    # Setting logging duration (600 ~ 10 min)
    with open(fname, 'a') as fout:
        fout.write('TIME.MS,AN_READ,VOLTAGE,pH_VALUE\n')
    start = int(time.time())
    end = start + 120
    print('Start of logging: {}.'.format(time.strftime('%H:%M:%S')))
    while start < end:
        # Increment has to be the same as Arduino delay
        start += 0.2
        x = str(ser.readline()).replace('\\t', ',')
        writer(fname, x[2:-5])
    else:
        print('End of logging: {}.'.format(time.strftime('%H:%M:%S')))
