#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};


bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int findMaxDeadline(vector<Job>& jobs) {
    int mx = 0;
    for (int i = 0; i < jobs.size(); i++)
        mx = max(mx, jobs[i].deadline);
    return mx;
}

int scheduleJobs(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), cmp);

    int maxD = findMaxDeadline(jobs);
    
    vector<int> slot(maxD + 1, 0);
    int total = 0;

    for (int i = 0; i < jobs.size(); i++) {
        bool placed = false;
        for (int t = jobs[i].deadline; t >= 1; t--) {
            if (slot[t] == 0) {
                slot[t] = jobs[i].id;
                total += jobs[i].profit;
                cout << "Job " << jobs[i].id << " -> [" << t - 1 << "," << t << "]\n";
                placed = true;
                break;
            }
        }
        if (!placed)
            cout << "Job " << jobs[i].id << " -> Reject\n";
    }

    cout << "\nSchedule: ";
    for (int t = 1; t <= maxD; t++)
        if (slot[t] != 0) cout << "Job" << slot[t] << " ";
    cout << endl;

    return total;
}

int main() {
    int n;
    cout << "Number of jobs: ";
    cin >> n;

    cout << "Enter job id, deadline, profit:\n";
    vector<Job> jobs(n);
    for(int i=0;i<n;i++){
    cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;    
    }

    int total = scheduleJobs(jobs);
    cout << "Total profit = " << total << endl;
    
}
