from turtle import screensize
from pyfirmata import*
import time
from tkinter import *

screen = Tk()
screen.title("24h de st jo")
screen.maxsize(500,500)
screen.minsize(500,500)


carte = Arduino("/dev/ttyUSB0")
acisition = util.Iterator(carte)
tension = carte.get_pin("a:0:i")
acisition.start()


    
Vtension = tension.read()
print(Vtension)
Vtension =str(Vtension)
labelValeur=Label(screen,text=Vtension).pack()



screen.mainloop()