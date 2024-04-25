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
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int ans[n];
	int p = 0;
	int tmp = 0;
	while(true){
		pii re = {0,-1};
		for(int i = 0;i<n;i++){
			if(arr[i] == -1)continue;
			else if((arr[i]|tmp)>(re.fs|tmp)){
				re = {arr[i],i};
			}
		}
		if(re.sc == -1)break;
		else{
			tmp|=re.fs;
			ans[p++] = re.fs;
			arr[re.sc] = -1;
		}
	}
	for(int i = 0;i<n;i++){
		if(arr[i] != -1)ans[p++] = arr[i];
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

