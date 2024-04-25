#include <bits/stdc++.h>
using namespace std;

bool cmp(string a,string b){
	return a.size()<b.size();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin>>m;
	vector<string> v(m);
	for(int i = 0;i<m;i++)cin>>v[i];
	sort(v.begin(),v.end(),cmp);
//	cout<<v[0];
	set<string> st;
	long long ans = 0;
	for(int i = 0;i<m;i++){
		string s = v[i];
		for(int j = 1;j<=s.size()/2;j++){
			string form = s.substr(0,j);
			string lat = s.substr(s.size()-j,j);
			if(form == lat){
				if(st.find(s.substr(j,s.size()-j-j)) != st.end())ans++;
			}
		}
		st.insert(s);
	}
	cout<<ans;
	return 0;
}
