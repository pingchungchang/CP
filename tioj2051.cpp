#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool iscap(char c){
	if(c>='A'&&c<='Z')return true;
	else return false;
}
bool islittle(char c){
	if(c>='a'&&c<='z')return true;
	else return false;
}
bool isdigit(char c){
	if(c>='0'&&c<='9')return true;
	else return false;
}

map<string,int> rec(vector<string> v,int &now,map<string,int> pre){
	if(now == v.size())return pre;
//	cout<<v[now]<<' ';
	if(v[now] == "("){
		now++;
		map<string,int> tmp;
		tmp = rec(v,now,tmp);
		int t = stoi(v[now]);
		now++;
		for(auto it:tmp){
			if(pre.count(it.fs) == 0){
				pre[it.fs] = it.sc*t;
			}
			else pre[it.fs] += it.sc*t;
		}
	}
	else if(v[now] == ")"){
		now++;
		return pre;
	}
	else{
		string elem = v[now];
		now++;
		int t = stoi(v[now]);
		now++;
		if(pre.count(elem) == 0)pre[elem] = t;
		else pre[elem] += t;
	}
	return rec(v,now,pre);
	
}
int main(){
	string s;
	cin>>s;
	string cop = s;
	s += "Abcdef";
	int n = s.size();
	vector<string> v;
	vector<int> pos;
	string tmp;
	for(int i = 0;i<n-1;i++){
		tmp += s[i];
		if(isdigit(s[i+1])&&isdigit(s[i]))continue;
		else if(islittle(s[i+1]))continue;
		else pos.push_back(i);
	}
	for(int i = pos.size()-1;i>=0;i--){
		s = s.substr(0,pos[i]+1)+' '+s.substr(pos[i]+1,s.size()-pos[i]);
	}
	stringstream ss(s);
	string k;
	while(ss>>k){
		if(!v.empty()&&iscap(v[v.size()-1][0])&&!isdigit(k[0]))v.push_back("1");
		else if(!v.empty()&&v[v.size()-1] == ")"&&!isdigit(k[0]))v.push_back("1");
		if(k == "Abcdef")break;
		v.push_back(k);
	}
	map<string,int> mp;
	int now = 0;
	
//	for(auto it:v)cout<<it<<' ';cout<<endl;
	
	map<string,int> ans = rec(v,now,mp);

	cout<<cop<<'\n';
	for(auto it:ans){
		cout<<it.fs<<':'<<it.sc<<'\n';
	}
	return 0;
}

