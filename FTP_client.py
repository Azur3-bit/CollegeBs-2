import socket
s=socket.socket()
host=socket.gethostname()
port=65235
s.connect((host, port))
print("Connected.")
sentence input(">>")
s.send(sentence.encode())
filename= input(str("Enter incoming file name:"))
file=open(filename, 'a')

file_data=s.recv(1024)
file.write("\n")
file.write(file_data.decode("utf-8"))
file.close()
print("File received successfully.")
s.close(
