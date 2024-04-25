#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    set<int> st[m];
    for(auto &i:st){
        int c;
        cin>>c;
        while(c--){
            int k;
            cin>>k;
            i.insert(k);
        }
    }
    int ans = 0;
    for(int i = 0;i<(1<<m);i++){
        set<int> ss;
        for(int j = 0;j<m;j++){
            if(i&(1<<j)){
                for(auto &k:st[j])ss.insert(k);
            }
        }
        bool flag = true;
        for(int j = 1;j<=n;j++){
            if(ss.find(j) == ss.end())flag = false;
        }
        ans += flag;
    }
    cout<<ans;
}