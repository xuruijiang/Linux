#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
    pid_t id = fork(); //int

    if(id == 0)
    {
      
        cout << "I an child, PID: " << getpid() << " PPID: " << getppid() << endl;
        while(true)
        {
            cout << "I an child " << endl;
            sleep(2);
        }
    }
    else if(id > 0)
    {
        
        cout << "I an father, PID: " << getpid() << " PPID: " << getppid() << endl;
        int i = 10;
        while(i > 1)
        {
            cout << "I an father" << endl;
            sleep(1);
            i--;
        }
        //exit(1);
    }
    else{
      ;
    }
//    sleep(100);
//
    return 0;
}
