#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int p1 = 0,p2 = s.size()-1;
	bool flag = true;
	vector<vector<int>> ans;
	while(flag){
		flag = false;
		ans.push_back({});
		int p2 = s.size()-1;
		for(int i = 0;i<s.size();i++){
			if(s[i] == '('){
				while(p2>i&&s[p2] != ')')p2--;
				if(p2<=i)break;
				ans.back().push_back(i);
				ans.back().push_back(p2);
				s[i] = s[p2] = '.';
				p2--;
				flag = true;
			}
		}
	}
	while(!ans.empty()&&ans.back().empty())ans.pop_back();
	cout<<ans.size()<<'\n';
	for(auto &i:ans){
		cout<<i.size()<<'\n';
		sort(i.begin(),i.end());
		for(auto &j:i)cout<<j+1<<' ';cout<<'\n';
	}
	return 0;
}
