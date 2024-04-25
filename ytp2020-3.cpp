#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int r,c;
	cin>>r>>c;
	vector<string> v(r+1,string(c,' '));
	string in;
	getline(cin,in);
	for(int i = 1;i<=r;i++){
		getline(cin,in);
		while(in.size() != c)in += " ";
		v[i] = in;
	}
	int ans = 0;
	for(int i = 0;i<c;i++){
		for(int j = 1;j<=r;j++){
			if(v[j][i] == 'X'&&v[j-1][i] != 'X')ans++;
		}
	}
	cout<<ans;
}


