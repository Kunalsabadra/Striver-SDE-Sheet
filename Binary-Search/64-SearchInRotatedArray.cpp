//Optimised Approaxg Using Binary Search
//T.C: o(LogN)
//S.C:O(1)
int search(int* arr, int n, int key) {
       int low = 0 , high = n-1;

       while(low < high){
             int mid = low + (high-low)/2;

             if(arr[mid] == key) return mid;

             //Left array Sorted Checking
              if(arr[low] <= arr[mid]){
                    if(arr[low] <= key and key <= arr[mid])  high = mid;
              
              else{
                  low = mid+1;
              }

       }
       //right part is sorted
       else{
             
             if(arr[mid] <= key and key <= arr[high]){
                    low = mid+1;
             }
             else{
                  high = mid;
             }

       }
       }
       if(arr[low] == key) return low;
       else return -1;
}
