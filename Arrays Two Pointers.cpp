//1- Remove Duplicates From Sorted Array

#include<iostream>
#include<vector>
using namespace std;
int removeduplicates(vector<int>&nums){
    int n=nums.size();
    int i=0;
    int j=i+1;
    while(j<n){
        if(nums[i]!=nums[j])
        {
            i++;
            nums[i]=nums[j];
        }
        j++;
    }
    return i+1;
}
int main(){
    vector<int>nums={0,0,1,1,2,2,3,3};
    cout<<removeduplicates(nums);
}
------------------------------------------------------------------------------------------

  //2-Two Sum ||

  #include<iostream>
#include<vector>
using namespace std;
vector<int>TwoSum(vector<int>&nums,int target){
    int n=nums.size();
    int i=0;
    int j=n-1;
    while(i<j){
        int sum=nums[i]+nums[j];
        if(sum==target)
        return {i+1,j+1};
        else if(sum<target)
        i++;
        else
        j--;
    }
    return {-1,-1};
}
int main(){
    int target;
    vector<int>nums={2,7,9,13,28};
    vector<int>ans=TwoSum(nums,9);
    cout<<ans[0]<<" "<<ans[1];
}
---------------------------------------------------------------------------
  //3- Move Zeroes 

  #include<iostream>
#include<vector>
using namespace std;
void movezeroes(vector<int>&nums){
    int n=nums.size();
    int i=0;
    int j=0;
    while(j<n){
        if(nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
    }
    for(int i=0;i<n;i++)
    cout<<nums[i]<<" ";
}
int main(){
    vector<int>nums={0,1,0,2,13,0,0,39};
    movezeroes(nums);
}
---------------------------------------------------------------------------------
  //4- Vallid Pallindrome

  #include<iostream>
#include<vector>
using namespace std;
bool validpallindrome(vector<int>&nums){
    int n=nums.size();
    int i=0;
    int j=n-1;
    while(i<j){
        if(nums[i]!=nums[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int main(){
    vector<int>nums={1,2,2,1};
    cout<<validpallindrome(nums);
}
-------------------------------------------------------------------------------------
  //5- Square of Sorted Array

  #include<iostream>
#include<vector>
using namespace std;
vector<int>sorted(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n);
    int i=0;
    int j=n-1;
    int k=n-1;
    while(i<=j){
        int left=nums[i]*nums[i];
        int right=nums[j]*nums[j];
        if(left>right){
            ans[k]=left;
            i++;
        }
        else{
            ans[k]=right;
            j--;
        }
        k--;
    }
    return ans;
}
int main(){
    vector<int>nums={-7,-3,2,3,11};
    vector<int>result=sorted(nums);
    for(int i=0;i<result.size();i++)
    cout<<result[i]<<" ";
}
-----------------------------------------------------------------------------------
 //6- Container With Most Water

  #include<iostream>
#include<vector>
using namespace std;
int maxwatercontains(vector<int>&nums){
    int n=nums.size();
    int i=0;
    int j=n-1;
    int maxwater=0;
    while(i<j){
        int w=j-i;
        int h=min(nums[i],nums[j]);
        int area=h*w;
        maxwater=max(maxwater,area);
        if(nums[i]<nums[j])
        i++;
        else
        j--;
    }
    return maxwater;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    cout<<maxwatercontains(nums);
}

-----------------------------------------------------------------
  //7- Three Sum 

  #- ThreeSum (Optimized Approach)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>Threesum(vector<int>&nums){
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])
        continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0)
            j++;
            else if(sum>0)
            k--;
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])
                j++;
            }
        }
    }
    return ans;
}
int main(){
    vector<int>nums={-1,-2,3,-1,-2,-3,0};
    vector<vector<int>>result=Threesum(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
    }
}

---------------------------------------------------------------------------------------------
