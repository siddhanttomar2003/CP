// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int buildTree(int i, int l, int r, vector<int> & v,vector<int> &Seg_tree){
 if(l==r){
   Seg_tree[i]=v[l];
   return Seg_tree[i];
 }
 int mid=(l+r)/2;
 int build_left=buildTree(2*i+1,l,mid,v,Seg_tree);
 int build_right=buildTree(2*i+2,mid+1,r,v,Seg_tree);
 Seg_tree[i]=build_left+build_right;
 return Seg_tree[i];
}

int main()
{
vector<int>Seg_tree(10,0);
 vector<int>temp={4,2,3,1,6};
 buildTree(0,0,4,temp,Seg_tree);
 for(int i=0;i<10;i++){
    cout<<Seg_tree[i]<<" ";
 }
 cout<<endl;
return 0;
}