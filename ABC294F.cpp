#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 5e4+10;
ll n,m;
ll k;
pll arr[mxn],brr[mxn];

ll f(ld kk){
    vector<ld> ta,tb;
    for(int i = 0;i<n;i++)ta.push_back(100*arr[i].fs-kk*arr[i].sc);
    for(int i = 0;i<m;i++)tb.push_back(100*brr[i].fs-kk*brr[i].sc);
    sort(ta.begin(),ta.end());
    sort(tb.rbegin(),tb.rend());
    ll re = 0;
    ll p = 0;
    for(int i = 0;i<n;i++){
        while(p<m&&ta[i]+tb[p]>=0)p++;
        re += p;
    }
    return re;
}
int main(){
    cin>>n>>m>>k;
    for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc,arr[i].sc += arr[i].fs;
    for(int i =0;i<m;i++)cin>>brr[i].fs>>brr[i].sc,brr[i].sc += brr[i].fs;
    ld l = 0,r = 1e9;
    for(int i = 0;i<100;i++){
        ld mid = (l+r)/2;
        if(f(mid)>=k)l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(10)<<l;
}

/*
100*(x1+x2)/(y1+y2) >= N
100x1+100x2 >= N*(y1+y2)
100x1+100x2-N*y1-N*y2>=0
*/
