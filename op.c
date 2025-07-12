#include"header.h"
void main(int argc,char **argv)
{
int id;
if(argc!=2)
{
printf("Usage:./op semop\n");
return;
}


id=semget(3,5,IPC_CREAT|0664);

if(id<0)
{
perror("semget");
return;
}
printf("id=%d\n",id);
struct sembuf v;
v.sem_num=2;
v.sem_op=atoi(argv[1]);
v.sem_flg=SEM_UNDO;
printf("Before...\n");
semop(id,&v,1);
printf("After...\n");
sleep(20);
printf("Done...\n");

}








