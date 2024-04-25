#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pii arr[n];
    for(auto &i:arr)cin>>i.fs>>i.sc;
    set<pii> st;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(j == i)continue;
            pii dist = {arr[i].fs-arr[j].fs,arr[i].sc-arr[j].sc};
            if(dist.fs == 0)dist.sc /= abs(dist.sc);
            else if(dist.sc == 0)dist.fs /= abs(dist.fs);
            else{
                int G = __gcd(abs(dist.fs),abs(dist.sc));
                dist.sc /= G;
                dist.fs /= G;
            }
            // cout<<i<<' '<<j<<' '<<dist.fs<<','<<dist.sc<<endl;
            st.insert(dist);
        }
    }
    cout<<st.size();
    // cout<<endl;for(auto &i:st)cout<<i.fs<<','<<i.sc<<endl;  
}