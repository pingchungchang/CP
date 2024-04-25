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
	int n,x;
	cin>>n>>x;
	int cnt = 0,y = x,le = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(k>=y+le){
			cnt += y+le;
			le = 0;
			y++;
		}
		else{
			cnt += k;
			le = le+y-k;
			y = max(0,y-1);
		}
	}
	cout<<cnt<<' '<<le<<'\n';
}

