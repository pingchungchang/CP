#include <bits/stdc++.h>
using namespace std;



int f(int a,int b){
    int dif = a-b;
    if(dif == 0)return 0;
    if(dif == 1)return 1;
    if(dif == 2)return 1;
    return dif-1;
}
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int>eq;
    for(int i = 0;i<n;i++)cin>>v[i];
    for(int i = 1;i<n;i++){
        if(v[i] == v[i-1])eq.push_back(i);
    }
    if(eq.size() != 0)cout<<f(*eq.rbegin(),*eq.begin())<<'\n';
    else cout<<0<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i =0;i<t;i++)solve();
}
