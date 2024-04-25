#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	string s;
	cin>>n>>s;
	int ans = 0;
	for(char c = 'z';c>'a';c--){
		set<int> del;
		if(s.size() == 1)break;
		for(int i = 0;i<s.size();i++){
			if(s[i] != c)continue;
			if(!i&&s[i+1] == c-1){
				del.insert(0);
			}
			else if(i == s.size()-1&&s[i-1] == c-1){
				del.insert(i);
			}
			else if(s[i+1] == c-1||s[i-1] == c-1){
				del.insert(i);
			}
		}
		ans += del.size();
		string t;
		for(int i = 0;i<s.size();i++)if(del.find(i) == del.end())t += s[i];
		swap(t,s);
		if(!del.empty())c++;
	}
	cout<<ans;
}
