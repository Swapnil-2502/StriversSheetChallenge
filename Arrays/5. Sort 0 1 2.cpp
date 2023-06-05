#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //Optimal
   //Using three pointers low,mid,high
   // Finally array should look like:
   // 0 -> low-1 ----> all zeroes
   // low -> mid-1 -----> all ones
   // high+1 -> n-1 -----> all twos

   int low = 0,mid=0,high=n-1;

   while(mid<=high){
      if(arr[mid] == 0){
         swap(arr[mid],arr[low]);
         mid++;low++;
      }
      else if(arr[mid] == 1) mid++;

      else{
         swap(arr[mid],arr[high]);
         high--;
      }
   }
   // //TC = O(N) just single N
   // //SC = O(1)
   
   
   
   // //Better 
   // int count_0 = 0,count_1 = 0, count_2 = 0;

   // for(int i=0;i<n;i++){
   //    if(arr[i] == 0) count_0++;
   //    else if(arr[i] == 1) count_1++;
   //    else count_2++;
   // }

   // for(int i=0;i<count_0;i++) arr[i] = 0;

   // for(int i=count_0;i<count_0+count_1;i++) arr[i] = 1;

   // for(int i=count_0+count_1;i<n;i++) arr[i] = 2;

   // //TC = O(N + N)
   // //SC = O(1)

   
}