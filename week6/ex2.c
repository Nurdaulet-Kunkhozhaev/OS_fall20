#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_PROCESS 10

// at - arrival time
// bt - burst time
// tat - turnaround time
// wt - waiting time
// et - exit time
int main() {
    int bt[MAX_PROCESS] = {}, at[MAX_PROCESS] = {}, tat[MAX_PROCESS] = {};
    int wt[MAX_PROCESS] = {}, et[MAX_PROCESS] = {};
    bool executed[MAX_PROCESS] = {};

    int n, min_at = INT_MAX;
    float totalTAT = 0., totalWT = 0.;

    // Enter no more than MAX_PROCESS is
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Now enter AT and BT for each process:\n");

    int i, j;
    for (i = 0; i < n; i++) {
        executed[i] = false;

        printf("AT of %d process is: ", i + 1);
        scanf("%d", &at[i]);

        if (at[i] < min_at)
            min_at = at[i];

        printf("BT of %d process is: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Execute processes with SJF algo
    int cur_time = min_at;
    for (i = 0; i < n; i++) {
        int pos = 0, min_bt = INT_MAX;

        // Among all processes known at current time we choose the one with lowest BT
        for (j = 0; j < n; j++) {
            if (!executed[j] && at[j] <= cur_time && bt[j] < min_bt) {
                pos = j;
                min_bt = bt[j];
            }
        }

        executed[pos] = true;
        cur_time += bt[pos];
        et[pos] = cur_time; // calculate ET

        tat[pos] = et[pos] - at[pos]; // calculate TAT
        totalTAT += tat[pos];

        wt[pos] = tat[pos] - bt[pos]; // calculate WT
        totalWT += wt[pos];
    }

    // Formatting output
    printf("P#\t AT\t BT\t ET\t TAT\t WT\n\n");
    for (i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], bt[i], et[i], tat[i], wt[i]);

    printf("Average TAT is %f\n", totalTAT/n);
    printf("Average WT is %f\n", totalWT/n);
}
