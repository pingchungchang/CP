#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    if(n%2 == 0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vector<int> v;
    for(int i = (n+1+n*2)/2;i<=n*2;i++){
        v.push_back(i);
    }
    for(int i = n+1;i<v[0];i++)v.push_back(i);
    int k = (n*3+3)/2;
    for(int i = 0;i<n;i++){
        cout<<v.back()<<' '<<k-v.back()<<'\n';
        v.pop_back();
        k++;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
/*
1 2 3 4 5 6 7 8 9 10

2n*(2n+1)/2 = (2k+n-1)*n/2;
4n+2 = 2k+n-1
k = (3n+3)/2
n = 5:k = 9
9 10 11 12 13

8 5
9 3
10 1
6 4
7 2

n = 7 k = 12
12 13 14 15 16 17 18

11
12
13
14
8
9
10
*/