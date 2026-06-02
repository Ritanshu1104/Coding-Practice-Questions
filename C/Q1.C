#include <stdio.h>

typedef struct {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // CPU burst time
    int start;      // Start time
    int completion; // Completion time
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
} Process;

void sortByArrival(Process p[], int n) {
    Process temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (p[j].arrival > p[j+1].arrival) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void printGanttChart(Process p[], int n) {
    printf("\nGantt Chart:\n ");
    // Print top bar
    for (int i = 0; i < n; i++) {
        printf(" ");
        for (int j = 0; j < p[i].burst; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // Print process IDs in the middle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].burst - 1; j++) printf(" ");
        printf("P%d", p[i].pid);
        for (int j = 0; j < p[i].burst - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    // Print bottom bar
    for (int i = 0; i < n; i++) {
        printf(" ");
        for (int j = 0; j < p[i].burst; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // Print timeline
    printf("0");
    for (int i = 0; i < n; i++) {
        int time = p[i].completion;
        if (time > 9) printf("   %d", time);
        else printf("    %d", time);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process P%d: ", p[i].pid);
        scanf("%d", &p[i].arrival);
        printf("Enter burst time for process P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    // Sort processes by arrival time
    sortByArrival(p, n);

    int currentTime = 0;
    float totalWaiting = 0, totalTurnaround = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].arrival)
            currentTime = p[i].arrival; // CPU idle till process arrives

        p[i].start = currentTime;
        p[i].completion = p[i].start + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].start - p[i].arrival;

        totalWaiting += p[i].waiting;
        totalTurnaround += p[i].turnaround;

        currentTime = p[i].completion;
    }

    printGanttChart(p, n);

    printf("\nProcess\tArrival\tBurst\tStart\tCompletion\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst, p[i].start,
               p[i].completion, p[i].waiting, p[i].turnaround);
    }

    printf("\nAverage waiting time = %.2f\n", totalWaiting / n);
    printf("Average turnaround time = %.2f\n", totalTurnaround / n);

    return 0;
}
