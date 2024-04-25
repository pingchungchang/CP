#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 998244353;

int main(){
	deque<char> a;
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(auto i:s)a.push_back(i);
	cin>>s;
	for(auto i:s){
		if(i == '1')a.push_front(i);
		else a.push_back(i);
	}
	ll ans = 0;
	ll p = 1LL;
	while(!a.empty()){
		if(a.back() == '1')ans = (ans+p>=mod?ans+p-mod:ans+p);
		p = (p+p>=mod?p+p-mod:p+p);
		a.pop_back();
	}
	cout<<ans;
}

