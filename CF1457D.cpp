#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int hbit(int k){
	int re = 1;
	k>>=1;
	while(k){
		re<<=1;
		k>>=1;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 2;i<n;i++){
		if(hbit(arr[i-2]) == hbit(arr[i-1])&&hbit(arr[i-1]) == hbit(arr[i])){
			cout<<1;
			return 0;
		}
	}
	int ans = 1e9;
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			for(int l = j+1;l<n;l++){
				vector<int> v;
				for(int k = 0;k<i;k++)v.push_back(arr[k]);
				int x = 0;
				for(int k = i;k<=j;k++)x ^= arr[k];
				v.push_back(x);
				x = 0;
				for(int k = j+1;k<=l;k++)x ^= arr[k];
				v.push_back(x);
				for(int k = l+1;k<n;k++)v.push_back(arr[k]);
				bool flag = true;
				for(int k = 1;k<v.size();k++){
					if(v[k-1]>v[k])flag = false;
				}
				if(!flag)ans = min(ans,l-i-1);
				/*
				if(!flag){
					cout<<i<<j<<l<<":";for(auto &k:v)cout<<k<<' ';cout<<endl;
				}
			   */
			}
		}
	}
	if(ans>n)cout<<-1;
	else cout<<ans;
}
