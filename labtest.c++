#include<iostream>
using namespace std;
void swap(int *one,int *two){
    int temp=*one;
    *one=*two;
    *two=temp;
}
int partition(int array[],int starting_index,int ending_index){
    int pivot=array[starting_index];
    int i=starting_index;
    for(int j=starting_index+1;j<=ending_index;j++){
        if(array[j]<=pivot){
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i],&array[starting_index]);
    return i;
}
void quicksort(int array[],int starting_index,int ending_index){
    if(starting_index<ending_index){
        int midindex=partition(array,starting_index,ending_index);
        quicksort(array,starting_index,midindex-1);
        quicksort(array,midindex+1,ending_index);
    }
}
void printarray(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<' ';
    }
}
int input(int array[]){
    int size;
    cout<<"enter no. of elements you want to insert:";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"enter your["<<i<<"] element:";
        cin>>array[i];
    }
    return size;
}
int main(){
    int array[100]={};
    int size=input(array);
    printarray(array,size);
    quicksort(array,0,size-1);
    cout<<endl;
    printarray(array,size);
    return 0;
}