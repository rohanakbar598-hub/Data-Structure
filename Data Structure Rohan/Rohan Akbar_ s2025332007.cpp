#include <iostream>
using namespace std;

/* ===========================
   Q1 – Arrays & Searching
   =========================== */

// Q1.A.1
// Contiguous memory allocation means storing elements in adjacent memory locations.
// Arrays use it so we can access any element directly using index.
// Advantage: O(1) access time (direct access).

// Q1.A.2
// Memory leak = memory allocated but not deallocated.
// Example: using new int[10] and forgetting delete[] leads to memory leak.

// Q1.A.3
// Static array = fixed size (int arr[10])
// Dynamic array = size decided at runtime (new int[n])
// Fixed size matters because it cannot grow/shrink.

// Q1.A.4
// Array access is O(1) because address is calculated directly.
// Linked list requires traversal ? O(n).

// Q1.B.1 – Linear Search
int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

// Q1.B.2 – Min & Max in one loop
void findMinMax(int arr[], int size, int &minVal, int &maxVal) {
    minVal = arr[0];
    maxVal = arr[0];

    for(int i = 1; i < size; i++) {
        if(arr[i] < minVal)
            minVal = arr[i];
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
}


/* ===========================
   Q2 – Bubble Sort
   =========================== */

// Q2.A.1
// Bubble sort repeatedly compares adjacent elements and swaps them.
// Largest elements "bubble" to the end after each pass.

// Q2.A.2
// Best: O(n)
// Average: O(n^2)
// Worst: O(n^2)
// If already sorted + flag ? O(n)

// Q2.A.3
// Bubble Sort vs Selection Sort:
// Selection sort is preferred (fewer swaps).
// Bubble used when simplicity needed.

// Q2.B – Bubble Sort
void bubbleSort(int arr[], int n, int &swapCount) {
    swapCount = 0;

    for(int i = 0; i < n-1; i++) {
        bool swapped = false;

        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapCount++;
                swapped = true;
            }
        }

        // Print after each pass
        cout << "Pass " << i+1 << ": ";
        for(int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;

        if(!swapped) break;
    }
}


/* ===========================
   Q3 – Binary Search
   =========================== */

// Q3.A.1
// Array must be sorted.
// Otherwise binary search won't work.

// Q3.A.2
// Dry Run:
// low=0 high=7 ? mid=3 (12)
// low=4 high=7 ? mid=5 (23 FOUND)

// Q3.A.3
// Binary Search: O(log n)
// Linear Search: O(n)
// Binary is faster because it halves data each step.

int binarySearch(int arr[], int size, int key, int &iterations) {
    int low = 0, high = size - 1;
    iterations = 0;

    while(low <= high) {
        iterations++;
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


/* ===========================
   Q4 – Complexity (Big O)
   =========================== */

// Q4.A.1
// Big O describes growth rate of algorithm.
// Used instead of time because hardware differs.

// Q4.A.2
// Big O = worst case
// Omega = best case
// Theta = exact case

// Q4.A.3
// Fastest ? Slowest:
// O(1), O(log n), O(n), O(n log n), O(n^2)

// Q4.A.4
// Space complexity = memory usage.
// Array of size n ? O(n).

// Q4.A.5
// No, asymptotically O(n log n) beats O(n^2).

// Q4.B.1
// Nested loop ? O(n^2)
void nestedLoop(int arr[], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << arr[i] << " ";
}

// Single loop ? O(n)
void singleLoop(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Q4.B.2
// Time Complexity: O(n^2)
bool checkArrays(int A[], int B[], int n) {
    for(int i = 0; i < n; i++) {
        bool found = false;
        for(int j = 0; j < n; j++) {
            if(A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}
// Better approach: sort + binary search ? O(n log n)


/* ===========================
   Q5 – Linked List
   =========================== */

// Q5.A.1
// Linked List = nodes connected via pointers.
// Not contiguous like arrays.

// Q5.A.2
// Insert head: O(1)
// Insert tail: O(n)
// Delete: O(n)

// Q5.A.3
// Not deleting causes memory leak.

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node{val, nullptr};
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteByValue(int val) {
        if(head == nullptr) return;

        if(head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != val)
            temp = temp->next;

        if(temp->next == nullptr) {
            cout << "Value not found\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void display() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


/* ===========================
   MAIN FUNCTION
   =========================== */

int main() {

    // Q1
    int arr1[10] = {4,15,7,23,1,9,42,18,6,30};

    int index = linearSearch(arr1, 10, 42);
    if(index != -1)
        cout << "42 found at index: " << index << endl;
    else
        cout << "Not found\n";

    int minVal, maxVal;
    findMinMax(arr1, 10, minVal, maxVal);
    cout << "Min: " << minVal << " Max: " << maxVal << endl;


    // Q2
    int arr2[7] = {64,34,25,12,22,11,90};
    cout << "\nBefore Sorting: ";
    for(int i=0;i<7;i++) cout<<arr2[i]<<" ";
    cout<<endl;

    int swaps;
    bubbleSort(arr2,7,swaps);
    cout << "Total swaps: " << swaps << endl;


    // Q3
    int arr3[10] = {2,5,8,12,16,23,38,45,56,72};
    int iterations;

    int result = binarySearch(arr3,10,56,iterations);
    cout << "Found at index: " << result << " Iterations: " << iterations << endl;

    result = binarySearch(arr3,10,100,iterations);
    cout << "Not Found Iterations: " << iterations << endl;


    // Q5
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);
    list.insertAtHead(1);

    cout << "\nLinked List: ";
    list.display();

    list.deleteByValue(20);
    list.deleteByValue(100);

    cout << "After Deletion: ";
    list.display();

    return 0;
}


