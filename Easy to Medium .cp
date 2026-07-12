1- # Maximum SubArray Sum (Brute Force)
  ---------------------------------------------
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxsumsub(vector<int>&nums){
    int max_sum=0;
    int curr_sum;
    for(int i=0;i<nums.size();i++){
        curr_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            max_sum=max(curr_sum,max_sum);
        }
    }
    return max_sum;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    cout<<maxsumsub(nums);
}


# Maximum SubArray Sum Optimized (Kdanes Algorithm)
---------------------------------------------------------
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxsubsum(vector<int>&nums){
    int n=nums.size();
    int curr_sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++){
    curr_sum+=nums[i];
    max_sum=max(curr_sum,max_sum);
    if(curr_sum<0)
    curr_sum=0;
    }
    return max_sum;
    
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    cout<<maxsubsum(nums);
}

---------------------------------------------------------------------------------------------------------------------------

2- # Majority Element (Brute Force)
-----------------------------------------------------
  #include<iostream>
#include<vector>
using namespace std;
int majority(vector<int>&nums){
    int n=nums.size();
    int freq=0;
    int count;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(nums[i]==nums[j])
            count++;
        }
        if(count>n/2)
        return nums[i];
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    cout<<majority(nums);
}

# Majority Element Optimized(Moores Algorithm)
-----------------------------------------------

  #include<iostream>
#include<vector>
using namespace std;
int majority(vector<int>&nums){
    int n=nums.size();
    int freq=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(freq==0){
            ans=nums[i];
            freq=1;
        }
        else if(ans==nums[i])
        freq++;
        else
        freq--;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    cout<<majority(nums);
}

--------------------------------------------------------------------------------------------------------------------------
3- # Buy and Sell Stock Problem

#include<iostream>
#include<vector>
using namespace std;
int maxprofit(vector<int>&nums){
    int n=nums.size();
    int MP=0;
    int BB=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]>BB)
        MP=max(MP,nums[i]-BB);
        BB=min(BB,nums[i]);
    }
    return MP;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    cout<<maxprofit(nums);
}

---------------------------------------------------------------------------------------------------------------------

4- # Container with Most water (Brute Force)

  #include<iostream>
#include<vector>
using namespace std;
int maxwater(vector<int>&nums){
    int n=nums.size();
    int maxwater=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int w=j-i;
            int l=min(nums[i],nums[j]);
            int area=l*w;
            maxwater=max(maxwater,area);
        }
    }
    return maxwater;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    cout<<maxwater(nums);
}

# Container with most water Optimized

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

--------------------------------------------------------------------------------------------------------------------------
5- Product of Array Except Self (Brute Force)

#include<iostream>
#include<vector>
using namespace std;
vector<int>product(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n,1);
    for(int i=0;i<n;i++){
        int prod=1;
        for(int j=0;j<n;j++){
            if(i!=j)
            prod=prod*nums[j];
        }
        ans[i]=prod;
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    vector<int>res=product(nums);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    
}

#- Product of Array Except Self Optimized

#include<iostream>
#include<vector>
using namespace std;
vector<int>product(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n,1);
    for(int i=1;i<n;i++)
    ans[i]=ans[i-1]*nums[i-1];
    int suffix=1;
    for(int i=n-2;i>=0;i--){
    suffix*=nums[i+1];
    ans[i]*=suffix;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    vector<int>res=product(nums);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
}

---------------------------------------------------------------------------------------------------------------------------------


