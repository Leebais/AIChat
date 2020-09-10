#include <iostream>
#include <thread>
using namespace std;
void thread_1()
{
    cout << "hello from thread_1" << endl;
}
int main(int argc, char **argv)
{
    thread t1(thread_1);
    /**
    join()相当于调用了两个函数：WaitForSingleObject、CloseHandle，事实上，在vc12中也是这么实现的
    */
    t1.join();
    return 0;
}