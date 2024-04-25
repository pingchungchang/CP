#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	sort(arr,arr+n);
	multiset<ll> st;
	ll ans = 0;
	for(auto &i:arr){
		if(st.size()<i.fs)ans += i.sc,st.insert(i.sc);
		else{
			if(*st.begin()<i.sc){
				ans -= *st.begin();
				st.erase(st.find(*st.begin()));
				st.insert(i.sc);
				ans += i.sc;
			}
		}
	}
	cout<<ans;
}
