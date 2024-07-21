#include <stdio.h>
#include <stdlib.h> // Included for exit function

#define MAX 20 /* Define the required functions to create a list, insert into the list, 
delete an element from the list, search and display the list */

void create();
void insert();
void deletion();
void search();
void display();

int a,b[MAX], n, p, e, f, i, pos;

void main() {
    int ch;
    char g = 'y';
    
    do {
        printf("\nMain Menu");
        printf("\n1.Create\n2.Delete\n3.Search\n4.Insert\n5.Display\n6.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch); /* The following switch will call the appropriate choice provided 
by the user */
        
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\n Enter the correct choice:");
        }
        
        if (ch != 6) { // Ask to continue if not exiting
            printf("\nDo you want to continue (y/n)? ");
            scanf("\n%c", &g);
        }
        /* The program is intended to run till we provide inputs other that ‘y’ 
or ‘Y’ */
    } while (g == 'y' || g == 'Y');
}

void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    /* The loop should run till we get the ‘n’ inputs */

    for (i = 0; i < n; i++) {
        printf("\nEnter the element: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\nEnter the position you want to delete:: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\n Invalid location.");
    } else {
        for (i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
    }

    printf("\nThe elements after deletion: ");
    for (i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
    printf("\n");
}

void search() {
    int e, found = 0;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is in the %d position.\n", i);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos > n || pos < 0 || n >= MAX) {
        printf("\nInvalid location.");
    } else {
        for (i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }

        printf("\nEnter the element to insert: ");
        scanf("%d", &p);

        b[pos] = p;
        n++;
    }

    printf("\nThe list after insertion:\n");
    display();
}

void display() {
    printf("\nThe elements of the list ADT are: ");
    for (i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
    printf("\n");
}
