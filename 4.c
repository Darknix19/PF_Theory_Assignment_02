#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int stack[], int *top, int maxSize) {
    int value;
    if (*top >= maxSize - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &value);
    (*top)++;
    stack[*top] = value;
    printf("Value pushed.\n");
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow.\n");
        return;
    }
    printf("Popped value: %d\n", stack[*top]);
    (*top)--;
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top value: %d\n", stack[top]);
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(stack, &top, MAX); break;
            case 2: pop(stack, &top); break;
            case 3: peek(stack, top); break;
            case 4: display(stack, top); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
