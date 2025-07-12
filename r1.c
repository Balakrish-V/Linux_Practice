#include"header.h"
void main()
{
int fd;
	close(1);
	fd=open("DATA",O_WRONLY|O_TRUNC|O_CREAT,0664);

		if(fd<0)
		{
		perror("open");
		return;
		}
int a[5]={10,20,30,40,50},i;

for(i=0;i<5;i++)
	printf("%d ",a[i]);
//printf("Hello World fd=%d\n",fd);


}
