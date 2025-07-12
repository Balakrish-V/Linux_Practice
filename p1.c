#include"header.h"
void convert(char*p)
{
	int i;
	for(i=0;p[i];i++)
		if(p[i]>='a' && p[i]<='z')
		p[i]=p[i]-32;

}
void main()
{
int p[2];

pipe(p);
perror("pipe");

printf("p[0]=Readend=%d\np[1]=writeend=%d\n",p[0],p[1]);

if(fork()==0)
{
	char s[10];
printf("In c before read...%d\n",getpid());
read(p[0],s,sizeof(s));
convert(s);
write(p[1],s,strlen(s)+1);
//printf("In c data=%s\n",s);

}
else
{
char s[10];
printf("In P enter the data...%d\n",getpid());
scanf("%s",s);
write(p[1],s,strlen(s)+1);
sleep(1);
read(p[0],s,sizeof(s));
printf("In parent s=%s\n",s);
}






}
