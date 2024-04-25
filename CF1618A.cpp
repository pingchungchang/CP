#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	ll arr[7];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+7);
	ll a = arr[0],b = arr[1];
	multiset<ll> st;
	st.insert(a);st.insert(b);st.insert(a+b);
	ll c= 0;
	for(auto i:arr){
		if(st.find(i) != st.end())st.erase(st.find(i));
		else{
			c = i;
			break;
		}
	}
	cout<<a<<' '<<b<<' '<<c<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

