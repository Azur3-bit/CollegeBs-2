# server_datetime
import socket
from datetime import datetime
import datetime
print("modules have been imported without error might be working \n")
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("127.0.0.1",12345))
s.listen(5)
while True:
    cs , add = s.accept()
    print(f"server : connection from {add} has been estd. ")
    val = ""
    while(val != "exit"):
        msg = cs.recv(1024)
        print("client : " + msg.decode("utf-8"))
        if(msg.decode("utf-8") == "time"):
            val = str(datetime.datetime.now().time())
            cs.send(bytes(val,"utf-8"))
        elif(msg.decode("utf-8") == "date"):
            val = str(datetime.datetime.date())
            cs.send(bytes(val,"utf-8"))
        elif(msg.decode("utf-8") == "exit"):
            break
        else:
            val = "invalid req."
            cs.send(bytes(val,"utf-8"))
            