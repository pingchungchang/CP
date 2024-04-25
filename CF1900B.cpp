#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	ll s = a+b+c;
	int arr[] = {a,b,c};
	for(auto &i:arr)cout<<((s-i)%2 == 0?1:0)<<' ';cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
