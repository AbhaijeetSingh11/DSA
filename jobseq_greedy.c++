#include<iostream>
using namespace std;
int inputdata(int deadline[],int profit[]){
    int job;
    cout<<"enter no of jobs you want to input:";
    cin>>job;
    for(int i=0;i<job;i++){
        cout<<"enter deadline for job["<<i+1<<"]";
        cin>>deadline[i];
        cout<<"enter profit for job["<<i+1<<"]";
        cin>>profit[i];
    }
    return job;
}
int maxdata(int profit[],int jobs){
    int max=0;
    for(int i=0;i<jobs;i++){
        if(profit[i]>max){
            max=profit[i];
        }
    }
    return max;
}
void printarray(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<' ';
    }
}
int main(){
    int deadline[100]={};
    int profit[100]={};
    int jobs=inputdata(deadline,profit);
    int max=maxdata(deadline,jobs);
    int array[max]={};
    printarray(array,max);
    return 0;
}