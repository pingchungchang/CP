#include <bits/stdc++.h>
using namespace std;
#define ll long long
multiset<ll> st;

void add(){
	ll x;
	cin>>x;
	st.insert(x);
}

void findh(){
	ll x,k;
	cin>>x>>k;
	auto it = st.upper_bound(x);
	while(k != 0){
		if(it == st.begin()){
			cout<<-1<<'\n';
			return;
		}
		it--;
		k--;
	}
	cout<<*it<<'\n';
	return;
}
void findl(){
	ll x,k;
	cin>>x>>k;
	auto it = st.upper_bound(x-1);
	k--;
	while(k != 0&&it != st.end()){
		it++;
		k--;
	}
	if(it == st.end())cout<<-1<<'\n';
	else cout<<*it<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		int t;
		cin>>t;
		if(t == 1)add();
		else if(t == 2)findh();
		else findl();
	}
}
