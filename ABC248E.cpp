#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
ll cross(pll a,pll b){
    return a.fs*b.sc-b.fs*a.sc;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> times(303,0LL);
    vector<pll> pt(n);
    for(int i = 0;i<n;i++){
        cin>>pt[i].fs>>pt[i].sc;
    }
    if(k == 1){
        cout<<"Infinity";
        return 0;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(j == i)continue;
            pll a = pt[i];
            pll b = pt[j];
            int v = 2;
            for(int m = 0;m<n;m++){
                if(m == i||m == j)continue;
                pll c = pt[m];
                pll d1 = make_pair(c.fs-a.fs,c.sc-a.sc);
                pll d2 = make_pair(c.fs-b.fs,c.sc-b.sc);
                if(cross(d1,d2) == 0){
                    v++;
                }
            }
            times[v]+=1;
        }
    }
    ll ans = 0;
    for(int i = k;i<=n;i++){
        ans += times[i]/(i*(i-1));
    }
    cout<<ans;
}
