#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        vector<int> v(n+1,0);
        for(int i = 1;i<=n;i++){
            int k;
            cin>>k;
            v[i] = v[i-1]+k;
        }
        for(int i = 0;i<m;i++){
            int a,b;
            cin>>a>>b;
            cout<<v[b]-v[a-1]<<endl;
        }
    }
}
