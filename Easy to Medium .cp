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
6-# Sort colors Problems(Brute Force)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sorts(vector<int>&nums){
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    cout<<nums[i]<<" ";
}
int main(){
    vector<int>nums={0,1,2,1,0,2,2,0,1,0,1,2,0,0};
    sorts(nums);
}

#- Sort Colors (Optimized Approach)

#include<iostream>
#include<vector>
using namespace std;
void sortcolors(vector<int>&nums){
    int n=nums.size();
    int count0=0; int count1=0; int count2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0)
        count0++;
        else if(nums[i]==1)
        count1++;
        else
        count2++;
    }
    int idx=0;
    for(int i=0;i<count0;i++)
    nums[idx++]=0;
    for(int i=0;i<count1;i++)
    nums[idx++]=1;
    for(int i=0;i<count2;i++)
    nums[idx++]=2;
    for(int i=0;i<n;i++)
    cout<<nums[i]<<" ";
}
int main(){
    vector<int>nums={0,1,2,0,1,2,0,1,2,2,1,0};
    sortcolors(nums);
}

------------------------------------------------------------------------------------------

#- Sort Colors (Optimal Approach)
#include<iostream>
#include<vector>
using namespace std;
void sortcolors(vector<int>&nums){
    int n=nums.size();
    int mid=0;
    int high=n-1;
    int low=0;
    while(mid<=high){
        if(nums[mid]==0){
        swap(nums[low],nums[mid]);
        low++;
        mid++;
        }
        else if(nums[mid]==1)
        mid++;
        else{
            swap(nums[high],nums[mid]);
            high--;
        }
    }
    for(int i=0;i<n;i++)
    cout<<nums[i]<<" ";
}
int main(){
    vector<int>nums={0,1,2,0,1,2,0,1,2};
    sortcolors(nums);
}
-------------------------------------------------------------------------------------------------------------------------------

7- #Merge Two Sorted Arrays (Optimal Solution)

#include<iostream>
#include<vector>
using namespace std;
void mergetwo(vector<int>A,int m,vector<int>B,int n){
    int i=m-1;
    int j=n-1;
    int idx=(m+n)-1;
    while(i>=0 && j>=0){
        if(A[i]>B[j]){
            A[idx]=A[i];
            idx--;
            i--;
        }
        else{
            A[idx]=B[j];
            idx--;
            j--;
        }
    }
    while(j>=0){
        A[idx]=B[j];
        idx--;
        j--;
    }
    for(int i=0;i<A.size();i++)
    cout<<A[i]<<" ";
}
int main(){
    vector<int>A={1,2,3,0,0,0};
    vector<int>B={4,5,6};
    mergetwo(A,3,B,3);
}

-------------------------------------------------------------------------------------------------------------------------

8- # Two Sum Problem (Brute Force Approach)

#include<iostream>
#include<vector>
using namespace std;
vector<int>twosum(vector<int>& nums,int target){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        int f=nums[i];
        for(int j=i+1;j<n;j++){
            int s=nums[j];
            sum=nums[i]+nums[j];
            if(sum==target)
            return {i,j};
        }

    }
    return {-1,-1};
}
int main(){
    vector<int>nums={1,2,3,4,5};
    int target;
    vector<int>res=twosum(nums,6);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
}

#- Two Sum Optimal Approach(Two Pointers)

#include<iostream>
#include<vector>
using namespace std;
vector<int>Twosum(vector<int>&nums,int target){
    int n=nums.size();
    int l=0;
    int r=n-1;
    while(l<r){
        int sum=nums[l]+nums[r];
        if(sum==target)
        return {l,r};
        else if(sum<target)
        l++;
        else
        r--;
    }
    return {-1,-1};
}
int main(){
    vector<int>nums={1,2,3,4,5};
    int target;
    vector<int>res=Twosum(nums,9);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
}

#- Two Sum Optimized Approach(Unordered_map)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>Twosum(vector<int>&nums,int target){
    int n=nums.size();
    //vector<int>ans;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        int f=nums[i];
        int s=target-f;
        if(m.find(s)!=m.end()){
            return {m[s],i};
        }
        m[f]=i;
    }
    return {-1,-1};
}
int main(){
    vector<int>nums={1,2,3,4,5};
    int target;
    vector<int>res=Twosum(nums,9);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
}

-------------------------------------------------------------------------------------------------------------------------------

9- # Find Duplicates in Array(Brute Force Approach)

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int findduplicates(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j])
            return nums[i];
        }
    }
    return -1;
}
int main(){
    vector<int>nums={1,2,2,3,4,5};
    cout<<findduplicates(nums);
}

#- Find Duplicates in Array(Optimal using unordered_set)

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int findduplicates(vector<int>&nums){
    int n=nums.size();
    unordered_set<int>m;
    for(int i=0;i<n;i++){
        if(m.find(nums[i])!=m.end())
        return nums[i];
        m.insert(nums[i]);
    }
    return -1;
}
int main(){
    vector<int>nums={1,2,2,3,4,5};
    cout<<findduplicates(nums);
}

#- Find Duplicates in Array (Optimal Solution)

#include<iostream>
#include<vector>
using namespace std;
int findduplicates(vector<int>&nums){
    int n=nums.size();
    int slow=nums[0];
    int fast=nums[0];
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    }while(slow!=fast);
    
    slow=nums[0];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}
int main(){
    vector<int>nums={1,2,2,3,4};
    cout<<findduplicates(nums);
}

----------------------------------------------------------------------------------------------------------

10-# Threesum Problem (Brute Force)

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>>Threesum(vector<int>&nums){
    int n=nums.size();
    vector<vector<int>>ans;
    set<vector<int>>res;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());                 // sort to remove duplicate permutations of triplets.
                    if(res.find(temp)==res.end()){
                    res.insert(temp);
                    ans.push_back(temp);
                    }
                }
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

-----------------------------------------------------------------------------------------------------------------------------

11- # Subarray Sum Equals K (Brute Force Approach)

#include<iostream>
#include<vector>
using namespace std;
int subarraysum(vector<int>&nums,int k){
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==k)
            count++;
        }
    }
    return count;
}
int main(){
    vector<int>nums={1,2,3};
    int k;
    cout<<subarraysum(nums,3);
}

#- Subarray Sum Equals K (Optimized Approach)

















