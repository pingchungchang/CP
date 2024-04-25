#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#define T.size() int(T.size())
void solve(){
	string a,b;
	cin>>a>>b;
	int k  = a.size()*b.size()/__gcd((int)a.size(),(int)b.size());
	string ans;
	while(ans.size() != k)ans += a;
	for(int i = 0;i<k;i+=b.size()){
		if(ans.substr(i,b.size()) != b){
			cout<<"-1\n";
			return;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

