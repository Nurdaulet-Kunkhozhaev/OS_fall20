#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESS 10

// I assume all the processes are inserted based on their Arrival Time
// In other words, ATs are present in asceding order

// at - arrival time
// bt - burst time
// tat - turnaround time
// wt - waiting time
// et - exit time

// PP algo is good but compared with others WT are higher
int main() {
    int bt[MAX_PROCESS] = {}, at[MAX_PROCESS] = {}, tat[MAX_PROCESS] = {};
    int wt[MAX_PROCESS] = {}, et[MAX_PROCESS] = {}, bt_original[MAX_PROCESS] = {};
    bool executed[MAX_PROCESS] = {};

    int n, quantum;
    float totalTAT = 0., totalWT = 0.;

    // Enter no more than MAX_PROCESS is
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter quantum: ");
    scanf("%d", &quantum);

    printf("Now enter AT and BT for each process:\n");

    int i;
    for (i = 0; i < n; i++) {
        printf("AT of %d process is: ", i + 1);
        scanf("%d", &at[i]);
        executed[i] = false;

        printf("BT of %d process is: ", i + 1);
        scanf("%d", &bt[i]);
        bt_original[i] = bt[i];
    }

    // Execute processes with RR algo
    int cur_time = at[0], finished = 0;
    i = 0;
    while (finished != n) {
        if (executed[i] == true) {
                i = (i + 1)%n;
                continue;
        }

        // if process can be completed fully
        if (bt[i] <= quantum) {
            cur_time += bt[i];
            et[i] = cur_time; // calculate ET

            tat[i] = et[i] - at[i]; // calculate TAT
            totalTAT += tat[i];

            wt[i] = tat[i] - bt_original[i]; // calculate WT
            totalWT += wt[i];

            finished++;
            executed[i] = true;
            i = (i + 1)%n;
        } else {
            // otherwise we do it partly and move to next process
            cur_time += quantum;
            bt[i] -= quantum;
            i = (i + 1)%n;
        }
    }

    // Formatting output
    printf("P#\t AT\t BT\t ET\t TAT\t WT\n\n");
    for (i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], bt_original[i], et[i], tat[i], wt[i]);

    printf("Average TAT is %f\n", totalTAT/n);
    printf("Average WT is %f\n", totalWT/n);
}

