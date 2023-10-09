# server Full Duplex


import socket 
import threading
import sys
def recv_from_client(conn):
    global FLAG
    try:
        while True:
            if FLAG  == True:
                break
            messsage = conn.recv(1024).decode()
            if messsage == 'quit':
                conn.send('quit'.encode())
                conn.close()
                print("connection Closed !")
                FLAG = True
                break
            print('client : '+messsage)
    except:
        conn.close()
def send_to_client(conn):
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
    serverSocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    serverSocket.bind((HOST,serverPort))
    print("socket binded !")
    serverSocket.listen(1)
    print("listening ... ")
    connectionSocket, addr = serverSocket.accept()
    print("connection established wiht the client on addr : ",addr,"\n")
    t_rev = threading.Thread(target=recv_from_client,args = (connectionSocket,))
    t_send = threading.Thread(target=send_to_client,args = (connectionSocket,))
    threads.append(t_rev)
    threads.append(t_send)
    t_rev.start()
    t_send.start()
    t_rev.join()
    t_send.join()
    print("EXITING !")
    serverSocket.close()
    sys.exit()
if __name__ == "__main__":
    main()
    
                   
                