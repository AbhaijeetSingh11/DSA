#include<iostream>
using namespace std;
                                       //  quicksort starts here
void swap(float *a,float *b){
    float t=*a;
    *a=*b;
    *b=t;
}
int partition(float a[],int p,int q,float profit[],float weight[]){
    float x=a[p];
    int i=p;
    for(int j=p+1;j<=q;j++){
        if(a[j]<=x){
            i++;
            swap(&a[i],&a[j]);
            swap(&profit[i],&profit[j]);
            swap(&weight[i],&weight[j]);
        }
    }
    swap(&a[i],&a[p]);
    swap(&profit[i],&profit[p]);
    swap(&weight[i],&weight[p]);
    return i;
}
void quicksort(float a[],int p,int q,float profit[],float weight[]){
    if(p<q){
        int m=partition(a,p,q,profit,weight);
        quicksort(a,p,m-1,profit,weight);
        quicksort(a,m+1,q,profit,weight);
    }
}
                                 // ends quicksort

void print(float a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<",";
    }
}
float greedy_knapsack(float profit[],float weight[],int size){
    float ratio[100]={};
    for(int i=0;i<size;i++){
        ratio[i]=(profit[i]/weight[i]);
    }
    print(ratio,size); 
    cout<<endl<<"profit array:"<<endl;
    print(profit,size);
    cout<<endl<<"weight array:"<<endl;
    print(weight,size);
    cout<<endl;

             // calling quicksort
    quicksort(ratio,0,size-1,profit,weight);


    cout<<"printting after quicksort "<<endl;
    print(ratio,size);
    cout<<endl<<"profit array:"<<endl;
    print(profit,size);
    cout<<endl<<"weight array:"<<endl;
    print(weight,size);
    cout<<endl;
    int m=20;
    int count;
    float finalprofit=0;
    for(int i=size-1;i>=0;i--){
        if(m>0 && weight[i]<=m){
            m=m-weight[i];
            finalprofit=finalprofit+profit[i];
            count=i;
        }
        else{
            break;
        }
    }
    if(m>0){
        finalprofit=float(finalprofit)+(float(profit[count])*float(m/weight[count]));
    }
    return finalprofit;
}

int main(){
    float profit[100]={};
    float weight[100]={};
   
    int size;
    cout<<"enter no. of inputs :";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"enter profit of object["<<i+1<<"]";
        cin>>profit[i];
        cout<<"enter weight of object["<<i+1<<"]";
        cin>>weight[i];
    }
    cout<<greedy_knapsack(profit,weight,size);
    return 0;
}