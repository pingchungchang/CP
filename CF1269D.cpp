#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll arr[n];
	ll ans = 0;
	for(auto &i:arr){
		cin>>i;
		ans += i/2;
		i&=1;
	}
	vector<int> st;
	for(int i = 0;i<n;i++){
		if(arr[i]){
			if(!st.empty()&&((i-st.back())&1)){
				ans++;
				st.pop_back();
			}
			else st.push_back(i);
		}
	}
	cout<<ans;
}
