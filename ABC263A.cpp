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
	int cnt[14] = {};
	for(int  i = 0;i<5;i++){
		int k;
		cin>>k;
		cnt[k]++;
	}
	sort(cnt,cnt+14);
	if(cnt[13] == 3&&cnt[12] == 2){
		cout<<"Yes";
	}
	else cout<<"No";
}

