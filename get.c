#include"header.h"
void main(int argc,char **argv)
{
int id;
if(argc!=2)
{
printf("Usage:./get semnum\n");
return;
}


id=semget(3,5,IPC_CREAT|0664);

if(id<0)
{
perror("semget");
return;
}
printf("id=%d\n",id);

int r=semctl(id,atoi(argv[1]),GETVAL);
if(r<0)
{
perror("semctl");
return;
}

printf("r=%d\n",r);

}
