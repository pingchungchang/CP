#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    vector<vector<string>> v(a.size(),vector<string>(b.size(),""));
    if(a[0] == b[0]){
        v[0][0]  = a[0];
    }
    for(int i = 1;i<a.size();i++){
        if(v[i-1][0].size() == 1){
            v[i][0] = v[i-1][0];
        }
        else if(a[i] == b[0])v[i][0]+=a[i];
    }
    for(int i = 1;i<b.size();i++){
        if(v[0][i-1].size()==1)v[0][i] = v[0][i-1];
        else if(a[0] == b[i]) v[0][i] += a[0];
    }
    for(int i = 1;i<a.size();i++){
        for(int j = 1;j<b.size();j++){
            if(v[i-1][j].size()>v[i][j-1].size())v[i][j] = v[i-1][j];
            else v[i][j] = v[i][j-1];
            if(a[i] == b[j]&&v[i-1][j-1].size()+1>v[i][j].size()) v[i][j] = v[i-1][j-1]+a[i];
        }
    }
    if(v[v.size()-1][v[0].size()-1].size()==0) cout<<"E";
    else cout<<v[v.size()-1][v[0].size()-1];
}
