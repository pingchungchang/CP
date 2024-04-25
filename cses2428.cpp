#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(ll i =0;i<n;i++)cin>>v[i];
	ll p1 = 0,p2=0;
	map<ll,ll> m;
	ll ans = 0;
	while(p2 <n){
		if(m.count(v[p2]) == 0){
			while(m.size()==k){
				m[v[p1]] --;
				if(m[v[p1]] ==0)m.erase(v[p1]);
				p1++;
			}
			m[v[p2]] = 1;
			p2++;
			ans += p2-p1;
		}
		else{
			m[v[p2]]++;
			p2++;
			ans += p2-p1;
		}
//		cout<<p1<<' '<<p2<<endl;
	}
	cout<<ans;
}
