#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a;
    int b;
    vector<int> max;
    int big = 0;
    cin >> a >> b;
    for (int i = 0; i < a;i++){
        vector<int> nums;
        for (int j = 0; j < b;j++){
            int k;
            cin >> k;
            nums.push_back(k);
        }
        sort(nums.begin(), nums.end());
        max.push_back(nums[b - 1]);
        big += nums[b - 1];
    }
    cout << big << endl;
    vector<int> op;
    for (int i = 0; i < max.size();i++){
        if(big % max[i]==0){
            op.push_back(max[i]);
        }
    }
    if(op.size()==0){
        cout << "-1";
    }
    else{
        for (int i = 0; i < op.size()-1;i++){
            cout << op[i] << ' ';
        }
        cout << op[op.size() - 1];
    }
}