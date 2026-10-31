
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Sort {
private:
    int arr[1000];
    int n;

    long long comparisons;
    long long swaps;

public:
    Sort(int a[], int size) {
        n = size;

        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }

        comparisons = 0;
        swaps = 0;
    }

    void bubbleSort() {
        comparisons = 0;
        swaps = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                comparisons++;

                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                }
            }
        }
    }

    void selectionSort() {
        comparisons = 0;
        swaps = 0;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                comparisons++;

                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
                swaps++;
            }
        }
    }

    void insertionSort() {
        comparisons = 0;
        swaps = 0;

        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0) {
                comparisons++;

                if (arr[j] > key) {
                    arr[j + 1] = arr[j];
                    swaps++;
                    j--;
                }
                else {
                    break;
                }
            }

            arr[j + 1] = key;
        }
    }

    void sort(string choice) {
        if (choice == "bubble") {
            bubbleSort();
        }
        else if (choice == "selection") {
            selectionSort();
        }
        else if (choice == "insertion") {
            insertionSort();
        }
        else {
            cout << "Invalid sorting technique!" << endl;
            return;
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    long long getComparisons() {
        return comparisons;
    }

    long long getSwaps() {
        return swaps;
    }

    static void analyze(int size) {
        int original[1000];

        for (int i = 0; i < size; i++) {
            original[i] = rand() % 1000;
        }

        string techniques[3] = {
            "bubble", "selection", "insertion"
        };

        long long comp[3];
        long long swp[3];

        for (int i = 0; i < 3; i++) {
            Sort s(original, size);

            s.sort(techniques[i]);

            comp[i] = s.getComparisons();
            swp[i] = s.getSwaps();
        }

        cout << "\n--- Sorting Analysis ---\n";

        for (int i = 0; i < 3; i++) {
            cout << techniques[i] << " Sort\n";
            cout << "Comparisons: " << comp[i] << endl;
            cout << "Swaps/Shifts: " << swp[i] << endl;
            cout << "----------------------\n";
        }

        int best = 0;
        int worst = 0;

        for (int i = 1; i < 3; i++) {
            if (comp[i] + swp[i] < comp[best] + swp[best]) {
                best = i;
            }

            if (comp[i] + swp[i] > comp[worst] + swp[worst]) {
                worst = i;
            }
        }

        cout << "\nBest (combined count): " << techniques[best] << endl;
        cout << "Worst (combined count): " << techniques[worst] << endl;
    }
};

int main() {
    srand(time(0));

    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n < 1 || n > 1000) {
        cout << "Invalid array size!";
        return 0;
    }

    int a[1000];

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Sort s(a, n);

    string choice;

    cout << "\nChoose sorting technique:\n";
    cout << "1. bubble\n";
    cout << "2. selection\n";
    cout << "3. insertion\n";
    cout << "Enter choice: ";

    cin >> choice;

    s.sort(choice);

    cout << "\nSorted Array: ";
    s.display();

    cout << "\nPerforming random array analysis...\n";
    Sort::analyze(n);

    return 0;
}
