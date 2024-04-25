#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v;
    int n;
    while(cin>>n){
        v.push_back(INT_MAX);
        for(int i = 0;i<v.size();i++){
            if(v[i]>=n){
                int k = v[i];
                v[i] = n;
                n = k;
            }
        }
        if(v.size()%2 == 1){
            cout<<v[v.size()/2];
        }
        else{
            cout<<(v[v.size()/2-1]+v[v.size()/2])/2;
        }
        cout<<endl;
    }
}
