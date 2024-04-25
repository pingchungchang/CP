#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll inf = 1e8;

void solve(){
	ll n;
	cin>>n;
	ll tmp = n;
	ll b = 0;
	while(tmp)b++,tmp>>=1;
	b--;
	if(n == 1){
		cout<<"1\n1\n";
		return;
	}
	vector<int> v;
	for(int i = 1;i<=b;i++)v.push_back(i);
	for(int i = b-1;i>=0;i--){
		if(n&(1ll<<i)){
			v.insert(v.begin()+i,inf);
		}
	}
	cout<<v.size()<<'\n';
	for(auto &i:v)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
