#include"header.h"
void main()
{
int id,fd;
///////////////////////////////////////
id=semget(3,5,IPC_CREAT|0664);
if(id<0)
{
perror("semget");
return;
}

////////////////////////////////////////////

fd=open("DATA",O_WRONLY|O_APPEND|O_CREAT,0664);
	if(fd<0)
	{
		perror("open");
		return;
	}

///////////////////////////////////////////////
struct sembuf v;
char ch;
v.sem_num=3;
v.sem_op=0;
v.sem_flg=0;
printf("Before...\n");
printf("After.....\n");
for(ch='A';ch<='Z';ch++)
{
semop(id,&v,1);
semctl(id,2,SETVAL,1);
write(fd,&ch,1);
semctl(id,3,SETVAL,1);
semctl(id,2,SETVAL,0);
}
printf("Done...\n");





}
