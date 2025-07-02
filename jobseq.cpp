#include <iostream>
using namespace std;

// Job structure
struct Job {
    int id;
    int deadline;
    int profit;
};

// Sort jobs by profit (bubble sort)
void sortByProfit(Job jobs[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (jobs[j].profit < jobs[j+1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}

// Job Scheduling function
void scheduleJobs(Job jobs[], int n) {
    sortByProfit(jobs, n);

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; ++i)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    // Initialize slots (1-based indexing)
    int slot[21]; // max 20 deadlines, index 1..20
    for (int i = 0; i <= maxDeadline; ++i)
        slot[i] = -1;

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; ++i) {
        for (int j = jobs[i].deadline; j > 0; --j) {
            if (slot[j] == -1) {
                slot[j] = i;  // store index of job in slot
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print scheduled jobs in slot order
    cout << "\nScheduled Job IDs in slot order: ";
    for (int i = 1; i <= maxDeadline; ++i) {
        if (slot[i] != -1)
            cout << jobs[slot[i]].id << " ";
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[20]; // Assume max 20 jobs
    cout << "Enter Job ID, Deadline, and Profit for each job:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Job " << i+1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    scheduleJobs(jobs, n);

    return 0;
}
