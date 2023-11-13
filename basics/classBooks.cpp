#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

class Book {
    public:
        // constructor
        Book(string title, string author, int pages) {
            cout << "Creating book..." << endl;
            this->title = title;
            this->author = author;
            this->pages = pages;
        }

        // getters
        string getTitle() {return this->title;}
        string getAuthor() {return this->author;}
        int getPages() {return this->pages;}

        // setters
        void setTitle(string title) {this->title = title;}
        void setAuthor(string author) {this->author = author;}
        void setPages(int pages) {this->pages = pages;}

        // methods
        void printBook() {
            cout << "Book: [title=" << this->title << ", author=" << this->author << ", pages=" << this->pages << "]" << endl;
        }

        bool longBook() {
            if (this->pages >= 500) {
                return true;
            } else {
                return false;
            }
        }
    private:
        // members
        string title;
        string author;
        int pages;
};

int main() {
    vector<Book> books;
    Book book1("Harry Potter", "J.K. Rowling", 500);
    books.push_back(book1);
    Book book2("Lord of the Rings", "J.R.R. Tolkien", 600);
    books.push_back(book2);

    books.push_back(Book("Chronicles of Narnia", "C.S. Lewis", 400));
    
    for (auto e : books) {
        e.printBook();
    }

    for (auto e : books) {
        if (e.longBook()) {
            cout << e.getTitle() << " is a long book." << endl;
        } else {
            cout << e.getTitle() << " is a short book." << endl;
        }
    }
    return 0;
}