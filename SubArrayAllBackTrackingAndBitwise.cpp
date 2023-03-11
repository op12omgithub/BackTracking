#include<iostream>
#include<bitset>
#include<stdlib.h>
#include<math.h>
#include<vector>

using namespace std;
void allSubSet(int index,vector<int>&res,int arr[],int size)
{
    if(index==size){
        for(auto it:res)
        {
            cout<<it<<'\t';
        }
        cout<<endl;
        return;
    }
    //allSubSet(index+1,res,arr,size);
    res.push_back(arr[index]);
    allSubSet(index+1,res,arr,size);
    res.pop_back();
    allSubSet(index+1,res,arr,size);
}

int main()
{
    cout<<"welcome subarray"<<endl;
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>result;
    //using recursion
    cout<<"Result using Recursion"<<endl;
    allSubSet(0,result,arr,n);

    cout<<endl;
    int totalSize = 1<<n;
    int numOfBits = log2(totalSize);
    int count=0;
    cout<<"number of bits "<<numOfBits<<endl;
    for(int i=1;i<=totalSize;i++){
        for(int k=0;k<numOfBits;k++){
            if(i&(1<<k)){
                cout<<arr[k]<<" ";
            }
        }
        count++;
        cout<<endl;
    }
    cout<<"total number of subarray "<<count<<endl;
}
