#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	for(auto &i:a){
		if(i == '1')i = 'l';
		else if(i == '0')i = 'o';
	}
	for(auto &i:b){
		if(i == '1')i = 'l';
		else if(i == '0')i = 'o';
	}
	if(a == b)cout<<"Yes";
	else cout<<"No";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
