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
	int arr[] = {4,3,5,2,4,6,1,3,5,7};
	int cnt[8] = {};
	bool bb = true;
	for(int i = 0;i<10;i++){
		char c;
		cin>>c;
		if(i == 0&&c == '1')bb = false;
		if(c == '1')cnt[arr[i]]++;
	}
	bool ans = false;
	for(int i = 2;i<=6;i++){
		bool flag = false;
		for(int j = 0;j<i;j++)if(cnt[j])flag = true;
		if(!flag)continue;
		flag = false;
		for(int j = i+1;j<=7;j++)if(cnt[j])flag = true;
		if(flag&&cnt[i] == 0)ans = true;
	}
	if(ans&&bb)cout<<"Yes";
	else cout<<"No";
}

