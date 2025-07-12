#include"header.h"
void main()
{
if(fork()==0)
{//child
printf("In c pid=%d\n",getpid());
sleep(30);
printf("In c after sleep...\n");
exit(1);
}
else
{//p
int r,s;
printf("In P before wait...\n");
r=wait(&s);
printf("In P after wait r=%d s=%d\n",r,s);
while(1);
}




}
