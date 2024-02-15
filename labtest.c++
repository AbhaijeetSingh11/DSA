#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int p,int q,int arr[]){
    int x=arr[p];
    int i=p;
    for(int j=p+1;j<=q;j++){
        if(arr[j]>=x){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i],&arr[p]);
    return i;
}
void quicksort(int arr[],int p,int q){
    if(p<q){
        int m=partition(p,q,arr);
        quicksort(arr,p,m-1);
        quicksort(arr,m+1,q);
    }
}
int main(){
    int arr[]={2,8,1,11,3};
    quicksort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}