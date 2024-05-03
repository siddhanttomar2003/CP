#include<iostream>
using namespace std;


int main()
{
int arr[5]={3,5,4,2,1};
for(int i=0;i<5;i++){
    if(arr[i]!=i+1){
        swap(arr[arr[i]-1],arr[i]);
        i--;
    }
}
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}