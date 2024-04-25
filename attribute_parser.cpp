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

struct node{
	string type;
	node* pre;
	map<string,node*> mp;
	string val;
	node(){}
	node(string s){
		type = "val";
		val = s;
		return;
	}
};
int main(){
	io
	int n,q;
	cin>>n>>q;
	cin.ignore();
	node* root = new node();
	stringstream ss;
	node* now = root;
	while(n--){
		string in;
		getline(cin,in);
//		return 0;
		if(in[1] == '/'){
			now = now->pre;
			continue;
		}
		ss.clear();
		in[0] = in.back() = ' ';
		ss<<in;
		string name;
		ss>>name;
		auto tt = now;
		now->mp[name] = new node();
		now = now->mp[name];
		now->type = "tag";
		now->pre = tt;
		string tmp;
		while(ss>>in){
			tmp += in;
			if(tmp.back() == '"'){
				string a,b;
				bool flag = false;
				for(auto &i:tmp){
					if(i == '='&&flag == false){
						flag = true;
					}
					else if(i == '"')continue;
					else if(flag)b += i;
					else a += i;
				}
				now->mp[a] = new node(b);
				tmp.clear();
			}
		}
	}
	while(q--){
		string in;
		getline(cin,in);
		for(auto &i:in){
			if(i == '.'||i == '~')i = ' ';
		}
		stringstream ss(in);
		node* now = root;
		bool flag = true;
		while(ss>>in){
			if(!now||now->mp.count(in) ==0){
				flag = false;
				break;
			}
			else now = now->mp[in];
		}
		if(flag == false||now->type == "tag"){
			cout<<"Not Found!\n";
		}
		else cout<<now->val<<'\n';
	}
}

