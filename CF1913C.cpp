#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


map<int,int> mp;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		int t,x;
		cin>>t>>x;
		if(t == 1){
			mp[x]++;
			while(x<=30&&mp[x]>2){
				mp[x] -= 2;
				mp[++x]++;
			}
		}
		else{
			for(auto it = mp.rbegin();it != mp.rend();it++){
				for(int j = 0;j<it->sc;j++){
					if(x>=(1ll<<(it->fs)))x -= 1ll<<it->fs;
				}
			}
			cout<<(!x?"YES\n":"NO\n");
		}
	}
	return 0;
}
