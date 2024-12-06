#include <iostream>
#include <string>
using namespace std;

struct BookNode {
    string bookTitle;
    string returnDate; 
    BookNode* nextBook;
};

struct MemberNode {
    string memberName;
    string memberID;
    BookNode* bookHead; 
    MemberNode* nextMember;
};

MemberNode* memberHead = nullptr;

void addMember(const string& name, const string& id) {
    MemberNode* newMember = new MemberNode{name, id, nullptr, memberHead};
    memberHead = newMember;
}

void addBook(const string& memberID, const string& bookTitle, const string& returnDate) {
    MemberNode* currentMember = memberHead;
    while (currentMember) {
        if (currentMember->memberID == memberID) {
            BookNode* newBook = new BookNode{bookTitle, returnDate, currentMember->bookHead};
            currentMember->bookHead = newBook;
            return;
        }
        currentMember = currentMember->nextMember;
    }
    cout << "Member with ID " << memberID << " not found.\n";
}

void deleteMember(const string& memberID) {
    MemberNode* prevMember = nullptr;
    MemberNode* currentMember = memberHead;

    while (currentMember) {
        if (currentMember->memberID == memberID) {
            if (prevMember) {
                prevMember->nextMember = currentMember->nextMember;
            } else {
                memberHead = currentMember->nextMember;
            }

            BookNode* currentBook = currentMember->bookHead;
            while (currentBook) {
                BookNode* tempBook = currentBook;
                currentBook = currentBook->nextBook;
                delete tempBook;
            }

            delete currentMember;
            cout << "Member with ID " << memberID << " and their borrowed books have been removed.\n";
            return;
        }
        prevMember = currentMember;
        currentMember = currentMember->nextMember;
    }
    cout << "Member with ID " << memberID << " not found.\n";
}

void displayMembers() {
    cout << "========== LIBRARY MEMBERS ==========\n";
    MemberNode* currentMember = memberHead;
    while (currentMember) {
        cout << "Member Name  : " << currentMember->memberName << "\n";
        cout << "Member ID    : " << currentMember->memberID << "\n";

        cout << "Borrowed Books:\n";
        BookNode* currentBook = currentMember->bookHead;
        if (!currentBook) {
            cout << "  (No books borrowed)\n";
        } else {
            while (currentBook) {
                cout << "  📚 " << currentBook->bookTitle 
                     << " (Return Date: " << currentBook->returnDate << ")\n";
                currentBook = currentBook->nextBook;
            }
        }
        cout << "-------------------------------------\n";
        currentMember = currentMember->nextMember;
    }
    cout << "=====================================\n";
}

int main() {
    addMember("Rani", "A001");
    addMember("Dito", "A002");
    addMember("Vina", "A003");

    addBook("A001", "Pemrograman C++", "01/12/2024");
    addBook("A002", "Algoritma Pemrograman", "15/12/2024");

    addBook("A001", "Struktur Data", "10/12/2024");

    deleteMember("A002");

    displayMembers();

    return 0;
}
