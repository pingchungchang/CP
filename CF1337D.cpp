#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

inline ll sq(ll k){
	return k*k;
}
inline ll calc(ll a,ll b,ll c){
	return sq(a-b)+sq(b-c)+sq(a-c);
}

void solve(){
	ll cnt[3];
	for(auto &i:cnt)cin>>i;
	vector<pll> all;
	ll ans = 5e18;
	vector<ll> arr[3];
	for(int i = 0;i<3;i++){
		for(int j = 0;j<cnt[i];j++){
			int tmp;
			cin>>tmp;
			arr[i].push_back(tmp);
			all.push_back({tmp,i});
		}
	}
	for(auto &i:arr)sort(i.begin(),i.end());
	for(auto &i:all){
		//cout<<i.fs<<' '<<i.sc<<endl;
		vector<int> dif;
		for(int j = 0;j<3;j++){
			if(j != i.sc)dif.push_back(j);
		}
		int ta = dif[0],tb = dif[1];
		auto lit = upper_bound(arr[ta].begin(),arr[ta].end(),i.fs);
		auto rit = lower_bound(arr[tb].begin(),arr[tb].end(),i.fs);
		if(lit != arr[ta].begin()&&rit != arr[tb].end()){
			lit--;
			//cout<<i.fs<<' '<<i.sc<<":"<<*lit<<' '<<*rit<<endl;
			ans = min(ans,calc(*lit,*rit,i.fs));
		}
		lit = lower_bound(arr[ta].begin(),arr[ta].end(),i.fs);
		rit = upper_bound(arr[tb].begin(),arr[tb].end(),i.fs);
		if(lit != arr[ta].end()&&rit != arr[tb].begin()){
			rit--;
			//cout<<i.fs<<' '<<i.sc<<":"<<*lit<<' '<<*rit<<endl;
			ans = min(ans,calc(*lit,*rit,i.fs));
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
