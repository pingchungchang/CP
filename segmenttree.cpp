#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void build(int s, int e,vector<int> &v,vector<int> &segtree,int root){
    if(s == e){
        segtree[root] = v[s];
    }
    else if(s == e-1){
        segtree[2*root+1] = v[s];
        segtree[2*root+2] = v[e];
        segtree[root] = v[s]+v[e];
    }
    else{
        int mid = s+e;
        mid = mid/2;
        build(s,mid,v,segtree,2*root+1);
        build(mid+1,e,v,segtree,2*root+2);
        segtree[root] = segtree[2*root+1]+segtree[2*root+2];
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    vector<int> segtree(4*n,-1);
    build(0,v.size()-1,v,segtree,0);
    for(int i = 0;i<segtree.size();i++){
        cout<<segtree[i]<<' ';
    }
}
