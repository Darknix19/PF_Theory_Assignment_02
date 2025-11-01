#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50

void addBook(int isbns[], char titles[][TITLE_LEN], float prices[], int quantities[], int *count); // 1
void processSale(int isbns[], int quantities[], int count); // 2
void generateLowStockReport(int isbns[], char titles[][TITLE_LEN], float prices[], int quantities[], int count); // 3

int main() {
    int isbns[MAX_BOOKS];
    char titles[MAX_BOOKS][TITLE_LEN];
    float prices[MAX_BOOKS];
    int quantities[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\n--- Liberty Books Inventory Menu ---\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, quantities, count);
                break;
            case 3:
                generateLowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// 1
void addBook(int isbns[], char titles[][TITLE_LEN], float prices[], int quantities[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Inventory full. Cannot add more books.\n");
        return;
    }

    int newIsbn;
    printf("Enter ISBN: ");
    scanf("%d", &newIsbn);
    getchar();

    for (int i = 0; i < *count; i++) {
        if (isbns[i] == newIsbn) {
            printf("Book with ISBN %d already exists.\n", newIsbn);
            return;
        }
    }

    isbns[*count] = newIsbn;

    printf("Enter Title: ");
    fgets(titles[*count], TITLE_LEN, stdin);
    titles[*count][strcspn(titles[*count], "\n")] = '\0';

    printf("Enter Price: ");
    scanf("%f", &prices[*count]);

    printf("Enter Quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++;
    printf("Book added successfully.\n");
}

// 2
void processSale(int isbns[], int quantities[], int count) {
    int isbn, sold;
    printf("Enter ISBN of book sold: ");
    scanf("%d", &isbn);

    int found = -1;
    for (int i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Book not found.\n");
        return;
    }

    printf("Enter number of copies sold: ");
    scanf("%d", &sold);

    if (quantities[found] < sold) {
        printf("Not enough stock. Only %d copies available.\n", quantities[found]);
    } else {
        quantities[found] -= sold;
        printf("Sale processed. Remaining stock: %d\n", quantities[found]);
    }
}

// 3
void generateLowStockReport(int isbns[], char titles[][TITLE_LEN], float prices[], int quantities[], int count) {
    printf("\n--- Low Stock Report (Quantity < 5) ---\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No books with low stock.\n");
    }
}
