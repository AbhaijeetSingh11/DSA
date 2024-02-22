#include<iostream>
using namespace std;
void swap(int *one,int *two){
    int temp=*one;
    *one=*two;
    *two=temp;
}
int partition(int array[],int starting_index,int ending_index,int s[],int p[]){
    int pivot=array[starting_index];
    int i=starting_index;
    for(int j=starting_index+1;j<=ending_index;j++){
        if(array[j]<=pivot){
            i++;
            swap(&array[i],&array[j]);
            swap(&s[i],&s[j]);
            swap(&p[i],&p[j]);
        }
    }
    swap(&array[i],&array[starting_index]);
    swap(&s[i],&s[starting_index]);
    swap(&p[i],&p[starting_index]);
    return i;
}
void quicksort(int array[],int starting_index,int ending_index,int s[],int p[]){
    if(starting_index<ending_index){
        int midindex=partition(array,starting_index,ending_index,s,p);
        quicksort(array,starting_index,midindex-1,s,p);
        quicksort(array,midindex+1,ending_index,s,p);
    }
}
void activity(int starttime[],int finishtime[],int answer[],int work[],int size){
    int count=0;
    for(int i=0;i<size;){
        for(int j=0;j<size;j++){
            if(starttime[i]>=finishtime[j]){
                answer[count]=work[i];
                i=j;
                count++;
                break;
            }
        }
    }
}
int main(){
    int work[]={1,2,3,4,5,6,7,8};
    int starttime[]={1,0,1,4,2,5,3,4};
    int finishtime[]={3,4,2,6,9,8,5,5};
    int answer[]={};
    int size=sizeof(starttime)/sizeof(int);
    quicksort(finishtime,0,7,starttime,work);

    cout<<endl<<"printing work array:"<<endl;
    for(int j=0;j<=7;j++){
        cout<<work[j]<<" ";
    }
    cout<<endl<<"printing finishtime array:"<<endl;
    for(int i=0;i<=7;i++){
        cout<<finishtime[i]<<" ";
    }
    cout<<endl<<"printing starttime array:"<<endl;
    for(int j=0;j<=7;j++){
        cout<<starttime[j]<<" ";
    }
    // activity(starttime,finishtime,answer,work,size);
    // cout<<endl<<"printing answer-array:"<<endl;
    // for(int k=0;k<=7;k++){
    //     cout<<answer[k]<<" ";
    // }
    return 0;
}