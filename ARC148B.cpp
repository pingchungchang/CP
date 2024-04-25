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
	int n;
	cin>>n;
	string s;
	cin>>s;
	string ans = s;
	int start = -1;
	for(int i = 0;i<n;i++){
		if(s[i] == 'p'){
			start = i;
			break;
		}
	}
	if(start == -1){
		cout<<s;
		return 0;
	}
	for(int i = start;i<n;i++){
		string tmp = s;
		int len = i-start+1;
		for(int j = 0;j<len/2;j++){
			swap(tmp[i-j],tmp[start+j]);
		}
		for(int j = start;j<=i;j++){
			if(tmp[j] == 'd')tmp[j] = 'p';
			else tmp[j] = 'd';
		}
		ans= min(ans,tmp);
//		cout<<i<<' '<<tmp<<endl;
	}
	cout<<ans;
}

