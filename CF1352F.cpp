#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	swap(b,c);
	string tmp;
	if(a>0)tmp += string(a+1,'0');
	if(b>0)tmp += string(b+1,'1');
	if(a>0&&b>0)c--;
	if(a == 0&&b == 0)tmp += '0';
	for(int i = 1;i<=c;i++){
		if(tmp.back() == '0')tmp += '1';
		else tmp += '0';
	}
	cout<<tmp<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
