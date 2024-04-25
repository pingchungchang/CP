#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string a,b,c;
	cin>>a>>b>>c;
	for(int i = 0;i<a.size();i++){
		if(c[i] == b[i])swap(c[i],a[i]);
		else swap(c[i],b[i]);
	}
	if(b == a)cout<<"Yes\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
