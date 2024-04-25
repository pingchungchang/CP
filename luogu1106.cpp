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
	string s;int k;
	cin>>s>>k;
	while(k--){
		int pt = -1;
		for(int i = 0;i+1<s.size();i++){
			if(s[i]>s[i+1]){
				pt = i;
				break;
			}
		}
		if(pt != -1)s.erase(s.begin()+pt,s.begin()+pt+1);
		else s.pop_back();
	}
	while(!s.empty()&&s[0] == '0')s.erase(s.begin(),s.begin()+1);
	if(s.empty())s = "0";
	cout<<s;
}
