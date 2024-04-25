#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> v;
	int c = 2;
	while(v.size()<n){
		v.push_back(c);
		c++;
		if((v.back()+c)%3 == 0)c++;
	}
	for(auto &i:v)cout<<i<<' ';cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
