#include <stdio.h>
struct Item {
    float profit, weight, ratio;
};
void sort(struct Item items[], int n) {
    int i, j;
    struct Item temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
int main() {
    int n, i;
    float capacity, total_profit = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter profit and weight for each item:\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &items[i].profit, &items[i].weight);
        items[i].ratio = items[i].profit / items[i].weight;
    }
    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);
    sort(items, n);
    printf("\nSelected items:\n");
    for(i = 0; i < n; i++) {
        if(items[i].weight <= capacity) {
            printf("Item %d -> Taken completely (Profit=%.2f, Weight=%.2f)\n",
                   i + 1, items[i].profit, items[i].weight);

            total_profit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            float fraction = capacity / items[i].weight;

            printf("Item %d -> Taken %.2f fraction (Profit=%.2f, Weight=%.2f)\n",
                   i + 1, fraction, items[i].profit, items[i].weight);

            total_profit += items[i].profit * fraction;
            break;
        }
    }
    printf("\nMaximum Profit = %.2f\n", total_profit);
    return 0;
}


