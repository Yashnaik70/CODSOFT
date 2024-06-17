#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip> 
#include <algorithm> 

#ifdef _WIN32
#include <windows.h>
#else
#endif

using namespace std;


struct Book {
    string Title;
    string Author;
    string ISBN;
    bool isAvailable;
};

struct Borrower {
    string name;
    string BorrowerID;
    string borrowedISBN;
    tm dueDate;

    bool operator==(const Borrower& other) const {
        return BorrowerID == other.BorrowerID && borrowedISBN == other.borrowedISBN;
    }
};

tm addDaysToDate(const tm& date, int days) {
    tm newDate = date;
    const time_t ONE_DAY = 24 * 60 * 60;
    time_t date_seconds = mktime(&newDate) + (days * ONE_DAY);
    return *localtime(&date_seconds);
}

void clearScreen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

class LibrarySystem {
public:
    void addBook(const string &Title, const string &Author, const string &ISBN) {
        books.push_back({Title, Author, ISBN, true});
    }

    void Search_Book() {
        clearScreen();
        int choice;
        string query;
        cout << "===== SEARCH BOOK =====\n";
        cout << "=======================\n";
        cout << "SEARCH BY: 1. Title 2. Author 3. ISBN\nENTER YOUR CHOICE--: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "ENTER TITLE--: ";
                getline(cin, query);
                Search_By_Title(query);
                break;
            case 2:
                cout << "ENTER AUTHOR--: ";
                getline(cin, query);
                Search_By_Author(query);
                break;
            case 3:
                cout << "ENTER ISBN--: ";
                getline(cin, query);
                Search_By_ISBN(query);
                break;
            default:
                cout << "INVALID CHOICE." << '\n'; 
        }
    }

    void Ceckout_Book() {
        clearScreen();
        string BorrowerName, BorrowerID, ISBN;
        cout << "===== CHECKOUT BOOK =====\n";
        cout << "=========================\n";
        cout << "ENTER BORROWER NAME--: ";
        cin.ignore();
        getline(cin, BorrowerName);
        cout << "ENTER BORROWER ID--: ";
        getline(cin, BorrowerID);
        cout << "ENTER BOOK ISBN--: ";
        getline(cin, ISBN);

        for (auto &book : books) {
            if (book.ISBN == ISBN && book.isAvailable) {
                book.isAvailable = false;

                time_t now = time(0);
                tm* now_tm = localtime(&now);
                tm dueDate = addDaysToDate(*now_tm, 7); 

                borrowers.push_back({BorrowerName, BorrowerID, ISBN, dueDate});
                cout << "BOOK CHECKED OUT SUCCESSFULLY. DUE DATE: "
                     << setw(2) << setfill('0') << dueDate.tm_mday << '/' << setw(2) << setfill('0') << (dueDate.tm_mon + 1) << '/' << (dueDate.tm_year + 1900) << '\n';
                cout << "FINE AFTER DUE DATE RS.5 PER DAY \n\n";

                return;
            }
        }
        cout << "BOOK NOT AVAILABLE OR INVALID ISBN." << '\n';
    }

    void Return_Book() {
        clearScreen();
        string ISBN;
        cout << "===== RETURN BOOK =====\n";
        cout << "=======================\n";
        cout << "ENTER BOOK ISBN TO RETURN--: ";
        cin.ignore();
        getline(cin, ISBN);

        for (auto it = borrowers.begin(); it != borrowers.end(); ++it) {
            if (it->borrowedISBN == ISBN) {
                time_t now = time(0);
                tm* now_tm = localtime(&now);

                time_t dueDate_seconds = mktime(&it->dueDate);
                time_t now_seconds = mktime(now_tm);
                if (now_seconds > dueDate_seconds) {
                    double fine = difftime(now_seconds, dueDate_seconds) / (24 * 60 * 60) * 5.0; 
                    cout << "BOOK IS OVERDUE. FINE: RS." << fine << '\n';
                }
                Update_Book_Status(ISBN, true);
                borrowers.erase(it); 
                cout << "\n\t\tBOOK RETURNED SUCCESSFULLY.\n" << '\n';
                return;
            }
        }
        cout << "\nINVALID ISBN OR BOOK NOT CHECKED OUT." << '\n'; 
    }

private:
    vector<Book> books;
    vector<Borrower> borrowers;

    void Search_By_Title(const string &Title) {
        cout << "\nSEARCH RESULTS:\n";
        for (const auto &book : books) {
            if (book.Title.find(Title) != string::npos) {
                Display_Book_Info(book);
            }
        }
    }

    void Search_By_Author(const string &Author) {
        cout << "\nSEARCH RESULTS:\n";
        for (const auto &book : books) {
            if (book.Author.find(Author) != string::npos) {
                Display_Book_Info(book);
            }
        }
    }

    void Search_By_ISBN(const string &ISBN) {
        cout << "\nSEARCH RESULTS:\n";
        for (const auto &book : books) {
            if (book.ISBN == ISBN) {
                Display_Book_Info(book);
            }
        }
    }

    void Display_Book_Info(const Book &book) {
        cout << "TITLE--: " << book.Title << '\n' << " AUTHOR--: " << book.Author
             << '\n' << " ISBN--: " << book.ISBN << '\n' << " AVAILABLE--: " << (book.isAvailable ? "YES\n" : "NO\n") << '\n';
    }

    void Update_Book_Status(const string &ISBN, bool isAvailable) {
        for (auto &book : books) {
            if (book.ISBN == ISBN) {
                book.isAvailable = isAvailable;
                return;
            }
        }
    }
};

void showMenu() {
    cout << "\n===== WELCOME TO THE LIBRARY MANAGEMENT SYSTEM =====\n";
    cout << "======================================================\n";
    cout << "1. ADD BOOK\n";
    cout << "2. SEARCH BOOK\n";
    cout << "3. CHECKOUT BOOK\n";
    cout << "4. RETURN BOOK\n";
    cout << "5. EXIT\n";
    cout << "======================================================\n";
    cout << "ENTER YOUR CHOICE--: ";
}

int main() {
    LibrarySystem librarySystem;
    int choice;
    string Title, Author, ISBN;
    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                clearScreen();
                cout << "===== ADD BOOK =====\n";
                cout << "====================\n";
                cout << "\nENTER BOOK TITLE--: ";
                cin.ignore();
                getline(cin, Title);
                cout << "ENTER BOOK AUTHOR--: ";
                getline(cin, Author);
                cout << "ENTER BOOK ISBN--: ";
                getline(cin, ISBN);
                librarySystem.addBook(Title, Author, ISBN);
                cout << "\n\t\tBOOK ADDED SUCCESSFULLY.\n" << '\n';
                break;
            case 2:
                librarySystem.Search_Book();
                break;
            case 3:
                librarySystem.Ceckout_Book();
                break;
            case 4:
                librarySystem.Return_Book();
                break;
            case 5:
                cout << "\n\t\tEXITING THE PROGRAM\n" << '\n';
                cout << "\n\t\tTHANK YOU FOR USING THIS ...\n" << '\n';
                return 0;
            default:
                cout << "\nINVALID CHOICE. PLEASE TRY AGAIN....\n" << '\n';
        }
    }
    return 0;
}
