#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


vector<int> v[2][2];
int N;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++){
		int a,b;
		cin>>a>>b;
		int x = a+b,y = a-b;
		v[x&1][0].push_back(x);
		v[x&1][1].push_back(y);
	}
	ll ans = 0;
	for(auto &i:v){
		for(auto &j:i){
			ll pref = 0,cnt = 0;
			sort(j.begin(),j.end());
			for(auto &k:j){
				ans += 1ll*cnt*k-pref;
				pref += k;
				cnt++;
			}
		}
	}
	cout<<ans/2<<'\n';
	return 0;
}
