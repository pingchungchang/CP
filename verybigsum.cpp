#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> v;
    int longest = 0;
    for (int i = 0; i < N;i++){
        string s;
        cin >> s;
        v.push_back(s);
        if(s.size()>longest){
            longest = s.size();
        }
    }
    vector<int> sum;
    int add = 0;
    for (int i = 1; i <= longest;i++){
        int num = add;
        add = 0;
        for (int j = 0; j < v.size();j++){
            if(v[j].size()>=i){
                num += v[j][v[j].size() - i] - '1' + 1;
            }
        }
        add = num / 10;
        sum.push_back(num % 10);
    }
    if(add!=0) sum.push_back(add);
    for (int i = sum.size()-1; i >=0;i--){
        cout << sum[i];
    }
}