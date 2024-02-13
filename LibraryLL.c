#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book {
    int book_id;
    char book_name[100];
    char author[100];
    struct Book* next_book;
};

struct Book* head = NULL;

struct Book* createNewBook(int book_id, const char* book_name, const char* author) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->book_id = book_id;
    strcpy(newBook->book_name, book_name);
    strcpy(newBook->author, author);
    newBook->next_book = NULL;
    return newBook;
}

void addBook(int book_id, const char* book_name, const char* author) {
    struct Book* newBook = createNewBook(book_id, book_name, author);
    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* temp = head;
        while (temp->next_book != NULL) {
            temp = temp->next_book;
        }
        temp->next_book = newBook;
    }
}

void display_book(struct Book* head) {
    struct Book* current = head;
    while (current != NULL) {
        printf("Book id: %d\tBook Name: %s\tAuthor: %s\n", current->book_id, current->book_name, current->author);
        current = current->next_book;
    }
    printf("\n");
}

int main() {
    addBook(110, "Harry Potter and Goblet of Fire", "J K Rowling");
    addBook(111, "The Time Machine", "H.G. Wells");
    addBook(112, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari");
    
    display_book(head);
    
    // Free allocated memory (not done in this example, but important in real-world usage)
    
    return 0;
}
