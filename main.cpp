#include<bits/stdc++.h>
using namespace std;
#define ll long long
class User {
private:
    string userName, userPassword, userEmail;
    ll userId, userAge;

public:
    static int count;

    User()
    {
        userName = "";
        userPassword = "";
        userEmail = "";
        userAge = 0;
        userId = ++count;
    }
    User(string userName, string userPassword, string userEmail, ll userAge)
            : userName(userName)
            , userPassword(userPassword)
            , userEmail(userEmail)
            , userAge(userAge)
    {
        count++;
        userId = count;
    }
    // defult contractor
    User(const User& user)
    {
        userName = user.userName;
        userPassword = user.userPassword;
        userEmail = user.userEmail;
        userAge = user.userAge;
        userId = user.userId;
    }
    void setUserName(string userName)
    {
        this->userName = userName;
    }
    void setUserPassword(string userPassword)
    {
        this->userPassword = userPassword;
    }
    void setUserEmail(string userEmail)
    {
        this->userEmail = userEmail;
    }
    void setUserAge(ll userAge)
    {
        this->userAge = userAge;
    }
    void setUserId(int userId)
    {
        this->userId = userId;
    }
    string getUserName() const
    {
        return userName;
    }
    string getUserPassword() const
    {
        return userPassword;
    }
    string getUserEmail() const
    {
        return userEmail;
    }
    ll getUserAge() const
    {
        return userAge;
    }
    ll getUserId() const
    {
        return userId;
    }
    // to comper betwen them and check if they equal or not
    bool operator==(const User& user)
    {
        if (userName != user.userName || userAge != user.userAge || userEmail != user.userEmail || userId != user.userId) {
            return false;
        }
        else {
            return true;
        }
    }
    void operator=(const User& user)
    {
        userName = user.userName;
        userAge = user.userAge;
        userPassword = user.userPassword;
        userEmail = user.userEmail;
    }
    void display()
    {
        cout << "Name:" << userName << endl
             << "Age:" << userAge << endl
             << "Id: " << userId << endl
             << "Email: " << userEmail << endl;
        cout << "***************************************************\n";
    }
    // to cin or cout an object >> << that the reason why we make operator overloding so we use friend function
    friend istream& operator>>(istream&, User&);
    friend ostream& operator<<(ostream&, const User&);
};
int User::count = 0;
istream& operator>>(istream& input, User& user)
{
    cout << "Enter the user information in this order\n";
    cout << "Name  ||  Age  ||  Email   ||   Password \n";
    input >> user.userName >> user.userAge >> user.userEmail >> user.userPassword;
    return input;
}
ostream& operator<<(ostream& output, const User& user)
{
    output << "***************User  " << user.userId << " info*****:\n";
    output << "Name :" << user.userName;
    output << "| Age :" << user.userAge;
    output << "| ID :" << user.userId;
    output << "| Email :" << user.userEmail << endl;
    cout << "*********************************************\n";
    return output;
}
class Book {
private:
    //search about isbn on google
    string bookTitle, ISBN, bookCategory;
    ll bookId;
    double bookRatingAverage;
    User author;
    int numberOfPeople;
    double sumOfRating;

public:
    static int count;
    Book()
            : bookTitle("")
            , ISBN("")
            , bookCategory("")
            , bookId(0)
            , bookRatingAverage(0.0)
            , numberOfPeople(0)
            , sumOfRating(0.0)
    {
        count++;
        bookId = count;
        User author;
    }
    Book(string bookTitle, string ISBN, string bookCategory)
            : bookTitle(bookTitle)
            , ISBN(ISBN)
            , bookCategory(bookCategory)
    {
        count++;
        bookId = count;
        bookRatingAverage = 0.0;
        numberOfPeople = 0;
        sumOfRating = 0.0;
        User author;
    }
    Book(const Book& book)
    {
        bookTitle = book.bookTitle;
        ISBN = book.ISBN;
        bookCategory = book.bookCategory;
        bookId = book.bookId;
        author = book.author;
        bookRatingAverage = book.bookRatingAverage;
        numberOfPeople = book.numberOfPeople;
        sumOfRating = book.sumOfRating;
    }
    void setBookTitle(string bookTitle)
    {
        this->bookTitle = bookTitle;
    }
    void setISBN(string ISBN)
    {
        this->ISBN = ISBN;
    }
    void setBookCategory(string bookCategory)
    {
        this->bookCategory = bookCategory;
    }
    void setBookRatingAverage(double bookRatingAverage)
    {
        this->bookRatingAverage = bookRatingAverage;
    }
    void setAuthor(const User& author)
    {
        this->author = author;
    }
    void setBookId(int bookId)
    {
        this->bookId = bookId;
    }
    string getBookTitle() const
    {
        return bookTitle;
    }
    string getISBN() const
    {
        return ISBN;
    }
    string getBookCategory() const
    {
        return bookCategory;
    }
    ll getBookId() const
    {
        return bookId;
    }
    double getBookRatingAverage() const
    {
        return bookRatingAverage;
    }
    User getAuthor() const
    {
        return author;
    }
    void rateBook(int rate)
    {
        numberOfPeople++;
        sumOfRating += rate;
        bookRatingAverage = sumOfRating / numberOfPeople;
    }
    bool operator==(const Book& book)
    {
        if (bookTitle != book.bookTitle || ISBN != book.ISBN || bookCategory != book.bookCategory || bookId != book.bookId) {
            return false;
        }
        else {
            if (author == book.author)
                return true;
            else
                return false;
        }
    }
    friend istream& operator>>(istream&, Book&);
    friend ostream& operator<<(ostream&, const Book&);
};
int Book::count = 0;
istream& operator>>(istream& input, Book& book)
{
    cout << "Enter the book information in this order\n";
    cout << "Title   ||  ISBN  ||  category  \n ";
    input >> book.bookTitle >> book.ISBN >> book.bookCategory;
    return input;
}
ostream& operator<<(ostream& output, const Book& book)
{
    output << "----------------book  " << book.bookId << " info****\n";
    output << "Title : " << book.bookTitle;
    output << "||ISBN : " << book.ISBN;
    output << "||ID : " << book.bookId;
    output << "||Category : " << book.bookCategory;
    output << "||Average rating :" << book.bookRatingAverage;
    cout << endl;
    if (book.author.getUserName() != "") {
        cout << "Author name: " << book.author << endl;
    }
    cout << "*********************************************\n";
    return output;
}
class UserList {
private:
    User* userNumber;
    int userSize;
    int userCount;

public:
    UserList()
            : userSize(0)
    {
        userCount = 0;
    }
    UserList(int size)
            : userSize(size)
    {
        userNumber = new User[size];
        userCount = 0;
    }

