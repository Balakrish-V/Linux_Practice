#include"header.h"
void main()
{

int fd;

fd=open("DATA",O_WRONLY|O_APPEND|O_CREAT,0664);

if(fd<0)
{
perror("open");
return;
}
char ch;
struct flock v;
v.l_type=F_WRLCK;
v.l_whence=SEEK_SET;
v.l_start=0;
v.l_len=0;
printf("Before...\n");
fcntl(fd,F_SETLKW ,&v);
printf("After...\n");

for(ch='A';ch<='Z';ch++)
{
write(fd,&ch,1);
sleep(1);
}

printf("Done...\n");

v.l_type=F_UNLCK;

fcntl(fd,F_SETLK ,&v);


}
