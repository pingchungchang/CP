#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<int> all;
const int inf = 1e9+10;

inline bool inter(pii a,pii b){
	if(a.fs == b.fs||a.sc == b.sc)return true;
	if(a.fs>b.fs)swap(a,b);
	if(b.fs<=a.sc)return true;
	else return false;
}

void solve(){
	ll n;
	cin>>n;
	vector<pii> v;
	for(int i = 0;i<n;i++){
		pii tmp;
		cin>>tmp.fs>>tmp.sc>>tmp.sc>>tmp.sc;
		swap(tmp.fs,tmp.sc);
		v.push_back(tmp);
	}
	sort(v.rbegin(),v.rend());
	vector<pii> stk;
	for(auto &i:v){
		swap(i.fs,i.sc);
		if(stk.empty()){
			stk.push_back(i);
			continue;
		}
		if(inter(stk.back(),i)){
			stk.back().fs = min(stk.back().fs,i.fs);
			stk.back().sc = max(stk.back().sc,i.sc);
		}
		else{
			stk.push_back(i);
		}
	}
	reverse(stk.begin(),stk.end());
	//for(auto &i:stk)cout<<i.fs<<' '<<i.sc<<',';cout<<'\n';
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		auto it = upper_bound(stk.begin(),stk.end(),make_pair(k,inf));
		if(it != stk.begin()){
			it--;
			if(it->fs<=k&&it->sc>=k){
				cout<<it->sc<<' ';
				continue;
			}
		}
		cout<<k<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
