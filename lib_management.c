#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library {
    char book_name[100];
    char author[100];
    int pages;
    float price;
};

struct library BOOKS[100];
int num = 0;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addbook() {
    if (num >= 100) {
        printf("Library is FULL! Cannot add books to the library.\n");
    } else {
        printf("Enter book title:\n");
        clearInputBuffer();
        fgets(BOOKS[num].book_name, sizeof(BOOKS[num].book_name), stdin);
        BOOKS[num].book_name[strcspn(BOOKS[num].book_name, "\n")] = '\0'; // Remove newline character
        printf("Enter author name:\n");
        fgets(BOOKS[num].author, sizeof(BOOKS[num].author), stdin);
        BOOKS[num].author[strcspn(BOOKS[num].author, "\n")] = '\0'; // Remove newline character
        printf("Enter number of pages:\n");
        scanf("%d", &BOOKS[num].pages);
        clearInputBuffer();
        printf("Enter price of the book:\n");
        scanf("%f", &BOOKS[num].price);
        clearInputBuffer();
        num++;
        printf("Book added successfully to the library!\n");
    }
}

void removebook() {
    if (num == 0) {
        printf("Library is empty. Cannot remove any books.\n");
    } else {
        char remove[100];
        printf("Enter the title of the book to remove:\n");
        clearInputBuffer();
        fgets(remove, sizeof(remove), stdin);
        remove[strcspn(remove, "\n")] = '\0'; // Remove newline character

        for (int i = 0; i < num; i++) {
            if (strcmp(BOOKS[i].book_name, remove) == 0) {
                for (int j = i; j < num - 1; j++) {
                    strcpy(BOOKS[j].book_name, BOOKS[j + 1].book_name);
                    strcpy(BOOKS[j].author, BOOKS[j + 1].author);
                    BOOKS[j].pages = BOOKS[j + 1].pages;
                    BOOKS[j].price = BOOKS[j + 1].price;
                }
                num--;
                printf("Book deleted successfully from the library!\n");
                return;
            }
        }
        printf("Book with title '%s' not found in the library.\n", remove);
    }
}

void searchByTitle() {
    char searchTitle[100];
    printf("Enter the title to search for:\n");
    clearInputBuffer();
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline character

    printf("Matching books:\n");
    for (int i = 0; i < num; i++) {
        if (strstr(BOOKS[i].book_name, searchTitle) != NULL) {
            printf("Title: %s\nAuthor: %s\nPages: %d\nPrice: %.2f\n\n",
                   BOOKS[i].book_name, BOOKS[i].author, BOOKS[i].pages, BOOKS[i].price);
        }
    }
}

void searchByAuthor() {
    char searchAuthor[100];
    printf("Enter the author to search for:\n");
    clearInputBuffer();
    fgets(searchAuthor, sizeof(searchAuthor), stdin);
    searchAuthor[strcspn(searchAuthor, "\n")] = '\0'; // Remove newline character

    printf("Matching books:\n");
    for (int i = 0; i < num; i++) {
        if (strstr(BOOKS[i].author, searchAuthor) != NULL) {
            printf("Title: %s\nAuthor: %s\nPages: %d\nPrice: %.2f\n\n",
                   BOOKS[i].book_name, BOOKS[i].author, BOOKS[i].pages, BOOKS[i].price);
        }
    }
}

void displayLibrary() {
    printf("Books in the library:\n");
    for (int i = 0; i < num; i++) {
        printf("Title: %s\nAuthor: %s\nPages: %d\nPrice: %.2f\n\n",
               BOOKS[i].book_name, BOOKS[i].author, BOOKS[i].pages, BOOKS[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System Menu:\n");
        printf("1. Add a book\n");
        printf("2. Search by title\n");
        printf("3. Search by author\n");
        printf("4. Display all books\n");
        printf("5. Remove a book\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addbook();
                break;
            case 2:
                searchByTitle();
                break;
            case 3:
                searchByAuthor();
                break;
            case 4:
                displayLibrary();
                break;
            case 5:
                removebook();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
