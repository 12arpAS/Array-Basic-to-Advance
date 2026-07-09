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

#4- Note while insertion alway use a[100] in normal array

------------------------------------------------------------------------------------------


























  
