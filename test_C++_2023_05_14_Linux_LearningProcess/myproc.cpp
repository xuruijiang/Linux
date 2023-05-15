#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
    fork();

    cout << "hello proc: " << getpid() << "hello parent: " << getppid() << endl;
    sleep(1);
    return 0;
}
