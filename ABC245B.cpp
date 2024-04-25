#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int v[2001] = {};
	int n,m;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>m;
		v[m]++;
	}
	for(int i = 0;i<=2000;i++){
		if(v[i] == 0){
			cout<<i;
			return 0;
		}
	}
}

