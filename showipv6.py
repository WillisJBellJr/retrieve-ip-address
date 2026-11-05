import socket

buffer = input("domain name: ")
try:
        info = socket.getaddrinfo(buffer, None, family=socket.AF_INET6, proto=socket.IPPROTO_TCP)
        print(f"ipv6 addresses for {buffer}")
        for i in info:
                ip = i[4][0]
                print(ip)
        with open("ip6addr.txt", "a") as file:
                file.write("ip address for " + str(buffer) + " is " + str(ip) + "\n")

except socket.gaierror:
        print(f"no ip6 address found for {buffer}")