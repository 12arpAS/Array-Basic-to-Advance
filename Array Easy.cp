#1- Inserting element at begining
---------------------------------------------------------------------------
1- Normal Way
  
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100], key;
    // Input array
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // Element to insert
    cin >> key;
    // Shift elements to the right
    for (int i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }
    // Insert at first position
    a[0] = key;
    // Increase array size
    n++;
    // Print updated array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

2- Function Way

#include<iostream>                                                            
#include<vector>
using namespace std;
void insertion(vector<int>&nums,int key){
    int n=nums.size();
    nums.resize(n+1);
    for(int i=n;i>0;i--)
    nums[i]=nums[i-1];
    nums[0]=key;                     
    for(int i=0;i<n+1;i++)
    cout<<nums[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    int key;
    cin>>key;
    insertion(nums,key);
}
---------------------------------------------------------------------------------
#2- Inserting at last position
---------------------------------------------------------------------------------
1- Normal Way

  #include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100], key;
    // Input array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Element to insert
    cin >> key;
    // Insert at last position
    a[n] = key;
    n++;
    // Print updated array
    for (int i = 0; i < n; i++) {
       cout << a[i] << " ";
    }
    return 0;
}

2- Fucntion Way
  
#include<iostream>
#include<vector>
using namespace std;
void lastinsertion(vector<int>&nums,int key){
    int n=nums.size();
    nums.resize(n+1);
    nums[n]=key;
    for(int i=0;i<n+1;i++)
    cout<<nums[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    int key;
    cin>>key;
    lastinsertion(nums,key);
}
---------------------------------------------------------------------------------------
#3- Anyposition Insertion
---------------------------------------------------------------------------------------

1- Normal Way

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[100],key,pos;
    for(int i=0;i<n;i++)         // While inserting in normal array use arr[100].
    cin>>a[i];
    if(pos < 1 || pos > n)
    {
        cout << "Invalid Position";
        return 0;
    }
    cin>>key;
    cin>>pos;
    for(int i=n;i>=pos;i--)
    a[i]=a[i-1];
    a[pos-1]=key;
    n++;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

}

2- Fucntion Way

  
#include<iostream>
#include<vector>
using namespace std;
void anyposition(vector<int>&nums,int key,int pos){
    int n=nums.size();
    nums.resize(n+1);
    for(int i=n;i>=pos;i--)
    nums[i]=nums[i-1];
    nums[pos-1]=key;
    for(int i=0;i<n+1;i++)
    cout<<nums[i]<<" ";
    
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    int key;
    cin>>key;
    int pos;
    cin>>pos;
    anyposition(nums,key,pos);
}

#- Note while insertion alway use a[100] in normal array

------------------------------------------------------------------------------------------
#4- Deletion First position element
------------------------------------------------------------------------------------------
 (1) Normal Way

#include<iostream>
using namespace std;
int main(){
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    a[i-1]=a[i];
    for(int i=0;i<n;i++)
    cout<<a[i];

}

(2) Function Way Part 1

#include<iostream>
#include<vector>
using namespace std;
void deletefirst(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n-1;i++)
    nums[i]=nums[i+1];
    nums.pop_back();
    for(int i=0;i<nums.size();i++)
    cout<<nums[i]
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    deletefirst(nums);
}

(3) Function way Part 2

#include<iostream>
#include<vector>
using namespace std;
void deletefirst(vector<int>&nums){
    int n=nums.size();
    nums.erase(nums.begin())
    for(int i=0;i<nums.size();i++)
    cout<<nums[i]
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    deletefirst(nums);
}

---------------------------------------------------------------------

#2- Deletion Last Element

(1) Normal Way

#include<iostream>
using namespace std;
int main(){
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n-1;i++)
    cout<<a[i];
}

(2)- Fucntion Way Part 1

#include<iostream>
#include<vector>
using namespace std;
void deletelast(vector<int>&nums){
    int n;
    n=nums.size();
    for(int i=0;i<n-1;i++)
    cout<<nums[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    deletelast(nums);
}

(3) Function way Part 2

#include<iostream>
#include<vector>
using namespace std;
void deletelast(vector<int>&nums){
    int n;
    n=nums.size();
    nums.pop_back();
    for(int i=0;i<nums.size();i++)
    cout<<nums[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    deletelast(nums);
}

#3- Delete any ELement 

(1) Normal Way

#include<iostream>
using namespace std;
int main(){
    int a[100];
    int n;
    cin>>n;
    int pos;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>pos;
    for(int i=pos-1;i<n-1;i++)
    a[i]=a[i+1];
    n--;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

(2) Funciton way Part 1

#include<iostream>
#include<vector>
using namespace std;
void anydelete(vector<int>&a,int pos){
    int n=a.size();
    if(pos<1 || pos>n+1){
    cout<<"Invalid";
    return;
    }
    for(int i=pos-1;i<n-1;i++)
    a[i]=a[i+1];
    n--;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int pos;
    cin>>pos;
    anydelete(a,pos);
}

# Function way part 2

#include<iostream>
#include<vector>
using namespace std;
void anydelete(vector<int>&nums,int pos){
    int n=nums.size();
    if(pos<1 || pos>n){
    cout<<"invalid";
    return;
    }
    nums.erase(nums.begin()+pos-1);
    for(int i=0;i<nums.size();i++)
    cout<<nums[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    int pos;
    cin>>pos;
    anydelete(nums,pos);
}

----------------------------------------------------------------

































  
