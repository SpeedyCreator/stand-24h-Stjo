import serial
from tkinter import*

screen =Tk()
screen.title("test")
screen.maxsize(500,500)
screen.minsize(500,500)

#label

#var
def nettoie(Liste):
    data = []
    for i in range(len(Liste)):
        temp=Liste[i][2:]
        data.append(temp[:-5])
    return data
def reception():
    arduino=serial.Serial("/dev/ttyUSB0",timeout=1)
    rawdata = []
    cleandata = []
    rawdata.append(str(arduino.readline()))
    cleandata = nettoie(rawdata)
    LabelVal = Label(text=cleandata).pack()
    print(cleandata)
    print(rawdata)
    rawdata = []
    cleandata = []

reception()



screen.mainloop()