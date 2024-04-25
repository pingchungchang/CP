#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b;
	cin>>a>>b;
	ll ans = 0;
	ll dif = __gcd(a,b);
	ll big = abs(a-b);
	vector<ll> all;
	for(ll i = 1;i*i<=big;i++){
		if(big%i == 0){
			ll tmp = i;
			if(tmp%dif == 0)all.push_back(tmp);
			tmp = big/i;
			if(tmp%dif == 0&&i != tmp)all.push_back(tmp);
		}
	}
	bool flag = true;
	while(a != 0&&b != 0){
		//cout<<dif<<endl;
		flag = false;
		pair<ll,ll> choose = {1e18,-1};
		for(auto &i:all){
			if(a%i == b%i&&i != dif)choose = min(choose,{a%i/dif,i}),flag = true;
		}
		if(!flag)break;
		if(choose.second != -1)ans += choose.first;
		//cout<<dif<<":"<<choose.second<<endl;
		a -= choose.first*dif;
		b -= choose.first*dif;
		dif = choose.second;
		vector<ll> tmp;
		for(auto &i:all){
			if(i%dif == 0)tmp.push_back(i);
		}
		all = tmp;
	}
	if(a != 0&&b != 0)ans += min(a,b)/dif;
	cout<<ans;
}
