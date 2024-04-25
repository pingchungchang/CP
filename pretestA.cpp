#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	set<ll> v;
	for(int i = 0;i<k;i++){
		ll a,b;
		cin>>a>>b;
		ll pos = 0;
		pos += (a-1)*m;
		if(a%2 == 0){
			pos += (m-b+1);
		} 
		else pos += b;
		v.insert(pos);
	}
	if(k == 0){
		ll asd= (1ll*n*m)/6;
		if(asd*6<n*m)asd+=1;
		cout<<asd;
		return 0;
	}
//	cout<<endl;
//	for(auto it = v.begin();it != v.end();it++)cout<<*it<<' ';
//	cout<<endl<<endl;
	ll con = 0;
	ll prev = -1;
	for(auto it = v.begin();it != v.end();it++){
		if(*it-prev == 1){
			con++;
		}
		else con = 1;
		prev = *it;
		if(con == 6){
			cout<<-1;
			return 0;
		}
	}
	
	v.insert(n*m+1);
	ll ans = 0;
	ll now = 0;
	for(auto it = v.begin();it != v.end();it++){
//		cout<<now<<' '<<*it<<endl;
		if(*it>n*m){
			if(now>=m*n){
				cout<<ans;
				return 0;
			}
			ans += (n*m-now)/6;
			if((n*m-now)%6 !=0)ans++;
			cout<<ans;
			return 0;
		}
		if(*it<now)continue;
		if((*it-now)%6 == 0){
			ans += ((*it-now)/6);
			for(int i = -1;i>=-5;i--){
				if(v.find(*it+i) == v.end()){
					now = *it+i;
					break;
				}
			}
		}
		else{
			continue;
		}
	}
}
