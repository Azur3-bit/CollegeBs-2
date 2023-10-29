import socket

# Create a socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
host = "127.0.0.1"  # Use the correct server IP address
port = 55004  # Use the same port as in the server
s.connect((host, port))

# Receive data from the server
data = s.recv(1024)
print(f"Received: {data.decode()}")

# Close the client socket
s.close()
