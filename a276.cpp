#include <bits/stdc++.h>
using namespace std;

stringstream ss;
bool not_done = true;
void solve(){
	string s;
	vector<stack<string>> v(52);
	for(int i = 0;i<52;i++){
		cin>>s;
		if(s == "#"){
			not_done = false;
			return;
		}
		v[i].push(s);
	}
	bool done =false;
	for(int asd = 0;asd<52*52;asd++){
		if(v.size()==1||done)break;
		for(int i = 1;i<v.size();i++){
			if(i>=3){
				if(v[i-3].top()[0] == v[i].top()[0]||v[i-3].top()[1]==v[i].top()[1]){
					v[i-3].push(v[i].top());
					v[i].pop();
					if(v[i].empty()){
						v.erase(v.begin()+i);
					}
					break;
				}
			}
			if(v[i-1].top()[0] == v[i].top()[0] ||v[i-1].top()[1] == v[i].top()[1]){
				v[i-1].push(v[i].top());
				v[i].pop();
				if(v[i].empty())v.erase(v.begin()+i);
				break;
			}
			if(i ==51)done = true;
		}
	}
	cout<<v.size()<<" pile";
	if(v.size()>1)cout<<"s";
	cout<<" remaining: ";
	for(auto &i:v){
		cout<<i.size()<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	while(not_done)solve();
}
