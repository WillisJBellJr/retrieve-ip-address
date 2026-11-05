#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
        struct addrinfo hints, *res, *p;
        int status;
        char ipstr[INET_ADDRSTRLEN];
        if(argc != 2) {
                char buf[150];
                fprintf(stderr, "INVALID: input hostname\n");
                fprintf(stderr,"Input site: ");
                scanf("%149s", buf);
                argv[1] = buf;
        }
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        if((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
                fprintf(stderr,"getaddrinfo: %s\n", gai_strerror(status));
                return 2;
        }
        for(p = res; p!=NULL; p = p->ai_next) {
                void *addr;
                struct sockaddr_in *ipv4;
                ipv4 = (struct sockaddr_in *)p->ai_addr;
                addr = &(ipv4->sin_addr);
                inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
                fprintf(stdout, "IPv4: %s\n", ipstr);
        }
        freeaddrinfo(res);

        return 0;
}