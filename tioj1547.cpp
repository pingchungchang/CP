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
	cin>>n;
	int pre = 1,now = 1;
	int x = 1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<now;j++){
			cout<<x;
			x++;
			if(x>=3)x-= 3;
		}
		cout<<'\n';
		swap(now,pre);
		now += pre;
	}
	
}

