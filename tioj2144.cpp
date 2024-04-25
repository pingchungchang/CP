#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 6e6+10;
int lpf[mxn];

inline int calc(int k,int c){
	int l = 0,r = mxn;
	while(l != r){
		int mid =(l+r)>>1;
		ll tp = k;
		int ts = 0;
		while(tp<=mid)ts += mid/tp,tp *= k;
		if(ts>=c)r = mid;
		else l = mid+1;
	}
	return l;
}

void solve(){
	int n;
	cin>>n;
	if(n<=1){
		cout<<"0\n";
		return;
	}
	vector<pii> v;
	while(n != 1){
		if(v.empty()||v.back().fs != lpf[n])v.push_back({lpf[n],1});
		else v.back().sc++;
		n/=lpf[n];
	}
	int ans = 0;
	for(auto &i:v){
		ans = max(ans,calc(i.fs,i.sc));
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	lpf[0] = lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
