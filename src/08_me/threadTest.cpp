#include<iostream>
#include"thread.h"
#include<unistd.h>

using namespace std;


class threadTest : public Thread{
    
public:
    threadTest(int count) : count_(count){
        cout << "Thread()..." << endl;
        }
    ~threadTest(){
        cout << "~Thread()..." << endl;
    }
private:
    void Run(){
        while(--count_){
            cout << "this is a test" << endl;
            sleep(1);
        }
        
    }
    int count_;

};

int main(){
    // threadTest A(5);
    // A.Start();
    // A.Join();

    threadTest *B = new threadTest(5);
    B->SetAutoDelete(true);
    B->Start();
    B->Join();

    for(;;)
        pause();
    return 0;
}