import socket

buffer = input("domain name: ")
ip = socket.gethostbyname(buffer)
print(ip)
with open("ip4addr.txt", "a") as file:
        file.write("ip4 address for " + str(buffer) + " is " + str(ip) + "\n")