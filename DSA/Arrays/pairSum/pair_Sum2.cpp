#include<iostream>
#include<vector>
using namespace std;

vector<int>pairSum2(vector<int>nums,int target){//O(n)
    vector<int>ans;
    //using 2 pointer approach
    int left=0;
    int right=nums.size()-1;
    while (left<right){
        int sum=nums[left]+nums[right];
        if(sum==target){
            ans.push_back(left);
            ans.push_back(right);
            return ans;
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums={2,7,11,15};
    int target=26;

    vector<int> result=pairSum2(nums,target);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}

//ans:2,3

