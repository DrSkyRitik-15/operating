#include <stdio.h>

struct Student {
    int id;
    int ARA;  // kab aaya
    int foodTime;
    int remainingTime;
    int turnTime;
    int waitingTime;
};

void sortById(struct Student S[], int n) {     // Normal Binary Use hai
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (S[j].id > S[j + 1].id) {
                struct Student temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student students[3] = {
        {2132, 0, 2, 2, 0, 0},{2102, 0, 4, 4, 0, 0},{2453, 0, 8, 8, 0, 0}
    };

    int n = 3;

    sortById(students, n);

    int currentTime = 0;
    float totalTurnTime = 0, totalWaitingTime = 0;
printf(".........................................................\n");
    printf("Student ID\t TurnTime\t Waiting Time\n");

    for (int i = 0; i < n; i++) {
        int Mtime = -1, Mindex = -1;
        for (int j = 0; j < n; j++) {
            if (students[j].ARA <= currentTime && students[j].remainingTime > Mtime) {
                Mtime = students[j].remainingTime;
                Mindex = j;
            }
        }

        currentTime += students[Mindex].remainingTime;
        students[Mindex].remainingTime = 0;

        students[Mindex].turnTime = currentTime - students[Mindex].ARA;
        students[Mindex].waitingTime = students[Mindex].turnTime - students[Mindex].foodTime;

        totalTurnTime += students[Mindex].turnTime;
        totalWaitingTime += students[Mindex].waitingTime;

        printf("%d\t\t %d\t\t %d\n", students[Mindex].id, students[Mindex].turnTime, students[Mindex].waitingTime);
    }

    float averageTTTime = totalTurnTime / n;
    float averageWait = totalWaitingTime / n;
    printf(".........................................................");
    printf("\nAvg Turnaround Time: %.2f\n", averageTTTime);
    printf("Avg Waiting Time: %.2f", averageWait);

    return 0;
}
