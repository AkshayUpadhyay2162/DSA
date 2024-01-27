// Using STL Queue library 
#include<iostream>
#include<queue>
using namespace std;

int main(){
    // Usage of queue using STL
    queue<int> q;
    q.push(10);
    q.push(13);
    q.push(14);
    q.push(17);
    cout<<"Before pop operation:"<<endl;
    cout<<"Size of queue is: "<<q.size()<<endl;
    cout<<"Element at front: "<<q.front()<<endl;
    cout<<"Element at back: "<<q.back()<<endl;
    q.pop();
    cout<<"After pop operation:"<<endl;
    cout<<"Size of queue is: "<<q.size()<<endl;
    cout<<"Element at front: "<<q.front()<<endl;
    cout<<"Element at back: "<<q.back()<<endl;
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    return 0;
}