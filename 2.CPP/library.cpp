#include <iostream>
using namespace std;

const int MAX_ITEMS = 10; 


class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:

    void setTitle(string newTitle) 
	{ title = newTitle; 
	
	}
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }
    

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }


    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    // Virtual destructor
    virtual ~LibraryItem() {}
};

// Book class
class Book : public LibraryItem {
private:
    string isbn;
    bool isCheckedOut;

public:
    Book(string title, string author, string dueDate, string isbn)
        : isbn(isbn), isCheckedOut(false) {
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
    }

    void checkOut() override {
        if (isCheckedOut)
            cout << "Book is already checked out.\n";
        else {
            isCheckedOut = true;
            cout << "Book checked out successfully.\n";
        }
    }

    void returnItem() override {
        if (!isCheckedOut)
            cout << "Book is not currently checked out.\n";
        else {
            isCheckedOut = false;
            cout << "Book returned successfully.\n";
        }
    }

    void displayDetails() const override {
        cout << "\n[Book]\n";
        cout << "Title: " << getTitle() << "\n";
        cout << "Author: " << getAuthor() << "\n";
        cout << "Due Date: " << getDueDate() << "\n";
        cout << "ISBN: " << isbn << "\n";
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << "\n";
    }
};

// DVD class
class DVD : public LibraryItem {
private:
    int duration; // in minutes
    bool isCheckedOut;

public:
    DVD(string title, string author, string dueDate, int duration)
        : duration(duration), isCheckedOut(false) {
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
    }

    void checkOut() override {
        if (isCheckedOut)
            cout << "DVD is already checked out.\n";
        else {
            isCheckedOut = true;
            cout << "DVD checked out successfully.\n";
        }
    }

    void returnItem() override {
        if (!isCheckedOut)
            cout << "DVD is not currently checked out.\n";
        else {
            isCheckedOut = false;
            cout << "DVD returned successfully.\n";
        }
    }

    void displayDetails() const override {
        cout << "\n[DVD]\n";
        cout << "Title: " << getTitle() << "\n";
        cout << "Author: " << getAuthor() << "\n";
        cout << "Due Date: " << getDueDate() << "\n";
        cout << "Duration: " << duration << " minutes\n";
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << "\n";
    }
};

// Magazine class
class Magazine : public LibraryItem {
private:
    int issueNumber;
    bool isCheckedOut;

public:
    Magazine(string title, string author, string dueDate, int issueNumber)
        : issueNumber(issueNumber), isCheckedOut(false) {
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
    }

    void checkOut() override {
        if (isCheckedOut)
            cout << "Magazine is already checked out.\n";
        else {
            isCheckedOut = true;
            cout << "Magazine checked out successfully.\n";
        }
    }

    void returnItem() override {
        if (!isCheckedOut)
            cout << "Magazine is not currently checked out.\n";
        else {
            isCheckedOut = false;
            cout << "Magazine returned successfully.\n";
        }
    }

    void displayDetails() const override {
        cout << "\n[Magazine]\n";
        cout << "Title: " << getTitle() << "\n";
        cout << "Author: " << getAuthor() << "\n";
        cout << "Due Date: " << getDueDate() << "\n";
        cout << "Issue #: " << issueNumber << "\n";
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << "\n";
    }
};

// Menu
void menu() {
    cout << "\n--- Library Management System ---\n";
    cout << "1. Add Book\n";
    cout << "2. Add DVD\n";
    cout << "3. Add Magazine\n";
    cout << "4. Display All Items\n";
    cout << "5. Check Out Item\n";
    cout << "6. Return Item\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount = 0;

    int choice;
    do {
        menu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        try {
            if (choice == 1 || choice == 2 || choice == 3) {
                if (itemCount >= MAX_ITEMS) {
                    cout << "Library is full.\n";
                    continue;
                }

                string title, author, dueDate;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);

                cout << "Enter author: ";
                getline(cin, author);

                cout << "Enter due date: ";
                getline(cin, dueDate);

                if (choice == 1) {
                    string isbn;
                    cout << "Enter ISBN: ";
                    getline(cin, isbn);

                    if (isbn.length() < 5)
                        throw "Invalid ISBN format.";

                    libraryItems[itemCount++] = new Book(title, author, dueDate, isbn);
                    cout << "Book added successfully.\n";
                } else if (choice == 2) {
                    int duration;
                    cout << "Enter duration (in minutes): ";
                    cin >> duration;

                    if (duration <= 0)
                        throw "Invalid duration.";

                    libraryItems[itemCount++] = new DVD(title, author, dueDate, duration);
                    cout << "DVD added successfully.\n";
                } else if (choice == 3) {
                    int issueNumber;
                    cout << "Enter issue number: ";
                    cin >> issueNumber;

                    if (issueNumber <= 0)
                        throw "Invalid issue number.";

                    libraryItems[itemCount++] = new Magazine(title, author, dueDate, issueNumber);
                    cout << "Magazine added successfully.\n";
                }

            } else if (choice == 4) {
                for (int i = 0; i < itemCount; i++) {
                    cout << "\nItem #" << (i + 1) << ":\n";
                    libraryItems[i]->displayDetails();
                }

            } else if (choice == 5) {
                int index;
                cout << "Enter item number to check out: ";
                cin >> index;
                if (index <= 0 || index > itemCount)
                    throw "Invalid item number.";
                libraryItems[index - 1]->checkOut();

            } else if (choice == 6) {
                int index;
                cout << "Enter item number to return: ";
                cin >> index;
                if (index <= 0 || index > itemCount)
                    throw "Invalid item number.";
                libraryItems[index - 1]->returnItem();

            } else if (choice == 0) {
                cout << "Exiting...\n";
            } else {
                cout << "Invalid choice. Try again.\n";
            }

        } catch (const char* e) {
            cout << "Error: " << e << "\n";
        } catch (...) {
            cout << "An unexpected error occurred.\n";
        }

    } while (choice != 0);

    // Clean up memory
    for (int i = 0; i < itemCount; ++i)
        delete libraryItems[i];

    return 0;
}
