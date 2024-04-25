#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#define ll __int128_t
const ld PI = acos(-1);
int main(){
	io
	int n;
	cin>>n;
	if(n<=1000){
		pll v[n];
		for(int i = 0;i<n;i++){
			int a,b;
			cin>>a>>b;
			v[i] = {a,b};
		}
		ll total = 0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				total += (v[i].fs-v[j].fs)*(v[i].fs-v[j].fs)+(v[i].sc-v[j].sc)*(v[i].sc-v[j].sc);
			}
		}
		cout<<fixed<<setprecision(10)<<(ld)total/4*PI;
		return 0;
	}
	ll xx = 0,x = 0,yy = 0,y = 0;
	ll total = 0;
	pll arr[n];
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		arr[i].fs = a,arr[i].sc = b;
		xx += arr[i].fs*arr[i].fs;
		x += arr[i].fs;		
		yy += arr[i].sc*arr[i].sc;
		x += arr[i].sc;
	}
	for(auto &i:arr){
		total += xx+i.fs*i.fs*n-2*i.fs*x;
		total += yy+i.sc*i.sc*n-2*i.sc*y;
	}
	ld ans = (ld)total;
	ans/=4;
	cout<<fixed<<setprecision(10)<<ans*PI;
}

