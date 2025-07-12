#include"header.h"
struct msgbuf
{
long int mtype;//>0
char data[10];
};
void main(int argc,char **argv)
{
	if(argc!=2)
	{
	printf("Usage:./rcv mtype \n");
	printf("Ex:./rcv 2 \n");
	return;
	}

int id;
	id=msgget(4,IPC_CREAT|0664);


if(id<0)
{
perror("msgget");
return;
}
printf("id=%d\n",id);
///////////////////////////////////////////////////////////////////

struct msgbuf v;
printf("Before...\n");

msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
printf("After data=%s\n",v.data);






}
