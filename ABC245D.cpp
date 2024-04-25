#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll> a;
vector<ll> c;
vector<ll> b;
int n,m;
void mm(int pos,int val){
	for(int i = 0;i<=n;i++){
		c[i+pos] -= a[i]*val;
	}
	return;
}
int main(){
	cin>>n>>m;
	a = vector<ll>(n+1);
	c = vector<ll>(m+n+1);
	for(int i = 0;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<=n+m;i++)cin>>c[i];
	reverse(a.begin(),a.end());
	reverse(c.begin(),c.end());
	for(int i = 0;i<=m;i++){
		b.push_back(c[i]/a[0]);
		mm(i,c[i]/a[0]);
	}
	reverse(b.begin(),b.end());
	for(auto i:b)cout<<i<<' ';
}

