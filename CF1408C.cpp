#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define ld long double

const ld eps = 1e-6;
const int mxn = 1e5+10;
int arr[mxn];
int n,len;

ld cl(ld tar){
	ld v = 1,pos = 0;
	int pt = 0;
	ld re = 0;
	while(pt<n&&arr[pt]<=tar){
		re += (arr[pt]-pos)/v;
		v+=1;
		pos = arr[pt];
		pt++;
	}
	re += (tar-pos)/v;
	return re;
}
ld cr(ld tar){
	ld v = 1,pos = len;
	int pt = n-1;
	ld re = 0;
	while(pt>=0&&arr[pt]>=tar){
		re += (pos-arr[pt])/v;
		v += 1;
		pos = arr[pt];
		pt--;
	}
	re += (pos-tar)/v;
	return re;
}

void solve(){
	cin>>n>>len;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	ld l = 0.0,r = len;
	for(int i = 0;i<60*6;i++){
		ld mid = (l+r)/2;
		if(cl(mid)>=cr(mid))r = mid;
		else l = mid;
	}
	/*
	cout<<l<<' '<<r<<":";
	cout<<cl(l)<<' '<<cr(l)<<',';

   */
	cout<<fixed<<setprecision(20)<<cl(r)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
