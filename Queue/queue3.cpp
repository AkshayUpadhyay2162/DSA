#include <iostream>
#include <deque>
using namespace std;

// Sum of minimum and maximum elements of all subarrays of size k
int MaxMinSum(int *arr, int k, int n){
    deque<int> maxi(k);
    deque<int> mini(k);
    for(int i=0; i<k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);    
    }

    int sum = 0;
    sum += arr[maxi.front()] + arr[mini.front()];

    for(int i=k; i<n; i++){
        // process next windows

        // removal
        while(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }

        while(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }

        // addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

        sum += arr[maxi.front()] + arr[mini.front()];
    }

    return sum;
}

int main(){
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k;
    cin>>k;

    cout<<MaxMinSum(arr, k, 7)<<" ";
    return 0;
}