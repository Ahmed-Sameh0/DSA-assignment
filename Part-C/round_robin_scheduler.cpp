#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void printQueue(queue<int> q) {
    if (q.empty()) {
        cout << "[ Empty ]" << endl;
        return;
    }

    cout << "[ ";
    while (!q.empty()) {
        cout << "P" << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << " ]" << endl;
}

void addArrivedProcesses(int current_time, Process processes[], int n,
                         queue<int>& ready_queue, bool visited[]) {

    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time &&
            processes[i].remaining_time > 0 &&
            !visited[i]) {

            ready_queue.push(processes[i].id);
            visited[i] = true;
        }
    }
}

int main() {

    int time_quantum, n;

    cout << "Time Quantum: ";
    cin >> time_quantum;

    cout << "Number of Processes: ";
    cin >> n;

    Process processes[10];
    bool visited[10] = {false};

    for (int i = 0; i < n; i++) {
        cout << "Arrival Time, Needed Time P" << (i + 1) << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;

        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }

    queue<int> ready_queue;
    int current_time = 0;

    addArrivedProcesses(current_time, processes, n, ready_queue, visited);

    cout << "\nQueue updates:" << endl;
    printQueue(ready_queue);

    while (true) {

        bool done = true;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = false;
                break;
            }
        }
        if (done) break;

        if (ready_queue.empty()) {
            current_time++;
            addArrivedProcesses(current_time, processes, n, ready_queue, visited);

            if (!ready_queue.empty())
                printQueue(ready_queue);

            continue;
        }

        int pid = ready_queue.front();
        ready_queue.pop();

        Process &p = processes[pid - 1];

        int run = min(time_quantum, p.remaining_time);
        current_time += run;
        p.remaining_time -= run;

        addArrivedProcesses(current_time, processes, n, ready_queue, visited);

        if (p.remaining_time > 0) {
            ready_queue.push(pid);
        } else {
            p.completion_time = current_time;
            p.turnaround_time = current_time - p.arrival_time;
            p.waiting_time = p.turnaround_time - p.burst_time;
        }

        printQueue(ready_queue);
    }

    int total_waiting = 0;

    cout << "\nProcess\t\t";
    for (int i = 0; i < n; i++) cout << "P" << processes[i].id << "\t";
    cout << endl;

    cout << "Completion Time\t";
    for (int i = 0; i < n; i++) cout << processes[i].completion_time << "\t";
    cout << endl;

    cout << "Turnaround Time\t";
    for (int i = 0; i < n; i++) cout << processes[i].turnaround_time << "\t";
    cout << endl;

    cout << "Waiting Time\t";
    for (int i = 0; i < n; i++) {
        cout << processes[i].waiting_time << "\t";
        total_waiting += processes[i].waiting_time;
    }
    cout << endl;

    cout << "\nAverage Waiting Time: "
         << (float)total_waiting / n << endl;

    return 0;
}