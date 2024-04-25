#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,h,x;
	cin>>n>>h>>x;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		if(k+h>=x){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
