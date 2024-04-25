#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define pdd pair<double,double>
int n;
double w,vel;
vector<pdd> v;

bool f(int x){
	double k = (double)x;
	pdd now = make_pair(v[0].fs,v[0].fs+w);
	for(int i = 1;i<n;i++){
		double time = (v[i].sc-v[i-1].sc)/k;
		pdd ran = make_pair(now.fs-time*vel,now.sc+time*vel);
		if(ran.sc<v[i].fs||ran.fs>v[i].fs+w){
			return false;
		}
		now.fs = max(v[i].fs,ran.fs);
		now.sc = min(v[i].fs+w,ran.sc);
	}
	return true;
}
void solve(){
	cin>>w;
	cin>>vel;
	cin>>n;
	v = vector<pdd>(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].fs>>v[i].sc;
	}
	int l = 0;
	int r = 1e6+7;
	while(l != r){
		int mid = (l+r+1)/2;
		if(f(mid)){
			l = mid;
		}
		else r = mid-1;
	}

	int s;
	cin>>s;
	int ans = -1;
	for(int i = 0;i<s;i++){
		int k;
		cin>>k;
		if(k<=r)ans = max(k,ans);
	}
	if(ans == -1)cout<<"IMPOSSIBLE\n";
	else cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

