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
	priority_queue<int,vector<int>,greater<int>> na,nb;
	priority_queue<int,vector<int>,less<int>> a,b;
	ll ta = 0,tb = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		a.push(k);
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		b.push(k);
	}
	for(int i = 1;i<=n-n/4;i++){
		na.push(a.top());
		nb.push(b.top());
		ta += a.top();
		tb += b.top();
		a.pop();
		b.pop();
	}
	int cnt = 0;
	while(ta<tb){
		n++,cnt++;
		na.push(100);
		b.push(0);
		nb.push(b.top());
		ta += 100;
		tb += b.top();
		b.pop();
		if(n%4 == 0){
			ta -= na.top();
			a.push(na.top());
			na.pop();
			tb -= nb.top();
			b.push(nb.top());
			nb.pop();
		}
	}
	cout<<cnt<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

