/*Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), 
having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum. */

long long countTriplets(long long nums[], int n, long long sum)
	{
	    // Your code goes here
	    sort(nums, nums+n);
	    long long res = 0;
	    for(int i=0;i<n;i++) {
	        int start = i+1, end = n -1;
	        while(start < end) {
	            if(nums[i] + nums[start] + nums[end] < sum) {
	                res+=end - start;
	                start++;
	            }
	            else
	                end--;
	        }
	    }
	    return res;
	}

