import os
import getmac

ip = ""
while ip != "exit":
    ip = input("Enter IP address to ping or type 'exit' to quit: ")
    if ip == "exit":
        continue
    os.system("ping{}".format(ip))  # Use '-n 1' to send only one ping request on Windows
    msg = input("Do you want to get the MAC address? (y/n): ")
    if msg == "n":
        continue
    mac = getmac.get_mac_address(ip=ip)
    print("MAC address: {}".format(mac))
print("Exiting")
