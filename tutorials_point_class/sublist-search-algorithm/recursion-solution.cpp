#include <iostream>
using namespace std;

struct Node {
    int data{};
    Node *next{nullptr};
};

bool sublistSearch(const Node *list, const Node *sublist, const Node *tempList, const Node *tempSublist,
                   const bool isMatched) {
    if (!list && !sublist) return true;

    if (!list || !sublist) return false;

    if (!tempSublist) return false;

    if (!tempList) return false;

    cout << "data: " << tempList->data << endl;
    if (tempList->data != tempSublist->data) {
        if (isMatched) {
            return sublistSearch(list, sublist, tempList, sublist, false);
        } else {
            return sublistSearch(list, sublist, tempList->next, sublist, false);
        }
    }

    cout << "matched data: " << tempSublist->data << endl;

    return sublistSearch(list, sublist, tempList->next, tempSublist->next, true);
}

int main() {
    auto list = new Node{2};
    list->next = new Node{5};
    list->next->next = new Node{3};
    list->next->next->next = new Node{3};
    list->next->next->next->next = new Node{6};
    list->next->next->next->next->next = new Node{7};
    list->next->next->next->next->next->next = new Node{0};

    auto sublist = new Node{3};
    sublist->next = new Node{6};
    sublist->next->next = new Node{7};

    if (sublistSearch(list, sublist, list, sublist, false)) {
        cout << "Found the sublist" << endl;
    } else {
        cout << "The sublist is not found" << endl;
    }

    while (list) {
        const auto tempNode = list;
        list = list->next;
        delete tempNode;
    }
    while (sublist) {
        const auto tempNode = sublist;
        sublist = sublist->next;
        delete tempNode;
    }

    return 0;
}
