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
const ll mxn = 1e6+10;
ll arr[mxn];
int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		arr[a]++;
		arr[b+1]--;
	}
	pii ans = {0,0};
	int now = 0;
	for(int i = 0;i<mxn;i++){
		now += arr[i];
		ans = max(ans,{now,i});
	}
	cout<<ans.fs<<endl;
}

