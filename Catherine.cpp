#include "Catherine.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second

namespace NEKO{

int task;
vector<int> route;
int turn;

}  // namespace

void Init(int A, int B) {
	NEKO::task = (A<=2);
	NEKO::turn = 3;
	return;
}

namespace S1{
	int GO(vector<int> v){
		int sum = 0;
		for(auto &i:v)sum += (i?1:0);
		if(sum == 1)return max_element(v.begin(),v.end())-v.begin();
		int s = 0;
		for(int i = 0;i<3;i++){
			if(v[i])s ^= i;
		}
		switch(s){
			case 1:
				return 0;
			case 2:
				return 2;
			case 3:
				return 1;
		}
		assert(false);
		return -1;
	}
}

namespace S2{
	int pre = -1;
	int nt = -1;
	int C0(vector<int> v){
		//cout<<"C0"<<endl;
		int s = 0;
		for(auto &i:v)s += (i!=0);
		if(s == 1){
			return (pre = max_element(v.begin(),v.end())-v.begin());
		}
		else if(s == 0)return -1;
		else return (pre ^= 1);
	}
	int C1(vector<int> v){
		//cout<<"C1"<<endl;
		nt = 0;
		for(int i = 0;i<2;i++){
			if(v[i] == 1)return (pre = i);
		}
		assert(false);
	}
	int C2(vector<int> v){
		//cout<<"C2"<<endl;
		int s = (v[0]?0:1);
		NEKO::turn--;
		if(pre == -1){
			NEKO::route.push_back((v[0]?0:1));
			if(v[1])s = 1;
			else s = 0;
			NEKO::route.push_back(s);
			return (pre = s);
		}
		else if(NEKO::turn>=0){
			NEKO::route.push_back(s);
			return (pre = s);
		}
		else if(NEKO::turn == -1){
			NEKO::route.push_back(s);
			return -1;
		}
		else if(NEKO::turn >= -3){
			return (pre = s);
		}
		string ss;
		for(auto &i:NEKO::route){
			ss += '0'+i;
		}
		//cout<<ss<<endl;
		string t = "100110100110100110";
		assert(ss.size() == 5);
		bool flag = false;
		for(int i = 0;i+ss.size()<=t.size();i++){
			if(t.substr(i,ss.size()) == ss)flag = true;
		}
		nt = 0;
		if(flag)return s;
		else return -1;
	}
	int GO(vector<int> v){
		int re = -2;
		if(!nt)re = C0(v);
		int s = 0;
		for(auto &i:v)s +=i;
		if(re == -2&&s + (pre>=0) != 2){
			if(pre == -1){
				nt = 0;
				pre = re = (v[0]==1?0:1);
			}
			else{
				nt = 0;
				if(v[pre] == 0)re = -1;
				else re = (pre ^= 1);
			}
		}
		if(re == -2)re = C2(v);
		//for(auto &i:v)//cout<<i<<' ';cout<<s<<","<<pre<<":"<<re<<endl;
		return re;
	}
}

int Move(std::vector<int> y) {
	if(NEKO::task)return S2::GO(y);
	else return S1::GO(y);
}
