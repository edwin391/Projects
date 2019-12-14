public class Solution {
    public void sort(int arr[], int l, int r) {
        System.out.println("splitting l r: " + l + " " + r);
        if(l < r) {
            //find middle point
            int m = (l + r) / 2;

            //sort first and second halves
            sort(arr, l, m);
            sort(arr, m+1, r);

            //merge the sorted halves
            merge(arr,l,m,r);
        }
    }

    public void merge(int arr[], int l, int m, int r) {
        System.out.println("merge l m r: " + l + " " + m + " " + r);
        //find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;
        //create temp arrays
        int L[] = new int [n1];
        int R[] = new int [n2];
        //copy data to temp arrays
        for(int i = 0; i<n1; ++i)
            L[i] = arr[l + i];
        for(int j = 0; j<n2; ++j)
            R[j] = arr[m + 1 + j];
    }
}

/*@Test
public void Sort() throws Exception{
    int arr[] {4,7,14,1,3,9,17};
    int l = 0;
    int r = arr.length-1;
    mergeSort.sort(arr,l,r);
}*/


































