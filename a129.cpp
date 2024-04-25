#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	vector<pll> v(n);
	for(int i = 0;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		v[i] = make_pair(a*a+b*b,-c);
	}
	sort(v.begin(),v.end());
	for(auto &i:v)i.sc = -i.sc;
	ll nowbig = 0,ans = 0;
	for(auto i:v){
		ans = max(ans,nowbig-i.sc);
		nowbig = max(nowbig,i.sc);
	}
	
	cout<<ans;
}

