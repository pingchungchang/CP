#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


string s,a,b;
map<string,string> mp1,mp2;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>s){
		if(s == "add"){
			cin>>a>>b;
			mp1[a] = b;
			mp2[b] = a;
		}
		else if(s == "chk"){
			cin>>a;
			string b = a.substr(1,a.size()-1);
			if(a[0] == 'n'){
				if(mp1.find(b) != mp1.end())cout<<b<<' '<<mp1[b]<<'\n';
				else cout<<"Not found.\n";
			}
			else{
				if(mp2.find(b) != mp2.end())cout<<mp2[b]<<' '<<b<<'\n';
				else cout<<"Not found.\n";
			}
		}
		else{
			cin>>a;
			b = a.substr(1,a.size()-1);
			if(a[0] == 'n'){
				mp2.erase(mp1[b]);
				mp1.erase(b);
			}
			else{
				mp1.erase(mp2[b]);
				mp2.erase(b);
			}
		}
	}
	return 0;
}
