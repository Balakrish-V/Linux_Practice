#include"header.h"
void main()
{
int newfd;
newfd=dup(1);

printf("new fd=%d\n",newfd);
write(newfd,"abcdef\n",7);



}
