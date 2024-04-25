#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e7+10;
int lpf[mxn];

int main(){
	lpf[0] = lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j =i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int G = arr[0];
	for(auto &i:arr)G = __gcd(G,i);
	if(*max_element(arr,arr+n) == G){
		cout<<-1;
		return 0;
	}
	map<int,int> mp;
	for(auto &i:arr){
		int rest = i/G;
		unordered_set<int> st;
		while(rest != 1){
			st.insert(lpf[rest]);
			rest/=lpf[rest];
		}
		for(auto &j:st)mp[j]++;
	}
	int ans = n;
	for(auto &i:mp){
		ans = min(ans,n-i.second);
	}
	cout<<ans;
}
