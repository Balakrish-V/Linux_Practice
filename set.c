#include"header.h"
void main(int argc,char **argv)
{
int id;
if(argc!=3)
{
printf("Usage:./set semnum val\n");
return;
}


id=semget(3,5,IPC_CREAT|0664);

if(id<0)
{
perror("semget");
return;
}
printf("id=%d\n",id);

semctl(id,atoi(argv[1]),SETVAL,atoi(argv[2]));
perror("semctl");


}
