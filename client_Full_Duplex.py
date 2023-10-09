# write the client program for the above server
# Path: client_Full_Duplex.py
# client Full Duplex

import socket
import threading
import sys
def recv_from_server(conn):
    global FLAG
    try:
        while True:
            if FLAG == True:
                break
            messsage = conn.recv(1024).decode()
            if messsage == 'quit':
                conn.send('quit'.encode())
                conn.close()
                print("connection Closed !")
                FLAG = True
                break
            print('server : '+messsage)
    except:
        conn.close()
def send_to_server(conn):
    global FLAG
    try:
        while True:
            if FLAG == True:
                break
            send_msg = input("")
            if send_msg == 'quit':
                conn.send('quit'.encode())
                conn.close()
                print("connection Closed !")
                FLAG = True
                break
            conn.send(send_msg.encode())
    except:
        conn.close()
        
def main():
    threads = []
    global FLAG
    HOST = 'localhost'
    serverPort = 6500
    clientSocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    clientSocket.connect((HOST,serverPort))
    print("connection established wiht the server on addr : ",(HOST,serverPort),"\n")
    t_rev = threading.Thread(target=recv_from_server,args = (clientSocket,))
    t_send = threading.Thread(target=send_to_server,args = (clientSocket,))
    threads.append(t_rev)
    threads.append(t_send)
    t_rev.start()
    t_send.start()
    t_rev.join()
    t_send.join()
    print("EXITING !")
    clientSocket.close()
    sys.exit()
if __name__ == "__main__":
    main()
    