#include<iostream>
using namespace std;

// Implement k queues using array
class kQueue{
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;

        kQueue(int n, int k){
            this->n = n;
            this->k = k;
            arr = new int[n];
            next = new int[n];
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++){
                front[i] = -1;
                rear[i] = -1;
            }
            freespot = 0;
        }

        void enqueue(int qn, int x){
            // check overflow
            if(freespot==-1){
                cout<<"Queue overflow"<<endl;
                return;
            }

            // find first free index
            int index = freespot;

            // update freespot
            freespot = next[index];

            // check weather first element or not
            if(front[qn-1]==-1){
                front[qn-1] = index;
            }
            else{
                // link new element to previous
                next[rear[qn-1]] = index; 
            }

            // update next
            next[index] = -1;

            // update rear
            rear[qn-1] = index;

            // push element
            arr[index] = x;
        }

        int dequeue(int qn){
            if(front[qn-1]==-1){
                cout<<"Queue underflow"<<endl;
                return -1;
            }

            int index = front[qn-1]; 
            front[qn-1] = next[index];
            next[index] = freespot;
            freespot = index;
            int elem = arr[index];
            arr[index] = -1;

            return elem;
        }

        void traverse(){
            for(int i=0; i<n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    int n,k;
    cin>>n>>k;
    kQueue kq(n, k);

    kq.enqueue(1, 5);
    kq.enqueue(1, 15);
    kq.enqueue(2, 17);
    kq.enqueue(2, 25);
    kq.enqueue(1, 35);
    cout<<kq.dequeue(1)<<endl;
    kq.traverse();
    return 0;
}