#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    string s;
    cin>>s;
    int a =0;
    vector<int> c1(26,0);
    int atimes = 1;
    for(int i =0;i<s.size();i++){
        c1[s[i]-'a'] +=1;
    }
    unordered_map<int,int> nums;
    for(int i =0;i<26;i++){
        if(c1[i] !=0){
            if(nums.empty()){
                nums[c1[i]] = 1;
                nums[c1[i]+1] = 0;
                nums[c1[i]-1] = 0;
                a = c1[i];
            }
            else if(nums.count(c1[i])==0){
                cout<<"NO";
                return 0;
            }
            else{
                nums[c1[i]] ++;
                atimes ++;
            }
        }
    }
    vector<int> v;
    v.push_back(nums[a-1]);
    v.push_back(nums[a]);
    v.push_back(nums[a+1]);
    if(v[0] ==0){
        if(v[2]!=0&&v[2]!=1){
            cout<<"NO";
            return 0;
        }
        else{
            cout<<"YES";
            return 0;
        }
    }
    else if(v[2] == 0){
        if(v[1] == 1){
            cout<<"YES";
            return 0;
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    else{
        cout<<"NO";
        return 0;
    }
}
