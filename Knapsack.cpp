#include <iostream>
using namespace std;

int main() {
    int n;
    float capacity;

    // Input number of items and capacity
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    float weight[100], value[100], ratio[100];

    // Input weights and values
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
        ratio[i] = value[i] / weight[i];  // Value-to-weight ratio
    }

    // Sort items by value/weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (ratio[j] < ratio[j+1]) {
                // Swap all related data
                swap(ratio[j], ratio[j+1]);
                swap(weight[j], weight[j+1]);
                swap(value[j], value[j+1]);
            }
        }
    }

    float totalValue = 0.0;

    // Pick items
    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            capacity -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += ratio[i] * capacity;
            break; // Knapsack is full
        }
    }

    cout << "Maximum value in knapsack = " << totalValue << endl;

    return 0;
}
