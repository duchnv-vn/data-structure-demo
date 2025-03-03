#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

#define STOP_KEYWORD "stop"

struct SinhVien {
    int maso;
    string ho;
    string ten;

    SinhVien(int maso = 0, string ho = "", string ten = "") : maso{maso}, ho{ho}, ten{ten} {
    }
};

struct Node {
    SinhVien sv;
    Node *lk1;
    Node *lk2;

    Node(const SinhVien &sv) : sv{sv}, lk1(nullptr), lk2(nullptr) {
    }
};

typedef Node *PTR;

struct LinkedList {
    Node *headID;
    Node *headName;

    LinkedList() : headID(nullptr), headName(nullptr) {
    }

    void insertStudent(const SinhVien &sv);

    bool deleteStudentByID(int maso);

    Node *findStudentByID(int maso);

    void displayStudentsByID();

    void displayStudentsByName();

    void inputStudentList();

    void displayStudent(const SinhVien &sv);

    int compareNames(const char *ho1, const char *ten1, const char *ho2, const char *ten2);

private:
    bool getValidStringInput(string &buffer, const int maxLength, const char *fieldName);
};

void displayMenu();

void displayStudentListTitles();

int main() {
    LinkedList studentList{};

    while (true) {
        displayMenu();
        cout << "Nhap lua chon: ";
        string input;
        cin >> input;
        int choice;
        bool isValidChoice = true;
        try {
            choice = stoi(input);
            if (choice < 1 || choice > 6) {
                isValidChoice = false;
            }
        } catch (const std::invalid_argument &) {
            isValidChoice = false;
        } catch (const std::out_of_range &) {
            isValidChoice = false;
        }

        if (!isValidChoice) {
            cout << "Lua chon khong hop le. Vui long thu lai." << endl << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                studentList.inputStudentList();
                break;
            }
            case 2: {
                int maso;
                cout << "Nhap ma so sinh vien can xoa: ";
                if (!(cin >> maso)) {
                    cout << "Ma so khong hop le. Vui long nhap so." << endl;
                    cin.clear();
                    break;
                }
                studentList.deleteStudentByID(maso);
                break;
            }
            case 3: {
                int maso;
                cout << "Nhap ma so sinh vien can tim: ";
                if (!(cin >> maso)) {
                    cout << "Ma so khong hop le. Vui long nhap so." << endl;
                    cin.clear();
                    break;
                }
                if (const auto student = studentList.findStudentByID(maso)) {
                    displayStudentListTitles();
                    studentList.displayStudent(student->sv);
                } else
                    cout << "Khong tim thay sinh vien ma so " << maso << "." << endl;
                break;
            }
            case 4: {
                studentList.displayStudentsByID();
                break;
            }
            case 5: {
                studentList.displayStudentsByName();
                break;
            }
            case 6: {
                cout << "Ket thuc chuong trinh." << endl;
                break;
            }
            default:
                ;
        }

        cout << endl;
        if (choice == 6) break;
    }

    return 0;
}

void displayMenu() {
    cout << "===== QUAN LY DANH SACH SINH VIEN =====" << endl;
    cout << "1. Nhap danh sach sinh vien" << endl;
    cout << "2. Xoa sinh vien theo ma so" << endl;
    cout << "3. Tim sinh vien theo ma so" << endl;
    cout << "4. Liet ke DSSV tang dan theo ID" << endl;
    cout << "5. Liet ke DSSV tang dan theo ten" << endl;
    cout << "6. Ket thuc" << endl;
}

void displayStudentListTitles() {
    cout << left << setw(10) << "Ma so"
            << setw(30) << "Ho"
            << setw(15) << "Ten" << endl;
    cout << string(55, '-') << endl;
}

bool LinkedList::getValidStringInput(string &buffer, const int maxLength, const char *fieldName) {
    string input;
    bool isValid = false;

    while (!isValid) {
        cout << "Nhap " << fieldName << ": ";
        getline(cin, input);

        if (input == STOP_KEYWORD)
            return false;

        if (input.empty()) {
            cout << "Loi: " << fieldName << " khong duoc de trong. Vui long nhap lai." << endl;
        } else if (input.length() > maxLength - 1) {
            // -1 to account for null terminator
            cout << "Loi: " << fieldName << " khong duoc vuot qua " << (maxLength - 1) << " ky tu. Vui long nhap lai."
                    << endl;
        } else {
            isValid = true;
        }
    }

    buffer = input;
    return true;
}

int LinkedList::compareNames(const char *ho1, const char *ten1, const char *ho2, const char *ten2) {
    if (const int tenComp = strcmp(ten1, ten2); tenComp != 0)
        return tenComp;

    return strcmp(ho1, ho2);
}

