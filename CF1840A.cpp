#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	string re;
	bool flag = false;
	for(auto &i:s){
		if(!flag)re += i,flag = true;
		else if(flag&&re.back() == i)flag = false;
	}
	cout<<re<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
