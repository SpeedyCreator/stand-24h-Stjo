from tkinter import*

screen = Tk()
screen.title("test")
label1 = Label(screen)
label2 = Label(screen)
while True : 
    var1 = input ("Valeur 1: ") 
    var1 = str(var1)
    label1['text']= var1
    label1.pack()


