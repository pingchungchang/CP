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
	string s;
	cin>>s;
	vector<int> o,z;
	int one = 0,zero = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == '0')zero++;
		else one++;
	}
	for(int i = 0;i<n;i++){
		if(i<zero&&s[i] == '1')o.push_back(i);
		else if(i>=zero&&s[i] == '0')z.push_back(i);
	}
	if(o.empty()){
		cout<<"0\n";
		return;
	}
	cout<<1<<'\n';
	cout<<o.size()*2<<' ';
	for(auto i:o)cout<<i+1<<' ';
	for(auto i:z)cout<<i+1<<' ';cout<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

