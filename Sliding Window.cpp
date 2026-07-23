/* Sliding Window is a Way of Solving Problems related to contigious fixed size subarray,substring in finding min,max,sum etc. in which
we are mainting window size by taking two pointers and at every step we are decreasing left pointer and increasing right pointer
to get next window.

There are two Types of Sliding Window:-
  (i) Fixed size where size of window is fixed like k=3,k=4.
  (ii) Variable size where size of window is not fixed it depends on conditions.
*/

//1- Maximum Sum Subarray size K 

#include<iostream>
#include<vector>
using namespace std;
int subarraysum(vector<int>&nums,int k){
    int n=nums.size();
    int windowsum=0;
    for(int i=0;i<k;i++){
        windowsum=windowsum+nums[i];
    }
    int maxans=windowsum;
    for(int j=k;j<n;j++){
        windowsum=windowsum+nums[j];
        windowsum=windowsum-nums[j-k];
        maxans=max(windowsum,maxans);
    }
    return maxans;
}
int main(){
    int k;
    vector<int>nums={100,200,300,400};
    cout<<subarraysum(nums,2);
}
------------------------------------------------------------------------------------
  //2- Minimum Sum Subarray Size K

  #include<iostream>
#include<vector>
using namespace std;
int subarraysum(vector<int>&nums,int k){
    int n=nums.size();
    int windowsum=0;
    for(int i=0;i<k;i++){
        windowsum=windowsum+nums[i];
    }
    int minans=windowsum;
    for(int j=k;j<n;j++){
        windowsum=windowsum+nums[j];
        windowsum=windowsum-nums[j-k];
        minans=min(windowsum,minans);
    }
    return minans;
}
int main(){
    int k;
    vector<int>nums={100,200,300,400};
    cout<<subarraysum(nums,2);
}
--------------------------------------------------------------------------------------------
  //3- Maximum Consecutive Ones

  #include<iostream>
#include<vector>
using namespace std;
int maxxount1(vector<int>&nums){
    int n=nums.size();
    int curr_count=0;
    int max_count=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1)
        curr_count++;
        else{
            max_count=max(curr_count,max_count);
            curr_count=0;
        }
    }
    return max(max_count,curr_count);
}
int main(){
    vector<int>nums={1,1,0,1,1,1,1};
    cout<<maxxount1(nums);
}
--------------------------------------------------------------------------------------------------
  //4- Maximum Consecutive Sum |||

  #include<iostream>
#include<vector>
using namespace std;
int consecutive1(vector<int>&nums,int k){
    int n=nums.size();
    int left=0;
    int zero_count=0;
    for(int right=0;right<n;right++){
        if(nums[right]==0)
        zero_count++;
        if(zero_count>k){
            if(nums[left]==0)
            zero_count--;
            left++;
        }
    }
    return n-left;
}
int main(){
    int k;
    vector<int>nums={1,1,1,0,1,1,1,1,0,1,1,1,0};
    cout<<consecutive1(nums,2);
}
-----------------------------------------------------------------------------------------------------
//5- Subarray Product less than k

  #include<iostream>
#include<vector>
using namespace std;
int subaarayprod(vector<int>&nums,int k){
    int n=nums.size();
    int prod=1;
    int count=0;
    int left=0;
    if(k<=1)
    return 0;
    for(int right=0;right<n;right++){
        prod=prod*nums[right];
        while(prod>=k){
            prod=prod/nums[left]; //removing left from window, adding upcoming left
            left++;
        }
        count=count+right-left+1;
    }
    return count;
}
int main(){
    vector<int>nums={10,5,2,6};
    int k;
    cout<<subaarayprod(nums,100);
}
------------------------------------------------------------------------------------------------
//6- Minimum Size Subarray Sum

  #include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minsubarraysum(vector<int>&nums,int target){
    int n=nums.size();
    int left=0;
    int sum=0;
    int ans=INT_MAX;
    for(int right=0;right<n;right++){
        sum=sum+nums[right];
        while(sum>=target){
            ans=min(ans,right-left+1);        //right-left+1 is the window size of sum>=target
            sum=sum-nums[left];               // after finding one such window we are finding other window where window size even smaller
            left++;
        }
    }
    return(ans==INT_MAX)?0:ans;              // if no subarray such found then return 0 else return 1.
}
int main(){
    int target;
    vector<int>nums={2,3,1,2,4,3};
    cout<<minsubarraysum(nums,7);
}
