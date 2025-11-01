#include <stdio.h>

#define ROWS 3
#define COLS 3

// Bit masks
#define POWER_ON 1       // Bit 0
#define OVERLOADED 2     // Bit 1
#define MAINTENANCE 4    // Bit 2

void updateSectorStatus(int grid[ROWS][COLS]) {
    int row, col, flag, action;
    printf("Enter sector coordinates (row and col): ");
    scanf("%d %d", &row, &col);
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid coordinates.\n");
        return;
    }

    printf("Choose status to modify:\n");
    printf("1. Power\n2. Overload\n3. Maintenance\n");
    scanf("%d", &flag);
    printf("1. Set\n2. Clear\n");
    scanf("%d", &action);

    int mask = 1 << (flag - 1);
    if (action == 1)
        grid[row][col] |= mask;
    else
        grid[row][col] &= ~mask;

    printf("Status updated.\n");
}

void querySectorStatus(int grid[ROWS][COLS]) {
    int row, col;
    printf("Enter sector coordinates (row and col): ");
    scanf("%d %d", &row, &col);
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid coordinates.\n");
        return;
    }

    int status = grid[row][col];
    printf("Sector (%d,%d) Status:\n", row, col);
    printf("Power: %s\n", (status & POWER_ON) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & OVERLOADED) ? "YES" : "NO");
    printf("Maintenance: %s\n", (status & MAINTENANCE) ? "REQUIRED" : "NO");
}

void runSystemDiagnostic(int grid[ROWS][COLS]) {
    int overloadCount = 0, maintenanceCount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & OVERLOADED)
                overloadCount++;
            if (grid[i][j] & MAINTENANCE)
                maintenanceCount++;
        }
    }
    printf("System Diagnostic:\n");
    printf("Overloaded sectors: %d\n", overloadCount);
    printf("Sectors needing maintenance: %d\n", maintenanceCount);
}

int main() {
    int grid[ROWS][COLS] = {0};
    int choice;

    do {
        printf("\n--- IESCO Grid Menu ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: updateSectorStatus(grid); break;
            case 2: querySectorStatus(grid); break;
            case 3: runSystemDiagnostic(grid); break;
            case 4: printf("Exiting system.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