void LinkedList::inputStudentList() {
    cout << "Nhap thong tin sinh vien. Nhap 'stop' de dung tac vu va luu thong tin sinh vien da nhap." << endl;

    int studentCount = 0;
    string input;

    while (true) {
        SinhVien sv{};

        cout << "Nhap ma so: ";
        cin >> input;
        if (input == STOP_KEYWORD)
            break;

        try {
            sv.maso = stoi(input);
            if (sv.maso <= 0) {
                cout << "Ma so phai la so nguyen duong. Vui long nhap lai." << endl;
                continue;
            }
        } catch (const std::invalid_argument &) {
            cout << "Ma so khong hop le. Vui long nhap lai." << endl;
            continue;
        } catch (const std::out_of_range &) {
            cout << "Ma so qua lon. Vui long nhap lai." << endl;
            continue;
        }

        if (findStudentByID(sv.maso) != nullptr) {
            cout << "Ma so " << sv.maso << " da ton tai. Vui long nhap ma so khac." << endl;
            continue;
        }

        cin.ignore();

        if (!getValidStringInput(sv.ho, 51, "ho")) {
            break;
        }

        if (!getValidStringInput(sv.ten, 11, "ten")) {
            break;
        }

        insertStudent(sv);
        studentCount++;

        cout << "Sinh vien da duoc them vao danh sach." << endl;
    }

    cout << "Da them " << studentCount << " sinh vien vao danh sach." << endl;
}

void LinkedList::insertStudent(const SinhVien &sv) {
    const auto newNode = new Node{sv};

    if (headID == nullptr) {
        headID = newNode;
    } else if (sv.maso < headID->sv.maso) {
        newNode->lk1 = headID;
        headID = newNode;
    } else {
        Node *current = headID;
        while (current->lk1 != nullptr && current->lk1->sv.maso < sv.maso)
            current = current->lk1;

        newNode->lk1 = current->lk1;
        current->lk1 = newNode;
    }

    if (headName == nullptr) {
        headName = newNode;
    } else if (compareNames(sv.ho.c_str(), sv.ten.c_str(), headName->sv.ho.c_str(), headName->sv.ten.c_str()) < 0) {
        newNode->lk2 = headName;
        headName = newNode;
    } else {
        Node *current = headName;
        while (current->lk2 != nullptr &&
               compareNames(current->lk2->sv.ho.c_str(), current->lk2->sv.ten.c_str(),
                            sv.ho.c_str(), sv.ten.c_str()) < 0)
            current = current->lk2;

        newNode->lk2 = current->lk2;
        current->lk2 = newNode;
    }
}

bool LinkedList::deleteStudentByID(const int maso) {
    if (headID == nullptr) {
        cout << "Danh sach rong." << endl;
        return false;
    }

    Node *prev = nullptr;
    auto current = headID;
    while (current != nullptr && current->sv.maso != maso) {
        prev = current;
        current = current->lk1;
    }

    if (current == nullptr) {
        cout << "Khong tim thay sinh vien co ma so " << maso << endl;
        return false;
    }

    const auto deleteStudentPtr = current;

    if (prev == nullptr) {
        headID = current->lk1;
    } else {
        prev->lk1 = current->lk1;
    }

    if (headName == deleteStudentPtr) {
        headName = headName->lk2;
    } else {
        current = headName;
        while (current != nullptr && current->lk2 != deleteStudentPtr) {
            current = current->lk2;
        }

        if (current != nullptr) {
            current->lk2 = deleteStudentPtr->lk2;
        }
    }

    delete deleteStudentPtr;
    cout << "Sinh vien ma so " << maso << " da duoc xoa." << endl;
    return true;
}

Node *LinkedList::findStudentByID(const int maso) {
    auto current = headID;
    while (current != nullptr) {
        if (current->sv.maso == maso)
            return current;

        current = current->lk1;
    }

    return nullptr;
}

void LinkedList::displayStudentsByID() {
    if (headID == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }

    cout << "===== DANH SACH SINH VIEN THEO MA SO =====" << endl;
    displayStudentListTitles();

    auto current = headID;
    while (current != nullptr) {
        displayStudent(current->sv);
        current = current->lk1;
    }
}

void LinkedList::displayStudentsByName() {
    if (headName == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }

    cout << "===== DANH SACH SINH VIEN THEO TEN =====" << endl;
    displayStudentListTitles();

    auto current = headName;
    while (current != nullptr) {
        displayStudent(current->sv);
        current = current->lk2;
    }
}

void LinkedList::displayStudent(const SinhVien &sv) {
    cout << left << setw(10) << sv.maso
            << setw(30) << sv.ho
            << setw(15) << sv.ten << endl;
}
