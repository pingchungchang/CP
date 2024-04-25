#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

bitset<200005> able;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(auto &i:arr)cin>>i;
	if(k == 1){
		for(auto &i:arr)cout<<i<<' ';
		return 0;
	}
	int len = 1;
	for(int i = 1;i<n;i++){
		if(arr[i]>arr[i-1])len++;
		else len = 1;
		if(len>=k){
			for(auto &j:arr)cout<<j<<' ';cout<<'\n';
			return 0;
		}
	}
	set<int> st;
	for(int i = 0;i<k;i++)st.insert(arr[n-1-i]);
	int p = n-k;
	for(int i = n-k-1;i>=0;i--){
		st.erase(arr[i+k]);
		if(arr[i]<*st.begin())p = i;
		if(arr[i]>arr[i+1])break;
		st.insert(arr[i]);
		assert(st.size() == k);
	}
	sort(arr+p,arr+p+k);
	for(auto &i:arr)cout<<i<<' ';
	return 0;
}
