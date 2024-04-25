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
	int n;
	ld t,a;
	cin>>n>>t>>a;
	int ans = 0;
	ld arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		arr[i] = t-arr[i]*0.006;
		if(abs(a-arr[i])<abs(arr[ans]-a))ans = i;
	}
	cout<<ans+1;
}

