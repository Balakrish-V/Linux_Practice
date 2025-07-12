#include"header.h"
void main()
{
int p[2],c=0;
char ch='a';
//pipe(p);
pipe2(p,O_NONBLOCK);
perror("pipe");

while(write(p[1],&ch,1)!=-1)
{
	c++;
}
	printf("c=%d\n",c);
printf("Bye...\n");

}
