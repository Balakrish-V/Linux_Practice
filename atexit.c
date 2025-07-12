#include"header.h"
void abc(void)
{
	while(1)
printf("In abc...");
}
void main()
{

printf("Hello...");
atexit(abc);
atexit(def);
printf("Hai...");
sleep(10);
printf("Bye...");
_exit(0);

}
