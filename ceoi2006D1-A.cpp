#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define dd double
#define pld pair<ld,ld>
#define fs first
#define sc second
 
 
const ld PI = acos(-1);
const int mxn = 505;
pld arr[mxn];
int n,k;
pld cen;
 
int cross(pld &a,pld &b){
    return a.fs*b.sc-a.sc*b.fs>=0?1:-1;
}
 
ld dist(pld &a,pld &b){
    return sqrt((a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc));
}
 
bool cmp(pair<pld,int> &a,pair<pld,int> &b){
    if(a.fs.sc == 0)return true;
    if(b.fs.sc == 0)return false;
    return atan2(a.fs.fs,a.fs.sc)<atan2(b.fs.fs,b.fs.sc);
    // return cross(a.fs,b.fs)<=0;
}
 
bool check(ld R){
    for(int i = 0;i<n;i++){
        vector<pair<ld,int>> v;
        for(int j = 0;j<n;j++){
            if(i == j)continue;
            ld len = dist(arr[i],arr[j]);
            if(R*2<len)continue;
            ld theta = acos(len/2/R);
            ld t0 = atan2(arr[j].sc-arr[i].sc,arr[j].fs-arr[i].fs);
            v.push_back({t0-theta,j+1});
            v.push_back({t0+theta,-j-1});
        }
        sort(v.begin(),v.end());
        int s = v.size();
        for(int j = 0;j<s;j++)v.push_back(v[j]);
        int cnt = 1;
        for(auto &j:v){
            cnt+= j.sc>0?1:-1;
            if(cnt>=k){
                cen = {arr[i].fs+R*cos(j.fs),arr[i].sc+R*sin(j.fs)};
                return true;
            }
        }
    }
    return false;
}
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
    ld l = 0,r = 1e4;
    int enu = 32;
    while(enu--){
        ld mid = (l+r)/2;
        if(check(mid))r = mid;
        else l = mid;
    }
    cout<<fixed<<setprecision(10)<<l<<'\n'<<cen.fs<<' '<<cen.sc;
}
/*
4 3 
2 2 
6 2 
6 5 
2 8 
 
*/
