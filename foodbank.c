#include <stdio.h>
#include <string.h>

#define MAX_DONATIONS 10000

char donations[MAX_DONATIONS][20];
int amounts[MAX_DONATIONS];
int totalDonations = 0;
int z;

char requests[MAX_DONATIONS][20];
int requestAmounts[MAX_DONATIONS];
int totalRequests = 0;

void addDonation() {
    char item[20];
    int quantity;

    printf("\nEnter inventory type: ");
    scanf("%s", item);
    printf("Enter the amount: ");
    scanf("%d", &quantity);

    int i;
    for (i = 0; i < totalDonations; i++) {
        if (strcmp(donations[i], item) == 0) {
            amounts[i] += quantity;
            printf("\nDonation Added!\nPress any key to continue...\n");
            scanf("%d", &z);
            return;
        }
    }
    strcpy(donations[totalDonations], item);
    amounts[totalDonations] = quantity;
    totalDonations++;
    printf("\nDonation Added!\nPress any key to continue...\n");
    scanf("%d", &z);
}

void addRequest() {
    char item[20];
    int quantity;
    printf("Requested item: ");
    scanf("%s", item);
    printf("Quantity: ");
    scanf("%d", &quantity);

    strcpy(requests[totalRequests], item);
    requestAmounts[totalRequests] = quantity;
    totalRequests++;
    printf("\nRequest Added!\n");
}

void fillRequest() {
    if (totalRequests == 0) {
        printf("No requests to fulfill\n");
        return;
    }

    int i;
    for (i = 0; i < totalDonations; i++) {
        if (strcmp(donations[i], requests[0]) == 0) {
            if (amounts[i] >= requestAmounts[0]) {
                printf("Request Fulfilled!\n");
                totalRequests--;
                amounts[i] -= requestAmounts[0];
                if (amounts[i] == 0) {
                    totalDonations--;
                    for (int j = i; j < totalDonations; j++) {
                        strcpy(donations[j], donations[j + 1]);
                        amounts[j] = amounts[j + 1];
                    }
                }
                return;
            } else {
                printf("Partially Fulfilled!\n");
                requestAmounts[0] -= amounts[i];
                totalDonations--;
                for (int j = i; j < totalDonations; j++) {
                    strcpy(donations[j], donations[j + 1]);
                    amounts[j] = amounts[j + 1];
                }
                return;
            }
        }
    }
    printf("Request cannot be fulfilled\n");
}

void printStatusReport() {
    printf("Printing the Donations Table\n");
    for (int i = 0; i < totalDonations; i++) {
        printf("%s %d\n", donations[i], amounts[i]);
    }
    printf("Printing the Requests Table\n");
    for (int i = 0; i < totalRequests; i++) {
        printf("%s %d\n", requests[i], requestAmounts[i]);
    }
}

int main() {
    int choice = 0;

    while (choice != 5) {
        printf("\nWelcome to the Food Bank Program\n");
        printf("\n1. Add a donation\n");
        printf("2. Add a request\n");
        printf("3. Fulfill a request\n");
        printf("4. Print status report\n");
        printf("5. Exit\n");
        printf("Enter your choice:_");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDonation();
                break;
            case 2:
                addRequest();
                break;
            case 3:
                fillRequest();
                break;
            case 4:
                printStatusReport();
                break;
            case 5:
                printf("Thank You for using the software. Bye for now.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("Press any key to continue . . . ");
        scanf("%d", &z);
    }

    return 0;
}
