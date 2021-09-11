#include <iostream>
#include <vector>
using namespace std;

/*
    QuickSort's Partition Function

    This is based on Hoare's partition scheme. Based on a discussion on StackExchange it's faster than Lomuto's partition scheme. I'm a
    bit new to this type of problem but the math seems to check out.

    References:
    - https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
    - https://cs.stackexchange.com/questions/11458/quicksort-partitioning-hoare-vs-lomuto/11550#11550
*/
int Partition(vector<int>& values, int low, int high)
{
    int pivotValue = values[low + (high - low) / 2]; // Calculate the pivotIndex and store the value
    int tmp; // This is a tempoary value to assist with swaps
    while (low <= high) {
        // While the low end is less than the pivot value increment its index until it's not.
        while (values[low] < pivotValue) {
            low++;
        }
        // While the high end is greater than the pivot value decreate its index until its not.
        while (values[high] > pivotValue) {
            high--;
        }
        
        // If the low value is less than or equal to the high value swap them by reference
        if (low <= high) {
            tmp = values[low];
            values[low] = values[high];
            values[high] = tmp;
            low++;
            high--;
        }
    }
    return low;
}

/*
    QuickSort Algorithm

    Quicksort is a recursive algorithm which breaks up an array into smaller arrays and sorts them.

    References:
    - http://homepages.math.uic.edu/~jan/mcs360/quicksort.pdf
    - https://stackoverflow.com/questions/47382423/c-quicksort-with-vectors
    - https://codereview.stackexchange.com/questions/189103/quick-sort-on-c-vector
    - http://www.danielkoitzsch.de/blog/2016/11/18/quicksort-implementation-in-c/
*/
void QuickSort(vector<int>& myVec, int low, int high)
{
    // Make sure that low and high are natural numbers otherwise
    // you risk an out of bounds error (although vectors have some safeguards arrays do not)
    if (low >= 0 && high >= 0) {

        // if the low end is less than the high end run the parition scheme on it and then quicksort it
        if (low < high) {
            int pivotIndex = Partition(myVec, low, high);
            QuickSort(myVec, low, pivotIndex - 1);
            QuickSort(myVec, pivotIndex, high);
        }
    }
}

// This function acts as a stub to expand the arguments needed for my QuickSort implementation
void SortVector(vector<int>& myVec)
{
    // Set the beginning of the vector as low and the end as high.
    QuickSort(myVec, 0, myVec.size() - 1);
}

int main() {
    vector<int> myVecs = { 5, 7, 1, 5, 2, 7, 5, 4, 1, 2, 9, 6, 11};
    SortVector(myVecs);

    for (int i = 0; i < myVecs.size(); i++) {
        cout << myVecs.at(i) << " ";
    }

    cout << endl;

    return 0;
}
