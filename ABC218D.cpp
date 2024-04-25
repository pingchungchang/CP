#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pii arr[n];
	for(auto &i:arr){
		cin>>i.fs>>i.sc;
	}
	map<int,vector<int>> mp;
	for(auto &i:arr){
		mp[i.fs].push_back(i.sc);
	}
	for(auto &i:mp)sort(i.sc.begin(),i.sc.end());
	ll ans = 0;
	for(auto it = mp.begin();it != mp.end();it++){
		for(auto j = next(it);j != mp.end();j++){
			ll cnt = 0;
			for(auto &k:it->sc){
				auto tmp = lower_bound(j->sc.begin(),j->sc.end(),k);
				if(tmp != j->sc.end()&&*tmp == k)cnt++;
			}
			//cout<<it->fs<<' '<<j->fs<<':'<<cnt<<endl;
			ans += cnt*(cnt-1)/2;
		}
	}
	cout<<ans;
}
