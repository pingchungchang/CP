#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
ll arr[mxn],brr[mxn];
ll fin[mxn];
ll n;
multiset<ll> st;
vector<ll> dif;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++)cin>>brr[i];
	sort(arr,arr+n);
	sort(brr,brr+n);
	for(int i = 0;i<n;i++){
		if(fin[i]<arr[i])fin[i] = arr[i];
		fin[i+1] = fin[i]+1;
	}
	int pt = 0;
	for(int i = 0;i<n;i++){
		while(pt<n&&arr[pt]<=fin[i]){
			st.insert(arr[pt]);
			pt++;
		}
		dif.push_back(fin[i]-*st.rbegin());
		st.erase(st.find(*st.rbegin()));
	}
	sort(dif.rbegin(),dif.rend());
	ll ans = 0;
	for(int i = 0;i<n;i++)ans += dif[i]*brr[i];
	cout<<ans;
}
