#include <stdio.h>
#include <winsock2.h>


int main(int argc, char *argv[]){
    if (argc < 1){
        printf("This Takes 1 Arrgument 0 given Example: ./gethostbyname_example.exe www.google.com");
        return 1;
    }

    WSADATA wsa;
    WSAStartup(MAKEWORD(2,0), &wsa);

    struct hostent *hosts;
    struct in_addr *address;

    hosts = gethostbyname(argv[1]);
    address = (struct in_addr *) (hosts->h_addr);

    printf("%s\n", inet_ntoa(*address));
}