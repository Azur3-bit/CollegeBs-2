import socket

# Create a socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to an address and port
host = "127.0.0.1"  # Use the correct server IP address
port = 55004  # Use the same port as in the client
s.bind((host, port))

# Listen for incoming connections
s.listen(1)

print(f"Server is listening on {host}:{port}")

# Accept a connection
client_socket, client_address = s.accept()
print(f"Accepted connection from {client_address}")

# Send a message to the client
message = "Hello from the server!"
client_socket.send(message.encode())

# Close the server socket
s.close()
