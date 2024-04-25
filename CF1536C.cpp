#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
vector<int> ans;
int gcd(int a,int b){
	if(a<b)swap(a,b);
	while(b != 0){
		a-=(a/b)*b;
		swap(a,b);
	}
	return a;
}
void solve(){
	int n;
	cin>>n;
	cin>>s;
	map<ll,int> mp;
	pair<int,int> p =make_pair(0,0);
	int ans = 0;
	for(int i =0;i<n;i++){
		if(s[i] == 'D'){
			p.first++;
		}
		else p.second++;
		pair<int,int> racio = make_pair(p.first/gcd(p.first,p.second),p.second/gcd(p.first,p.second));
		if(mp.count(1LL*racio.first*1e6+racio.second) == 0)mp[1LL*racio.first*1e6+racio.second] = 1;
		else mp[1LL*racio.first*1e6+racio.second]++;
		cout<<mp[1LL*racio.first*1e6+racio.second]<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
