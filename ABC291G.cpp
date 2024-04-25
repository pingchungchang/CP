#include <bits/stdc++.h>
using namespace std;

#define cd complex<double>
#define dd double
#define ll long long
#define ld long double
const ld PI = acos(-1);
inline cd ei(ld theta){return cd(cos(theta),sin(theta));}
const int bits = 21;
ll cnt[5];
const ll mxn = 1LL<<bits;
ll A[mxn];
cd arr[5][mxn],brr[5][mxn];
void FFT(cd a[],int inv){
    for(int i = 0;i<mxn;i++){
        int tmp = i,re = 0;
        for(int j = 0;j<bits;j++){
            re<<=1;
            if(tmp&1)re ^= 1;
            tmp>>=1;
        }
        if(re>i)swap(a[re],a[i]);
    }

    for(int i = 1;i<mxn;i<<=1){
        for(int j = 0;j<mxn;j+=i*2){
            cd w = ei(inv*PI/i);
            cd now = 1;
            for(int k = 0;k<i;k++){
                cd ta = a[k+j],tb = a[k+j+i];
                a[j+k] = ta+tb*now;
                a[j+k+i] = ta-tb*now;
                now *= w;
            }
        }
    }
    if(inv == -1)for(int i = 0;i<mxn;i++)a[i]/=mxn;
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(int i = 0;i<n*2;i++){
        ll k;
        if(i<n)cin>>k;
      	else k = A[i-n];
      	A[i] = k;
        for(int j = 0;j<5;j++){
            if((1<<j)&k){
            	arr[j][i] = 1;
              	if(i<n)cnt[j]++;
            }
        }
    }
    for(int i = n-1;i>=0;i--){
        ll k;
        cin>>k;
        for(int j = 0;j<5;j++){
            if((1<<j)&k){
              brr[j][i] = 1;
              cnt[j]++;
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<n;j++){
            // cout<<i<<' '<<j<<':'<<brr[i][j].real()<<endl;
        }
    }
    for(int i = 0;i<5;i++){
        FFT(arr[i],1);
        FFT(brr[i],1);
        for(int j = 0;j<mxn;j++){
            arr[i][j] *= brr[i][j];
        }
        FFT(arr[i],-1);
    }
    for(int i = n-1;i<=n*2-2;i++){
        ll total = 0;
        for(int j = 0;j<5;j++){
          	// cout<<i<<","<<j<<":"<<arr[j][i].real()<<endl;
            total += (cnt[j]-(ll)round(arr[j][i].real()))*(1LL<<j);
        }
    //   cout<<i<<":"<<total<<endl;
        ans = max(ans,total);
    }
    cout<<ans;
}