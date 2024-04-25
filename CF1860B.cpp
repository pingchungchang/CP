#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll m,k,a,b;
	cin>>m>>k>>a>>b;
	ll tmp = min(m/k,b);
	b -= tmp;
	m -= tmp*k;
	tmp = min(m/k,a/k-1);
	tmp = max(tmp,0LL);
	m -= tmp*k;
	a -= tmp*k;
	vector<ll> ans;
	if(a>=m%k){
		ans.push_back(m/k);
	}
	else{
		ans.push_back(m/k+max(0LL,m%k-a%k));
	}
	if(a>=k&&m>=k){
		a -= k;
		m -= k;
	}
	if(a>=m%k){
		ans.push_back(m/k);
	}
	else{
		ans.push_back(m/k+max(0LL,m%k-a%k));
	}
	cout<<*min_element(ans.begin(),ans.end())<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
