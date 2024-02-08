#include<iostream>
using namespace std;
class jobs{
    int date[5];
    int profit[5];
    public:
    void dateinput(void){
        int n;
        cout<<"enter the no of entries:"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"enter data of objects:"<<i;
            cin>>date[i];
            cout<<"enter profit of objects:"<<i;
            cin>>profit[i];
        }
    }
};
int main(){
    //grsgrsznftahtrnaetnraeahr
    return 0;
}