    void addUser(const User& user)
    {
        if (userCount < userSize) {
            userNumber[userCount] = user;
            userNumber[userCount].setUserId(userCount + 1);
            userCount++;
        }
        else
            cout << "cant add\n";
    }
    User* searchUser(string name)
    {
        for (int i = 0; i < userCount; i++) {
            if (userNumber[i].getUserName() == name)
                return &userNumber[i];
        }
        return NULL;
    }
    User* searchUser(int id)
    {
        for (int i = 0; i < userCount; i++) {
            if (userNumber[i].getUserId() == id)
                return &userNumber[i];
        }
        return NULL;
    }
    void deleteUser(int id)
    {
        for (int i = 0; i < userCount; i++) {
            if (userNumber[i].getUserId() == id) {
                while (i < userCount - 1) {
                    userNumber[i] = userNumber[i + 1];
                    userNumber[i].setUserId(i + 1);
                    i++;
                }
                userCount--;
                userSize--;
                break;
            }
        }
    }
    friend ostream& operator<<(ostream& output, UserList& userList)
    {
        for (int i = 0; i < userList.userCount; i++) {
            output << userList.userNumber[i];
        }
        return output;
    }
    ~UserList()
    {
        delete[] userNumber;
    }
};
class BookList {
private:
    Book* bookNumber;
    int bookSize, bookCount;

public:
    BookList(const BookList& booklist)
    {
    }
    BookList()
            : bookSize(0)
    {
        bookCount = 0;
    }
    BookList(int Size)
            : bookSize(Size)
    {
        bookNumber = new Book[Size];
        bookCount = 0;
    }
    void addBook(Book& book)
    {
        if (bookCount < bookSize) {
            bookNumber[bookCount] = book;
            bookNumber[bookCount].setBookId(bookCount + 1);
            bookCount++;
        }
        else
            cout << "cant add\n";
    }
    Book* searchBook(string name)
    {
        for (int i = 0; i < bookCount; i++) {
            if (bookNumber[i].getBookTitle() == name)
                return &bookNumber[i];
        }
        return NULL;
    }
    Book* searchBook(int id)
    {
        for (int i = 0; i < bookCount; i++) {
            if (bookNumber[i].getBookId() == id)
                return &bookNumber[i];
        }
        return NULL;
    }
    void deleteBook(int id)
    {
        for (int i = 0; i < bookCount; i++) {
            if (bookNumber[i].getBookId() == id) {
                while (i < bookCount - 1) {
                    bookNumber[i] = bookNumber[i + 1];
                    bookNumber[i].setBookId(i + 1);
                    i++;
                }
                bookCount--;
                bookSize--;

                break;
            }
        }
    }
    Book getTheHighestRatedBook()
    {
        double hightestRate = -1;
        int index;
        for (int i = 0; i < bookCount; i++) {
            if (bookNumber[i].getBookRatingAverage() >= hightestRate) {
                hightestRate = bookNumber[i].getBookRatingAverage();
                index = i;
            }
        }
        return bookNumber[index];
    }
    void getBooksForUser(const User& user)
    {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (bookNumber[i].getAuthor() == user) {
                found = true;
                cout << bookNumber[i];
            }
        }
        if (!found)
            cout << "not found\n ";
    } // get all books of this author
    Book& operator[](int index)
    {
        if (index < 0 || index >= bookCount) {
            cout << "Error!\n ";
            exit(1);
        }
        return bookNumber[index];
    }
    friend ostream& operator<<(ostream&, const BookList&); //to display all books
    ~BookList()
    {
        delete[] bookNumber;
    }
};
ostream& operator<<(ostream& output, const BookList& booklist)
{
    for (int i = 0; i < booklist.bookCount; i++) {
        output << booklist.bookNumber[i];
    }
    return output;
}
class run{
public:
    void main_menu()
    {
        cout << "Select one of the following choices : " << endl;
        cout << "1- Books Menu" << endl;
        cout << "2- Users Menu" << endl;
        cout << "3- Exit " << endl;
    }
    void user_menu()
    {
        cout << " USERS MENU" << endl;
        cout << "1- Create a USER and add it to the list " << endl;
        cout << "2- Search for a user " << endl;
        cout << "3- Display all users " << endl;
        cout << "4- Back to the main " << endl;
    }
    void search_user_menu()
    {
        cout << "SEARCH FOR A USER" << endl;
        cout << "1- Search by name" << endl;
        cout << "2- Search by id" << endl;
        cout << "3- Return to users Menu" << endl;
    }
    void delete_user_menu()
    {
        cout << "1- Delete user " << endl;
        cout << "2- Return to users Menu" << endl;
    }
    void book_menu()
    {
        cout << "BOOKS MENU" << endl;
        cout << "1- Create a book and add it to the list " << endl;
        cout << "2- Search for a book" << endl;
        cout << "3- Display all books (with book rating)" << endl;
        cout << "4- Get the highest rating" << endl;
        cout << "5- Get all books of a user " << endl;
        cout << "6- Back to the main menu" << endl;
    }
    void search_book_menu()
    {
        cout << "SEARCH FOR A BOOK" << endl;
        cout << "1- Search by name" << endl;
        cout << "2- Search by id" << endl;
        cout << "3- Return to Books Menu" << endl;
    }
    void search_book_name()
    {
        cout << "1- Update author" << endl;
        cout << "2- Update name" << endl;
        cout << "3- Update Category" << endl;
        cout << "4- Delete Book" << endl;
        cout << "5- rate book" << endl;
        cout << "6- Get back to books menu" << endl;
    }
    void RUN()
    {
        bool b1 = true, b2 = true, b3 = true, b4 = true, b5 = true;
        bool b6 = true, b7 = true, b8 = true, b9 = true;
        int choice1, choice2, choice3, choice4, choice5;
        int choice6, choice7, choice8, choice9;
        UserList* U;
        BookList* B;
        while (b1) {
            main_menu();
            cin >> choice1;
            switch (choice1) {
                case 1:
                    /////////////////////////////////////////////
                {
                    int NumberOfBooks;
                    cout << "How many books will be added?" << endl;
                    cin >> NumberOfBooks;
                    B = new BookList(NumberOfBooks);
                    b6 = true;
                    while (b6) {
                        book_menu();
                        cin >> choice6;
                        switch (choice6) {
                            case 1: {
                                Book b1;
                                cin >> b1;
                                ///////////////////////////////////////
                                b8 = true;
                                while (b8) {
                                    cout << "1- Assign Author" << endl;
                                    cout << "2- Continue" << endl;
                                    cin >> choice8;
                                    switch (choice8) {
                                        case 1:
                                            //////////////////////////
                                        {
                                            cout << "Enter author (user ) id : " << endl;
                                            int id;
                                            cin >> id;
                                            User* u4;
                                            u4 = U->searchUser(id);
                                            if (u4 == nullptr) {
                                                cout << "No Author Found with id = " << id << endl;
                                            }
                                            else {
                                                b1.setAuthor(*u4);
                                                B->addBook(b1);
                                                b8 = false;
                                            }
                                        }
                                            /////////////////////////
                                            break;
                                        case 2:
                                            B->addBook(b1); ////////////////////
                                            b8 = false;
                                            break;
                                        default:
                                            b8 = false;
                                    }
                                }
                                ///////////////////////////////////////
                            } break;
                            case 2: {
                                ///////////////////////////////////////////////////////////////////////
                                b7 = true;
                                while (b7) {
                                    search_book_menu();
                                    cin >> choice7;
                                    switch (choice7) {
                                        case 1: {
                                            string ss;
                                            cout << "Enter Name : " << endl;
                                            cin >> ss;
                                            Book* b2;
                                            b2 = B->searchBook(ss);
                                            if (b2 == nullptr) {
                                                cout << "Name Not Found  " << endl;
                                                b9 = false;
                                            }
                                            else {
                                                b9 = true;
                                                cout << *b2;
                                                ///////////////////////////////////////////////////////////////////
                                                while (b9) {
                                                    search_book_name();
                                                    cin >> choice9;
                                                    switch (choice9) {
                                                        case 1:
                                                            //--------------------
                                                        {
                                                            cout << "Enter author (user ) id : " << endl;
                                                            int id;
                                                            cin >> id;
                                                            /////////////////////////////////////////
                                                            User* uu;
                                                            uu = U->searchUser(id);
                                                            if (uu == nullptr) {
                                                                cout << "No Author Found with id = " << id << endl;
                                                            }
                                                            else {
                                                                Book* bb;
                                                                bb = B->searchBook(ss);
                                                                bb->setAuthor(*uu);
                                                                b2 = bb;
                                                            }
                                                            /////////////////////////////////////////
                                                        }
                                                            //-------------------
                                                            break;
                                                        case 2:
                                                            //--------------------
                                                        {
                                                            cout << "Enter new name: " << endl;
                                                            string str;
                                                            cin >> str;
                                                            Book* b5;
                                                            b5 = B->searchBook(ss);
                                                            b5->setBookTitle(str);
                                                            b2 = b5;
                                                        }
                                                            //-------------------
                                                            break;
                                                        case 3:
                                                            //--------------------
                                                        {
                                                            cout << "Enter new Category: " << endl;
                                                            string str;
                                                            cin >> str;
                                                            Book* b4;
                                                            b4 = B->searchBook(ss);
                                                            b4->setBookCategory(str);
                                                            b2 = b4;
                                                        }
                                                            //-------------------
                                                            break;
                                                        case 4:
                                                            //--------------------
                                                        {
                                                            B->deleteBook(b2->getBookId());
                                                        }
                                                            //-------------------
                                                            break;
                                                        case 5:
                                                            //--------------------
                                                        {
                                                            cout << "Enter Rating value: " << endl;
                                                            double rate_value;
                                                            cin >> rate_value;
                                                            Book* b3;
                                                            b3 = B->searchBook(ss);
                                                            b3->rateBook(rate_value);
                                                            b2 = b3;
                                                        }
                                                            //-------------------
                                                            break;
                                                        case 6:
                                                            b9 = false;
                                                            break;
                                                        default:
                                                            b9 = false;
                                                    }
                                                }
                                                ///////////////////////////////////////////////////////////////////
                                            }
                                        } break;
                                        case 2: {
                                            int ID;
                                            cout << "Enter ID : " << endl;
                                            cin >> ID;
                                            Book* b3;
                                            b3 = B->searchBook(ID);
                                            if (b3 == nullptr) {
                                                cout << "ID Not Found  " << endl;
                                            }
                                            else {
                                                cout << *b3;
                                            }
                                        } break;
                                        case 3:
                                            b7 = false;
                                            break;
                                        default:
                                            b7 = false;
                                    }
                                }
                                /////////////////////////////////////////////////////////////////////////
                            } break;
                            case 3:
                                cout << *B;
                                break;
                            case 4: {
                                Book b4;
                                b4 = B->getTheHighestRatedBook();
                                cout << b4;
                            } break;
                            case 5: {
                                int ID;
                                cout << "Enter ID" << endl;
                                cin >> ID;
                                User* u5;
                                u5 = U->searchUser(ID);
                                ///////////////////////////////////////////////////////////////
                                if (u5 == nullptr) {
                                    cout << "No Author Found with id = " << ID << endl;
                                }
                                else {
                                    B->getBooksForUser(*u5);
                                }
                                ////////////////////////////////////////////////////////////
                            } break;
                            case 6:
                                b6 = false;
                                break;
                            default:
                                b6 = false;
                        }
                    }
                }
                    /////////////////////////////////////////////
                    break;
                case 2:
                    //////////////////////////
                {
                    int NumberOfUsers;
                    cout << "How many users will be added?" << endl;
                    cin >> NumberOfUsers;
                    U = new UserList(NumberOfUsers);
                    b2 = true;
                    while (b2) {
                        user_menu();
                        cin >> choice2;
                        switch (choice2) {
                            case 1: {
                                User u1;
                                cin >> u1;
                                U->addUser(u1);
                            } break;
                            case 2:
                                /////////////////////////
                                b3 = true;
                                while (b3) {
                                    search_user_menu();
                                    cin >> choice3;
                                    switch (choice3) {
                                        case 1: {
                                            string s;
                                            cout << "Enter Name : " << endl;
                                            cin >> s;
                                            User* u2;
                                            u2 = U->searchUser(s);
                                            if (u2 == nullptr) {
                                                cout << "Name Not Found" << endl;
                                                b3 = false;
                                                b4 = false;
                                            }
                                            else {
                                                cout << *u2 << endl;
                                            }
                                            /////////////////////
                                            while (b4) {
                                                delete_user_menu();
                                                cin >> choice4;
                                                switch (choice4) {
                                                    case 1:
                                                        U->deleteUser(u2->getUserId());
                                                        b4 = false;
                                                        break;
                                                    case 2:
                                                        b4 = false;
                                                        break;
                                                    default:
                                                        b4 = false;
                                                }
                                            }
                                            /////////////////////////
                                        }
                                            b4 = true;
                                            break;
                                        case 2: {
                                            int id;
                                            cout << "Enter ID : " << endl;
                                            cin >> id;
                                            User* u3;
                                            u3 = U->searchUser(id);
                                            if (u3 == nullptr) {
                                                cout << "ID Not Found" << endl;
                                                b4 = false;
                                                b5 = false;
                                            }
                                            else {
                                                cout << *u3;
                                            }
                                            /////////////////////////////////
                                            while (b5) {
                                                delete_user_menu();
                                                cin >> choice5;
                                                switch (choice5) {
                                                    case 1:
                                                        U->deleteUser(u3->getUserId());
                                                        b5 = false;
                                                        break;
                                                    case 2:
                                                        b5 = false;
                                                        break;
                                                    default:
                                                        b5 = false;
                                                }
                                            }
                                            /////////////////////////////////////
                                        }
                                            b5 = true;
                                            break;
                                        case 3:
                                            b3 = false;
                                            break;
                                        default:
                                            b3 = false;
                                    }
                                }
                                /////////////////////////
                                break;
                            case 3:
                                cout << *U;
                                break;
                            case 4:
                                b2 = false;
                                break;
                            default:
                                b2 = false;
                        }
                    }
                }
                    ///////////////////////////
                    break;
                case 3:
                    b1 = false;
                    break;
                default:
                    b1 = false;
            }
        }
    }
};
 int main() {
run r;
r.RUN();
    return 0;
}
