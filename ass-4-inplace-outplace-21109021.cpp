//Shashwat Rai
//21109021 Production
/*                         
[Ans.1]

IN-PLACE means that the algorithm does not use extra space for manipulating the input but may required
#Examples of in place Sorting Algorithms:) Bubble Sort, Heap Sort, Insertion Sort, Quick Sort, Selection
#(b)

 OUT-PLACE means an algorithm that is not in-place is called a not-in-place or out-of-place algorith
# Usually, this space is O(log n), though sometimes anything in O(n) (Smaller than linear) is allowed.
#The standard merge sort algorithm is an example of out-of-place algorithm as it requires O(n) extra space
#Examples of not in place Algorithms :- Merge Sort, Radix Sort

 */

//[Ans.2]

//Insertion Sort Using In-Place Algorithm
#include <iostream>
using namespace std;
//Creating Insertion Sort void function
void insertion_sort_IP(int arr[],int n){
    //Initialising variables i and j
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}

//Insertion Sort Using Out-Place Algorithm
void insertion_sort_OP(int arr[],int si,int ei){
    //si=starting index
    //ei=ending index
    if(si==ei){return;}
    int j=si+1;
    int temp=arr[j];
    while(si>=0){
        if(arr[si]>temp){
            arr[si+1]=arr[si];
            si--;
        }
        if(si==-1){arr[0]=temp;break;}
        if(arr[si]<=temp){arr[si+1]=temp;break;}
    }
    insertion_sort_OP(arr,si+1,ei);
}
//Function to print array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}
int main(){
    int n;
    //Taking Input array
    cout<<"ENTER NUMBER OF ELEMENTS IN THE ARRAY: ";
    cin>>n;
    int arr[n],arr2[n];//Two array with same size and elements
    cout<<"ENTER ELEMENTS OF ARRAY SEPERATED BY SPACE: ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    //copying arr to arr2
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    cout<<"ARRAY BEFORE SORTING : ";pfun(arr,n);
    //Calling insertion sort using in-place algorithm.
    insertion_sort_IP(arr,n);
    cout<<endl;
    cout<<"ARRAY AFTER SORTING USING IN-PLACE ALGORITHM : ";
    //printing the array
    pfun(arr,n);
    cout<<endl;
    //calling insertiong sort using out-place algorithm.
    insertion_sort_OP(arr2,0,n-1);
    cout<<"ARRAY AFTER SORTING USING OUT-PLACE ALGORITHM : ";
    //printing the array
    pfun(arr,n);
    cout<<endl;

}

/*
[ANS.3]

In-place techniques have lesser space complexity but are difficult to 
apply in algorithm whereas out-place techniques are easy to aplly but 
increases the space complexity of algorithm.
For exapmle if we want to reverse an array then its in-place algorithm
will be swaping the first and last element of array until we reach the 
middle of array,If we want to solve the same problem using out-place 
algorithm we have to create one extra array of same size and copy 
elements of original array from back to the front of new array,this 
algorith increases the space complexity to O(n) as we have creaed an 
extra array.

IN-PLACE algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heapsort.
NOT IN-PLACE algorithm is used in Merge Sort, Because merge sort requires O(n) extra space.

*/

