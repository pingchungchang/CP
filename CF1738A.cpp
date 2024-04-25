#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	ll n;
	cin>>n;
	multiset<ll> a,b;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll ans = 0;
	ll ans1 = 0,ans2 = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		ans += k;
		if(arr[i] == 0)a.insert(k);
		else b.insert(k);
	}
	auto ta = a,tb = b;
	bool flag = true;
	if(!tb.empty())tb.erase(tb.find(*tb.begin()));
	else flag = false;
	for(int i = 1;i<n;++i){
		if(!flag)break;
		if((i&1)&&!ta.empty()){
			ans1 += *ta.rbegin();
			ta.erase(ta.find(*ta.rbegin()));
		}
		else if(!(i&1)&&!tb.empty()){
			ans1 += *tb.rbegin();
			tb.erase(tb.find(*tb.rbegin()));
		}
		else break;
	}
	flag = true;
	if(!a.empty())a.erase(a.find(*a.begin()));
	else flag = false;
	for(int i = 1;i<n;i++){
		if(!flag)break;
		if((i&1)&&!b.empty()){
			ans2 += *b.rbegin();
			b.erase(b.find(*b.rbegin()));
		}
		else if(!(i&1)&&!a.empty()){
			ans2 += *a.rbegin();
			a.erase(a.find(*a.rbegin()));
		}
		else break;;
	}
//	cout<<ans1<<','<<ans2<<',';
	cout<<ans+ max(ans1,ans2)<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

