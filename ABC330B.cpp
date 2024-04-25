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
	int n,l,r;
	cin>>n>>l>>r;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(k<l)cout<<l<<' ';
		else if(k>r)cout<<r<<' ';
		else cout<<k<<' ';
	}
	return 0;
}
