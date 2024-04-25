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
	string s;cin>>s;
	int ans = 0;
	for(int i = 0;i<s.size();i++){
		string tmp;
		for(int j = i;j<s.size();j++){
			tmp += s[j];
			for(int k = 0;k+j-i+1<=s.size();k++){
				if(s.substr(k,j-i+1) == tmp&&k != i){
					ans = max(ans,j-i+1);
				}
			}
		}
	}
	cout<<ans;
}
