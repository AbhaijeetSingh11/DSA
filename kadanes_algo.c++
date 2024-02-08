#include<iostream>
#include<vector>
using namespace std;
int kadane(vector<int>& array){
    int max_current=array[0];
    int max_global=array[0];
    for(int i=1;i<array.size();i++){
        max_current=max(array[i],max_current+array[i]);
        max_global=max(max_global,max_current);
    }
    return max_global;
}
int main(){
    vector<int> array={-2,-3,4,-1,-2,1,5,-3};
    int maxsum=kadane(array);
    cout<<"Maximum sum of subarray:"<<maxsum<<endl;
    return 0;
}