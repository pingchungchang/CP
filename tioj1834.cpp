#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


class Cmp2{
	public:
		bool operator()(string &a,string &b)const{
			return (a.size() == b.size()?a>b:a.size()>b.size());
		}
};
class Cmp1{
	public:
		bool operator()(string &a,string &b)const{
			return (a.size() == b.size()?a<b:a.size()<b.size());
		}
};

priority_queue<string,vector<string>,Cmp1> pq1;
priority_queue<string,vector<string>,Cmp2> pq2;
vector<string> stk;
queue<string> que;

inline void WA(){
	cout<<"イヤ...やめてよ...お兄ちゃん...壊れる\n";
	return;
}

inline void mv(int from,int to){
	string tmp;
	if(from == 1){
		if(stk.empty()){
			//WA();
			return;
		}
		tmp = stk.back();
		stk.pop_back();
	}
	else if(from == 2){
		if(que.empty()){
			//WA();
			return;
		}
		tmp = que.front();
		que.pop();
	}
	else if(from == 3){
		if(pq1.empty()){
			//WA();
			return;
		}
		tmp = pq1.top();
		pq1.pop();
	}
	else{
		if(pq2.empty()){
			//WA();
			return;
		}
		tmp = pq2.top();
		pq2.pop();
	}
	if(to == 1){
		stk.push_back(tmp);
	}
	else if(to == 2)que.push(tmp);
	else if(to == 3)pq1.push(tmp);
	else pq2.push(tmp);
	return;
}

inline void take(int tp){
	string tmp;
	if(tp == 1){
		if(stk.empty()){
			WA();
			return;
		}
		tmp = stk.back();
		stk.pop_back();
	}
	else if(tp == 2){
		if(que.empty()){
			WA();
			return;
		}
		tmp = que.front();
		que.pop();
	}
	else if(tp == 3){
		if(pq1.empty()){
			WA();
			return;
		}
		tmp = pq1.top();
		pq1.pop();
	}
	else{
		if(pq2.empty()){
			WA();
			return;
		}
		tmp = pq2.top();
		pq2.pop();
	}
	cout<<tmp<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	while(cin>>q){
		while(!pq1.empty())pq1.pop();
		while(!pq2.empty())pq2.pop();
		while(!stk.empty())stk.pop_back();
		while(!que.empty())que.pop();
		while(q--){
			string tp;
			cin>>tp;
			if(tp == "ダメよ～ダメダメ"){
				int x;
				string y;
				cin>>x>>y;
				if(x == 1)stk.push_back(y);
				else if(x == 2)que.push(y);
				else if(x == 3)pq1.push(y);
				else pq2.push(y);
			}
			else if(tp == "しかしお兄ちゃんはわりと弱気だからなぁ……アタシの方からアプローチしないとダメかな"){
				int a,b;
				cin>>a>>b;
				mv(a,b);
			}
			else if(tp == "くやしい…！でも…感じちゃう！"){
				int k;
				cin>>k;
				take(k);
			}
			else assert(false);
		}
	}
	return 0;
}
