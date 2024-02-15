#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int p,int q){
    int x=a[p];
    int i=p;
    for(int j=p+1;j<=q;j++){
        if(a[j]<=x){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i],&a[p]);
    return i;
}
void quicksort(int a[],int p,int q){
    if(p<q){
        int m=partition(a,p,q);
        quicksort(a,p,m-1);
        quicksort(a,m+1,q);
    }
}
int main(){
    int a[]={23,43,5,22,87,44,1};
    int p=0;
    int q=6;
    quicksort(a,p,q);
    for(int b=0;b<7;b++){
        cout<<a[b]<<" ";
    }
    return 0;
}