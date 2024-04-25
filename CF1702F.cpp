#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	multiset<ll> a,b;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		while((k&1) == 0)k>>=1;
		a.insert(k);
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		b.insert(k);
	}
	for(auto it = a.rbegin();it != a.rend();it++){
		int val = *it;
		while(*b.rbegin() != val&&*b.rbegin()>val){
			int tmp = *b.rbegin();
			b.erase(b.find(*b.rbegin()));
			b.insert(tmp/2);
		}
		if(*b.rbegin() == val){
			b.erase(b.find(*b.rbegin()));
		}
		else{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

