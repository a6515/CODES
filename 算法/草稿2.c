#include <stdio.h>

#define MAX_N 100

int weights[MAX_N];
int values[MAX_N];
int best_value = 0;
int best_set[MAX_N];
int n, capacity;

void knapsack_backtracking(int index, int current_weight, int current_value, int selected[]) {
    if (index == n) {
        if (current_value > best_value) {
            best_value = current_value;
            for (int i = 0; i < n; i++) {
                best_set[i] = selected[i];
            }
            printf("Current Best Value: %d\n", best_value);
            printf("Selected items: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", selected[i]);
            }
            printf("\n");
        }
        return;
    }

    if (current_weight + weights[index] <= capacity) {
        selected[index] = 1;
        knapsack_backtracking(index + 1, current_weight + weights[index], current_value + values[index], selected);
        selected[index] = 0;
    }

    knapsack_backtracking(index + 1, current_weight, current_value, selected);
}

int main() {
    // Example usage
    n = 3;
    capacity = 6;
    weights[0] = 2; values[0] = 1;
    weights[1] = 3; values[1] = 2;
    weights[2] = 4; values[2] = 4;


    int selected[MAX_N] = {0};
    knapsack_backtracking(0, 0, 0, selected);

    printf("Best Value: %d\n", best_value);

    return 0;
}
