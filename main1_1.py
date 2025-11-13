from socket import *
from tkinter import *
from time import sleep
from threading import Thread
tk1=Tk()
tk1['bg']="white"
tk1.state("zoomed")
l1=Label(text="waiting for a connection",font=("",55))
l1.place(relx=0,rely=0,relwidth=1,relheight=1)
servar=socket(AF_INET,SOCK_STREAM)
ipv4=gethostbyname(gethostname())
servar.bind(('0.0.0.0',31425))
servar.listen()
client=None
def chckconcections():
    global client
    cla,cli=servar.accept()
    print(type(cla),type(cli))
    client=cla
    tk1.destroy()
th1=Thread(target=chckconcections)
th1.start()
tk1.mainloop()
tk=Tk()
tk['bg']='lightgreen'
tk.title("main cominucation app")
tk.state('zoomed')
tk.minsize(1600,800)
recvdltr='nothing until now'
def  reciving():
    global recvdltr
    while True:
        nau=client.recv(4096)
        recvdltr=nau.decode('utf-8')
th2=Thread(target=reciving)
th2.start()
awnsr=Label(tk,text=recvdltr,font=("",55),bg="white",fg="black")
awnsr.place(relx=0,rely=0.4,relwidth=1,relheight=0.2)
messg=Entry(tk,font=("",55),bg="white",fg="black",bd=4)
messg.place(relx=0,rely=0.6,relwidth=1,relheight=0.2)
def executee():
    while True:
        #print(recvdltr)
        awnsr['text']=recvdltr
        tk.update()
        sleep(1)
def send():
    na=messg.get()
    client.send(na.encode('utf-8'))
b1=Button(tk,font=("",55),bg="white",fg="black",bd=4,command=send,text="send")
b1.place(relx=0,rely=0.8,relwidth=1,relheight=0.2)
th3=Thread(target=executee)
th3.start()
tk.mainloop()

