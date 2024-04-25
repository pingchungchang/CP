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
	int l = 1,r = n;
	while(l != r){
		int mid = (l+r+1)/2;
		cout<<mid<<endl;
		int in;
		cin>>in;
		if(in == 0)return 0;
		else if(in == -1){
			l = mid+1;
		}
		else r = mid-1;
	}
	cout<<l<<endl;
}

