//Checker part
#include <stdio.h>
int main()
{
	printf("Hello World");
	return 0;
}

#include "unp.h"

int main(int argc, char **argv)
{
   int sockfd, n;
   char recvline[MAXLINE + 1];
   struct sockaddr_in servaddr; 

   if (argc != 2)
      err_quit("usage: a.out <IPaddress>");

   if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
      err_sys("Socket Error");

   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(13); /*DayTime Server*/
   if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
      err_quit("Inet_pton error for %s", argv[1]);

   if (connect (sockfd, (SA *) &servaddr, sizeof(servadrr)) <0)
      err_sys("Connect Error");

   while ( (n = read(sockfd, recvline, MAXLINE)) >0)
   {
      recvline[n] = 0; /*null terminate*/
      if (fputs(recvline, stdout) == EOF)
         err_sys("fputs Error");
      
   }
   if (n < 0)
      err_sys("read error");
   
   exit(0);

} 
