#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50
#define MAX_AUTHOR 30

struct Book
{
    int accession_number;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float price;
    int is_issued;
};

struct Library
{
    struct Book books[MAX_BOOKS];
    int count;
};

void addBook(struct Library *lib);
void displayBooks(struct Library *lib);
void listAuthorBooks(struct Library *lib);
void searchBook(struct Library *lib);
void displayCount(struct Library *lib);
void sortByAccession(struct Library *lib);
void displayMenu();

int main()
{
    struct Library lib = {{0}, 0};
    int choice;

    do
    {
        displayMenu();
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addBook(&lib);
            break;
        case 2:
            displayBooks(&lib);
            break;
        case 3:
            listAuthorBooks(&lib);
            break;
        case 4:
            searchBook(&lib);
            break;
        case 5:
            displayCount(&lib);
            break;
        case 6:
            sortByAccession(&lib);
            displayBooks(&lib);
            break;
        case 7:
            printf("Thank you for using the Library Management System!\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void displayMenu()
{
    printf("\n=== Library Management System ===\n");
    printf("1. Add book information\n");
    printf("2. Display book information\n");
    printf("3. List all books of given author\n");
    printf("4. List the title of specified book\n");
    printf("5. List the count of books in the library\n");
    printf("6. List the books in the order of accession number\n");
    printf("7. Exit\n");
}

void addBook(struct Library *lib)
{
    if (lib->count >= MAX_BOOKS)
    {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    struct Book *newBook = &lib->books[lib->count];

    newBook->accession_number = lib->count + 1;

    printf("Enter book title: ");
    fgets(newBook->title, MAX_TITLE, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = 0;

    printf("Enter author name: ");
    fgets(newBook->author, MAX_AUTHOR, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = 0;

    printf("Enter price: ");
    scanf("%f", &newBook->price);

    newBook->is_issued = 0;
    lib->count++;

    printf("Book added successfully!\n");
}

void displayBooks(struct Library *lib)
{
    if (lib->count == 0)
    {
        printf("No books in the library!\n");
        return;
    }

    printf("\nList of all books:\n");
    printf("%-10s %-30s %-20s %-10s %-10s\n",
           "Acc No.", "Title", "Author", "Price", "Status");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < lib->count; i++)
    {
        printf("%-10d %-30s %-20s %-10.2f %s\n",
               lib->books[i].accession_number,
               lib->books[i].title,
               lib->books[i].author,
               lib->books[i].price,
               lib->books[i].is_issued ? "Issued" : "Available");
    }
}

void listAuthorBooks(struct Library *lib)
{
    char author[MAX_AUTHOR];
    int found = 0;

    printf("Enter author name: ");
    fgets(author, MAX_AUTHOR, stdin);
    author[strcspn(author, "\n")] = 0;

    printf("\nBooks by %s:\n", author);
    for (int i = 0; i < lib->count; i++)
    {
        if (strcasecmp(lib->books[i].author, author) == 0)
        {
            printf("- %s (Accession No: %d)\n",
                   lib->books[i].title,
                   lib->books[i].accession_number);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No books found by this author.\n");
    }
}

void searchBook(struct Library *lib)
{
    int acc_no;
    printf("Enter accession number: ");
    scanf("%d", &acc_no);

    for (int i = 0; i < lib->count; i++)
    {
        if (lib->books[i].accession_number == acc_no)
        {
            printf("\nBook Details:\n");
            printf("Title: %s\n", lib->books[i].title);
            printf("Author: %s\n", lib->books[i].author);
            printf("Price: %.2f\n", lib->books[i].price);
            printf("Status: %s\n",
                   lib->books[i].is_issued ? "Issued" : "Available");
            return;
        }
    }

    printf("Book not found!\n");
}

void displayCount(struct Library *lib)
{
    printf("Total number of books in the library: %d\n", lib->count);
    printf("Available books: %d\n", lib->count);
}

void sortByAccession(struct Library *lib)
{
    struct Book temp;

    for (int i = 0; i < lib->count - 1; i++)
    {
        for (int j = 0; j < lib->count - i - 1; j++)
        {
            if (lib->books[j].accession_number > lib->books[j + 1].accession_number)
            {
                temp = lib->books[j];
                lib->books[j] = lib->books[j + 1];
                lib->books[j + 1] = temp;
            }
        }
    }
}