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
	int n,k;
	cin>>n>>k;
	int s = 0;
	for(int i = 0;i<n;i++){
		int t;
		cin>>t;
		s ^= t;
	}
	cout<<(s?"alvin":"bao");
}
