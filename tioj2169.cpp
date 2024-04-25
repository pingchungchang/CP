#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,k;

int check(int d){
	int now = 0;
	for(int i = 2;i<=n;i++){
		now = (now+d)%i;
	}
	return now;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	k--;
	for(int i = 2;i<=30000;i++){
		if(check(i) == k){
			cout<<i;
			return 0;
		}
	}
	cout<<0;
}
