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


# Setting port
uno = '/dev/cu.usbmodem1431'
ser = serial.Serial(port=uno, baudrate=9600)

# Setting filename of .log file
exp_date = dt.date.today()
exp_time = time.strftime('%H:%M')
fname = str(exp_date) + '-' + str(exp_time) + '.log'

# Setting experiment duration
start = int(time.time())
end = start + 100

# Wait a sec then print and throw away first line; likely incomplete
time.sleep(1)
print(ser.readline())

# Setting read/write loop
while start < end:
    start += 1
    x = str(ser.readline()).replace('\\t', ',')
    # print(x[2:-5])
    writer(fname, x[2:-5])
