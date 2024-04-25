#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

vector<pii> v;
int gcd(int a,int b){
	if(a == 0||b == 0){
		return a+b;
	}
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
int calc(int now){
	map<tuple<int,int>,int> mp;
	int same = 0;
	for(auto j:v){
//		cout<<j.first<<j.second<<endl;
		pii i = make_pair(j.first-v[now].first,j.second-v[now].second);
		if(i.first != 0||i.second != 0)i = make_pair(i.f/(gcd(abs(i.f),abs(i.s))),i.s/(gcd(abs(i.f),abs(i.s))));
		if(i.first<0){
			i.first = -i.first;
			i.second = -i.second;
		}
		else if(i.first == 0)i.second = abs(i.second);
		if(mp.count(make_tuple(i.first,i.second)) == 0){
			mp[make_tuple(i.first,i.second)] = 1;
		}
		else mp[make_tuple(i.first,i.second)]++;
		if(i.first == 0&&i.second == 0)same++;
	}
	int ans = 0;
	for(auto it:mp){
		if(it.first != make_tuple(0,0))it.second += same;
		ans = max(ans,it.second);
	}
	return ans;
}
int main(){
	int n,d;
	cin>>n>>d;
	if(d != 0)return 0;
	v = vector<pii>(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}
	int ans= 0;
	for(int i = 0;i<n;i++){
		ans = max(ans,calc(i));
	}
	cout<<ans;
}
