#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> c(n,1);
    vector<int> v;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    for(int i =1;i<v.size();i++){
        if(v[i]>v[i-1]){
            c[i] = c[i-1]+1;
        }
    }
    for(int i = v.size()-2;i>=0;i--){
        if(v[i]>v[i+1]){
            c[i] = max(c[i],c[i+1]+1);
        }
    }
    long long ans = 0;
    for(int i =0;i<v.size();i++){
        ans += c[i];
    }
    cout<<ans;
    return 0;
}

//strange! fail in cmd but success in hackerrank;





