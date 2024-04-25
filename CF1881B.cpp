#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

bool check(int arr[],int tar){
	if(!tar)return false;
	int C = 0;
	for(int i = 0;i<3;i++){
		if(arr[i]%tar != 0)return false;
		C += arr[i]/tar-1;
	}
	return C<=3;
}

void solve(){
	int arr[3];
	vector<int> v;
	for(auto &i:arr){
		cin>>i;
		v.push_back(i);
		v.push_back(i/4);
		v.push_back(i/2);
		v.push_back(i/3);
	}
	for(auto &i:v){
		if(check(arr,i)){
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
