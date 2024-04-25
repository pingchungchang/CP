#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	pll hero;
	cin>>hero.fs>>hero.sc>>n;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	sort(arr,arr+n);
	for(auto &i:arr){
		if(hero.sc<=0){
			cout<<"NO\n";
			return;
		}
		ll C = min((hero.sc+i.fs-1)/i.fs,(i.sc+hero.fs-1)/hero.fs);
		hero.sc -= C*i.fs;
		i.sc -= C*hero.fs;
		if(i.sc>0){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
