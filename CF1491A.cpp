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
int main(){
	io
	int n,q;
	cin>>n>>q;
	bool arr[n];
	int cnt = 0;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		if(arr[i])cnt++;
	}
	while(q--){
		int t,p;
		cin>>t>>p;
		if(t == 1){
			if(arr[p-1])cnt--;
			else cnt++;
			arr[p-1] ^=1;
		}
		else{
			if(p>cnt)cout<<0<<'\n';
			else cout<<"1\n";
		}
	}
	return 0;
}

