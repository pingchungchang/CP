#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld double
#define _all(T) T.begin(),T.end()
#define cd complex<ld>
#pragma GCC optimize("O3")
const ld PI = acos(-1);
 
const int mxn = 1<<19;
vector<cd> A(mxn,0),B(mxn,0);
bitset<mxn> done;
 
cd ei(ld theta){
	return cd(cos(theta),sin(theta));
}
void FFT(vector<cd> &f,int inv){
	done.reset();
	int n = f.size();
	int b = 0,k = n;
	while(k != 0){
		k>>=1;
		b++;
	}
	b--;
	for(int i = 0;i<n;i++){
		if(done[i])continue;
		int re = 0,tmp = i;
		for(int j = 0;j<b;j++){
			re<<=1;
			if(tmp&1)re ^=1;
			tmp>>=1;
		}
		done[re] = done[i] = true;
		swap(f[i],f[re]);
	}
	
	for(int step = 1;step<n;step<<=1){
		for(int i = 0;i<n;i+= step<<1){
			ld theta = inv*PI/step;
			cd w = ei(theta);
			cd now = 1;
			for(int j = 0;j<step;j++,now *= w){
				auto a = f[i+j],b = f[i+j+step]*now;
				f[i+j] = a+b;
				f[i+j+step] = a-b;
			}
		}
	}
	if(inv == -1){
		for(auto &i:f)i/=n;
	}
	return;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        A[i] = k;
    }
    for(int i = m-1;i>=0;i--){
        int k;
        cin>>k;
        B[i] = k;
    }
    FFT(A,1);
    FFT(B,1);
    for(int i = 0;i<mxn;i++)A[i] *= B[i];
    FFT(A,-1);
    for(int i = 0;i<n+m-1;i++)cout<<(int)(round(A[i].real()))<<' ';
    return 0;
}
 