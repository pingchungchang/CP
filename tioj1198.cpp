#include <bits/stdc++.h>
using namespace std;

string s;
set<string> st;
pair<int,int> findnum(vector<vector<int>> &v,int k){
	for(int i =0 ;i<3;i++)for(int j = 0;j<3;j++)if(v[i][j] == k)return make_pair(i,j);
	return make_pair(-1,-1);
}
bool done(vector<vector<int>> &v){
	int now = 1;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			if(v[i][j] != now)return false;
			now++;
			now = now%9;
		}
	}
	return true;
}

string tos(vector<vector<int>> v){
	string sss;
	for(int i = 0;i<=2;i++)for(int j= 0;j<=2;j++)sss += v[i][j]+'0';
	return sss;
}
vector<vector<int>> tov(string s){
	int now =0;
	vector<vector<int>> v(3,vector<int>(3));
	for(int i =0;i<3;i++){
		for(int j = 0;j<3;j++){
			v[i][j] = s[now]-'0';
			now++;
		}
	}
	return v;
}
void pv(vector<vector<int>> v){
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++)cout<<v[i][j]<<' ';
		cout<<'\n';
	}
	cout<<endl;
}

int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	stringstream ss;
	ss<<s1;
	vector<vector<int>> v(3,vector<int>(3,0));
	for(int i = 0;i<3;i++)for(int j = 0;j<3;j++)ss>>v[i][j];
	ss.clear();
	ss<<s2;
	s2 = "";
	for(int i = 0;i<9;i++){
		string k;
		ss>>k;
		s2 += k;
	}
//	cout<<s2<<'\n';
//	return 0;
	queue<pair<int,string>> q;
	q.push(make_pair(0,tos(v)));
	st.insert(tos(v));
	while(!q.empty()){
		int t= q.front().first;
		string now = q.front().second;
		if(now == s2){
			cout<<t;
			return 0;
		}
		q.pop();
		v = tov(now);
		pair<int,int> pos = findnum(v,0);
		cout<<t<<endl;
		pv(v);
		if(pos.first != 0){
			swap(v[pos.first-1][pos.second],v[pos.first][pos.second]);
			if(st.find(tos(v)) == st.end()){
				st.insert(tos(v));
				q.push(make_pair(t+1,tos(v)));
			}
			swap(v[pos.first-1][pos.second],v[pos.first][pos.second]);
		}
		if(pos.first != 2){
			swap(v[pos.first+1][pos.second],v[pos.first][pos.second]);
			if(st.find(tos(v)) == st.end()){
				st.insert(tos(v));
				q.push(make_pair(t+1,tos(v)));
			}
			swap(v[pos.first+1][pos.second],v[pos.first][pos.second]);			
		}
		if(pos.second != 2){
			swap(v[pos.first][pos.second+1],v[pos.first][pos.second]);
			if(st.find(tos(v)) == st.end()){
				st.insert(tos(v));
				q.push(make_pair(t+1,tos(v)));
			}
			swap(v[pos.first][pos.second+1],v[pos.first][pos.second]);			
		}
		if(pos.second != 0){
			swap(v[pos.first][pos.second-1],v[pos.first][pos.second]);
			if(st.find(tos(v)) == st.end()){
				st.insert(tos(v));
				q.push(make_pair(t+1,tos(v)));
			}
			swap(v[pos.first][pos.second-1],v[pos.first][pos.second]);			
		}
	}
	
}
