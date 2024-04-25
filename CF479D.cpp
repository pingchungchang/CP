#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll n,x,y,l;
	cin>>n>>l>>x>>y;
	vector<ll> v(n);
	set<ll> st;
	for(ll i = 0;i<n;i++)cin>>v[i];
	for(auto i:v)st.insert(i);
	bool flag1 = false,flag2 = false;
	for(auto i:v){
		if(st.find(i+x) != st.end()||st.find(i-x) != st.end())flag1 = true;
		if(st.find(i+y) != st.end()||st.find(i-y) != st.end())flag2 = true;
	}
	if(flag1 && flag2){
		cout<<0;
		return 0;
	}
	if(flag1 && !flag2){
		cout<<1<<'\n'<<y;
		return 0;
	}
	else if(!flag1&&flag2){
		cout<<1<<'\n'<<x;
		return 0;
	}
	for(auto i:v){
		if(i-x>=0&&(st.find(i-x+y) != st.end()||st.find(i-x-y) != st.end())){
			cout<<1<<'\n'<<i-x;
			return 0;
		}
		else if(i-y>=0&&(st.find(i-y-x) != st.end()||st.find(i-y+x) != st.end())){
			cout<<1<<'\n'<<i-y;
			return 0;
		}
		else if(i+x<=l&&(st.find(i+x+y) != st.end()||st.find(i+x-y) != st.end())){
			cout<<1<<'\n'<<i+x;
			return 0;
		}
		else if(i+y<=l&&(st.find(i+y+x) != st.end()||st.find(i+y-x) != st.end())){
			cout<<1<<'\n'<<i+y;
			return 0;
		}
	}
	cout<<2<<'\n'<<x<<' '<<y;
}

