import socket
s= socket.socket()
host= socket.gethostname()
port=65235
s.connect(('127.0.0.1', port))
print("Connected.")
sentence = input(">>")
s.send(sentecne.encode())
filename=input(str("Enter incoming file name:"))
file=open(filename, 'a')
file_data=s.recv(1024)
file.write("\n")
file.write(file_data.decode("utf-8"))
file.close()
print("File received successfully.")


