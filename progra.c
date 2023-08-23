#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

void main()
{
    while(1)
        printf("%d infinity\n", getpid());
}