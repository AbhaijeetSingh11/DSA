#include<iostream>
using namespace std;

void merge(int arr[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;

    int leftarray[n1],rightarray[n2];

    for(int i=0;i<n1;i++){
        leftarray[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        rightarray[j]=arr[mid+1+j];
    }

    i=0,j=0,k=left;
    while((i<n1) && (j<n2)){
        if(leftarray[i]<=rightarray[j]){
            arr[k]=leftarray[i];
            i++;
        }
        else{
            arr[k]=rightarray[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=leftarray[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=rightarray[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int begin,int end){
    if(begin>=end){
        return;
    }
    else{
        int mid = begin + (end-begin)/2;
        mergesort(arr,begin,mid);
        mergesort(arr,mid+1,end);
        merge(arr,begin,mid,end);
    }
}

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={12,3,4,6,43,7,1,98,0};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    printarray(arr,arr_size);
    mergesort(arr,0,arr_size-1);
    printarray(arr,arr_size);
    return 0;
}