#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int f(int n,int k){
	if(n == 1)return 1;
	if(k == 1)return 2;
	if(k<=n/2)return k*2;
	if(n&1){
		int tmp = f((n+1)/2,k-n/2);
		if(tmp == 1)return n;
		else return tmp*2-3;
	}
	else{
		int tmp = f(n/2,k-n/2);
		return tmp*2-1;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		int n,k;
		cin>>n>>k;
		cout<<f(n,k)<<'\n';
	}
	return 0;
}
