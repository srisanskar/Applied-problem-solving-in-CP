#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    deque<int> dq;
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }

    while(n>0){
        int rotate_steps=k%n;
        for(int i=0;i<rotate_steps;i++){
            int front=dq.front();
            dq.pop_front();
            dq.push_back(front);
        }

        cout<<dq.front()<<" ";
        dq.pop_front();
        n--;
    }
    cout<<"\n";
}
