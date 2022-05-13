#include<iostream>
using namespace std;
int majorityElement(int arr[], int n){
    int index=0;
    int count=1;
    
    for(int i=1; i<n; i++){
        if(arr[index] == arr[i]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            index=i;
            count=1;
        }
    }
    int count2=0;
    for(int j=0; j<n; j++){
        if(arr[j]==arr[index]){
            count2++;
        }
    }
    if(count2 > n/2){
        return arr[index];
    }
    else{
        return -1;
    }
}
int main(){
    int arr[5]={2,5,7,2,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<< majorityElement(arr,n);
}