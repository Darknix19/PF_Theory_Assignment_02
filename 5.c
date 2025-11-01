#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

char toggleBits(char ch) {
    ch ^= (1 << 1);
    ch ^= (1 << 4);
    return ch;
}

void encodeMessage(char message[]) {
    reverseString(message);
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);
    }
    printf("Encoded Message: %s\n", message);
}

void decodeMessage(char message[]) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);
    }
    reverseString(message);
    printf("Decoded Message: %s\n", message);
}

int main() {
    char message[MAX_LEN];
    int choice;

    do {
        printf("\n--- TCS Secure Message Menu ---\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter message to encode: ");
                fgets(message, MAX_LEN, stdin);
                message[strcspn(message, "\n")] = '\0';
                encodeMessage(message);
                break;
            case 2:
                printf("Enter message to decode: ");
                fgets(message, MAX_LEN, stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message);
                break;
            case 3:
                printf("Exiting system. Stay secure!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
