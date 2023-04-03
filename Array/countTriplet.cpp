/*Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), 
having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum. */
#include<bits/stdc++.h>
using namespace std;

long long countTriplets(long long nums[], int n, long long sum){
	sort(nums, nums+n);
	long long res = 0;
	for(int i=0;i<n;i++) {
		int start = i+1, end = n -1;
		while(start < end) {
			if(nums[i] + nums[start] + nums[end] < sum) { // when smaller which is what we needed then count the numbers 
					res+=end - start;                         // the triplet will be {i,start,{from start to end}}, since end was larget and 
					start++;                                  // with that we get sum smaller then elements before end which is smaller than end 
			}                                             // obviously will have sum smaller than with the end;
			else
				end--; // if sum is equal to or larget to given sum then decrease the largest element which is end.
		}
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	long long nums[n];
	for(auto &i:nums) cin>>i;
	int sum;
	cout<<"Enter sum : ";
	cin>>sum;
	cout<<countTriplets(nums,n,sum);

}

