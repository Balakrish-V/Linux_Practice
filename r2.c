#include"header.h"
void main()
{
int a[5],i;
	close(0);
	open("DATA",O_RDONLY);

for(i=0;i<5;i++)
	scanf("%d",&a[i]);


for(i=0;i<5;i++)
	printf("%d ",a[i]);

	printf("\n");




}
