#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,x;
	cin>>n>>x;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(k<=x)ans+=k;
	}
	cout<<ans;
}
