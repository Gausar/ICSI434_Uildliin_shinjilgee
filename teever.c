#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** leastCost(int* supply, int* demand, int** costs, int numSuppliers, int numConsumers) {
    int** allocations = (int**)malloc(numSuppliers * sizeof(int*));
    for (int i = 0; i < numSuppliers; i++) {
        allocations[i] = (int*)calloc(numConsumers, sizeof(int));
    }
    
    int* remainingSupply = (int*)malloc(numSuppliers * sizeof(int));
    int* remainingDemand = (int*)malloc(numConsumers * sizeof(int));
    for (int i = 0; i < numSuppliers; i++) {
        remainingSupply[i] = supply[i];
    }
    for (int i = 0; i < numConsumers; i++) {
        remainingDemand[i] = demand[i];
    }
    
    while (1) {
        int minCost = INT_MAX;
        int minRow = -1;
        int minCol = -1;
        for (int i = 0; i < numSuppliers; i++) {
            for (int j = 0; j < numConsumers; j++) {
                if (remainingSupply[i] > 0 && remainingDemand[j] > 0 && costs[i][j] < minCost) {
                    minCost = costs[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
        }
        
        if (minRow == -1 || minCol == -1) {
            break;
        }
        
        int teeverlelt = (remainingSupply[minRow] < remainingDemand[minCol]) ? remainingSupply[minRow] : remainingDemand[minCol];
        allocations[minRow][minCol] = teeverlelt;
        
        remainingSupply[minRow] = remainingSupply[minRow] - teeverlelt;
        remainingDemand[minCol] = remainingDemand[minCol] - teeverlelt;
    }
    
    free(remainingSupply);
    free(remainingDemand);
    return allocations;
}

int main() {
    int numSuppliers, numConsumers;
    printf("hichneen achaa yavuulah gazriin too : ");
    scanf("%d", &numSuppliers);
    printf("hichneen achaa huleen awah gazriin too: ");
    scanf("%d", &numConsumers);

    int* supply = (int*)malloc(numSuppliers * sizeof(int));
    for (int i = 0; i < numSuppliers; i++) {
        printf("Achaa yavuulah gazar %d: ", i+1);
        scanf("%d", &supply[i]);
    }

    int* demand = (int*)malloc(numConsumers * sizeof(int));
    for (int i = 0; i < numConsumers; i++) {
        printf("Achaa huleen avah gazar %d: ", i+1);
        scanf("%d", &demand[i]);
    }

    int** costs = (int**)malloc(numSuppliers * sizeof(int*));
    for (int i = 0; i < numSuppliers; i++) {
        costs[i] = (int*)malloc(numConsumers * sizeof(int));
    }
    for (int i = 0; i < numSuppliers; i++) {
        for (int j = 0; j < numConsumers; j++) {
            printf("a[%d][%d] zardal: ", i + 1, j + 1);
            scanf("%d", &costs[i][j]);
        }
    }

    int ** allocations = leastCost(supply, demand, costs, numSuppliers, numConsumers);
    int totalCost = 0;

    printf("Huwiarlalt:\n");
    for (int i = 0; i < numSuppliers; i++) {
        for (int j = 0; j < numConsumers; j++) {
            printf("%d\t", allocations[i][j]);
            totalCost = totalCost + allocations[i][j] * costs[i][j];
        }
        printf("\n");
    }

    printf("\tNiit zardal : %d\n", totalCost);
    free(supply);
    free(demand);
    free(costs);
    return 0;
}