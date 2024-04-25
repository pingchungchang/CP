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
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		arr[i] = tmp;
	}
	int p = -1;
	int use = 0;
	int ans = 0;
	for(int i = 0;i<n;i++){
		while(p<n&&use<=k){
			p++;
			if(!arr[p])use++;
		}
//		cout<<i<<' '<<p<<endl;
		ans = max(ans,p-i);
		if(!arr[i])use--;
	}
	cout<<ans;
}

