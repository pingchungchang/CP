#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long> v;
    for(int i =0;i<n;i++){
        long k;
        cin>>k;
        v.push_back(k);
    }
    if(v[0]<0) v[0] = 0;
    if(v[1]<0)v[1] = v[0];
    for(int i =2;i<n;i++){
        if(v[i]<0){
            v[i] = max(v[i-1],v[i-2]);
        }
        else{
            v[i] = max(v[i-1],v[i-2]+v[i]);
        }
    }
    cout<<v[v.size()-1];
    return 0;
}
