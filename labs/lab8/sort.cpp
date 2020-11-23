#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

//reference https://www.geeksforgeeks.org/merge-sort/
void merge(int* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int* arr, int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2;

        // Sort first and second halves 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

bool is_prime(int val) {
    if (val < 2)
        return false;

    for (int i = 2; i < val; ++i) {
        if (val % i == 0)
            return false;
    }
    return true;
}

int main() {
	srand(time(NULL));
	string input_str;
	int size;
	//get user input
	do {
		cout << "Enter the length of the array: ";
		getline(cin, input_str);
		size = atoi(input_str.c_str());
		if (size >= 0 && size <= 20) {
			break;
		}
		else {
			cout << "Error, enter again." << endl;
		}
	} while (1);

	if (size == 0) {
		return 0;
	}

	//create array and generate and print numbers
    cout << "Populating numbers and printing......" << endl;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50 + 1;
		cout << arr[i] << " ";
	}
    cout << endl << endl;
	
	//crete a copy
	int* arr2 = new int[size];
	for (int i = 0; i < size; i++) {
		arr2[i] = arr[i];
	}

	//merge sort in ascending order
	mergeSort(arr2, 0, size-1);


    //print the arr2
    cout << "Printing out sorted array......" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl << endl;

    //finding prime numbers
    cout << "Printing out prime numbers......" << endl;
    for (int j = 0; j < size; j++) {
        if (is_prime(arr2[j])) {
            cout << arr2[j] << " ";
        }
    }
    cout << endl;


    //free memory
    delete[] arr;
    delete[] arr2;

	return 0;
}