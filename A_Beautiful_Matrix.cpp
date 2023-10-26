#include<iostream>
#include<vector>
using namespace std;


int main()
{
int a[5][5];
int posi=-1;
int posj=-1;
for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++){
        cin>>a[i][j];
        if(a[i][j]==1){
            posi=i;
            posj=j;
        }

    }
}
cout<<abs(posi-3+1)+abs(posj-3+1);
return 0;
}