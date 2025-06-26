class Solution {
    void merge(int arr[], int start1, int end1, int start2, int end2) {
        int m = end1-start1+1;
        int n = end2-start2+1;
        
        int[] arr1 = new int[m];
        int[] arr2 = new int[n];
        
        for(int i=0;i<m;i++) {
            arr1[i] = arr[i+start1];
        }
        for(int i=0;i<n;i++) {
            arr2[i] = arr[i+start2];
        }
        
        int i = 0, j=0, start = start1;
        
        while(i<m || j<n) {
            if(i>=m && j<n) {
                arr[start++] = arr2[j++];
            }
            else if(j>=n && i<m) {
                arr[start++] = arr1[i++];
            }
            else if(arr1[i]<arr2[j]) {
                arr[start++] = arr1[i++];
            }
            else arr[start++] = arr2[j++];
        }
        
    }

    void mergeSort(int arr[], int l, int r) {
        // code here
        if(l==r) return;
        
        
        int mid = l+(r-l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, mid, mid+1, r);
        
    }
}