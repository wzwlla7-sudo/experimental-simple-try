from time import sleep
import json 
def encryp(text):
    lu=[]
    toe1=open("toen1.txt","w")
    for axu in text:
        lu.append(ord(axu))
        toe1.write(str(ord(axu))+"\n")
    toe1.close()
    sleep(0.15)
    dc=open('encrted1.txt','r')
    aj=((dc.read()).replace("\n"," ")).split()
    naud=json.dumps(aj).encode()
    return naud
def decryp(lisn):
    lis=json.loads(lisn.decode())
    tod1=open('todec.txt','w')
    for axu in lis:
        tod1.write(str(axu)+'\n')
    tod1.close()
    sleep(0.15)
    dect=open('dected.txt','r')
    anu=(dect.read().replace("\n"," ").split())
    resu=""
    for altr in anu:
        resu=resu+chr(int(altr))
    return resu