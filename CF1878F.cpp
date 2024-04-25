#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = sqrt(1e9)+10;
bitset<mxn> isp;
vector<int> primes;

vector<pii> dec(int k){
	vector<pii> re;
	for(auto &i:primes){
		if(i>k)break;
		if(k%i == 0){
			re.push_back({i,0});
			while(k%i == 0){
				k/=i;
				re.back().sc++;
			}
		}
	}
	if(k != 1)re.push_back({k,1});
	return re;
}

void solve(){
	map<int,int> mp;
	int n,q;
	cin>>n>>q;
	auto init = dec(n);
	int d = 1;
	for(auto &i:init)mp[i.fs] = i.sc,d *= i.sc+1;
	while(q--){
		int tp;
		cin>>tp;
		if(tp == 2){
			mp.clear();
			d = 1;
			for(auto &i:init)mp[i.fs] = i.sc,d*=i.sc+1;
		}
		else{
			int x;
			cin>>x;
			auto tmp = dec(x);
			for(auto &i:tmp){
				if(mp.find(i.fs) != mp.end()){
					d/=mp[i.fs]+1;
				}
				mp[i.fs] += i.sc;
				d *= mp[i.fs]+1;
			}
			tmp = dec(d);
			bool flag = true;
			for(auto &i:tmp){
				if(mp.find(i.fs) == mp.end()||mp[i.fs]<i.sc)flag = false;
			}
			if(flag)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	cout<<'\n';
	return;
}

int main(){
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			primes.push_back(i);
			for(int j = i+i;j<mxn;j+=i)isp[j] = true;
		}
	}
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
