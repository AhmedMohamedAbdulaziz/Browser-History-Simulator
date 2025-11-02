#include <iostream>
#include <cstring>
using namespace std;

struct Website {
    char url[100];
};

class Stack {
private:
    Website sites[100];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == 99; }

    void push(Website w) {
        if (isFull()) {
            cout << "Stack full! Cannot visit more sites.\n";
            return;
        }
        sites[++top] = w;
    }

    Website pop() {
        Website temp;
        if (isEmpty()) {
            strcpy_s(temp.url, sizeof(temp.url), "None");
            return temp;
        }
        return sites[top--];
    }

    Website peek() {
        Website temp;
        if (isEmpty()) {
            strcpy_s(temp.url, sizeof(temp.url), "None");
            return temp;
        }
        return sites[top];
    }

    void clear() {
        top = -1;
    }
};

class History {
private:
    Website* visited;
    int size;
public:
    History() {
        visited = nullptr;
        size = 0;
    }

    void add(Website w) {
        Website* newArr = new Website[size + 1];
        for (int i = 0; i < size; i++)
            newArr[i] = visited[i];
        newArr[size++] = w;
        delete[] visited;
        visited = newArr;
    }

    void show() {
        if (size == 0) {
            cout << "No browsing history.\n";
            return;
        }
        cout << "\nBrowsing History:\n";
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << visited[i].url << "\n";
        }
    }
};

int main() {
    Stack backStack, forwardStack;
    History history;
    Website current;
    strcpy_s(current.url, sizeof(current.url), "Home");

    int choice;
    do {
        cout << "\n===== BROWSER HISTORY SIMULATOR =====\n";
        cout << "Current Page: " << current.url << "\n";
        cout << "1. Visit new site\n";
        cout << "2. Go back\n";
        cout << "3. Go forward\n";
        cout << "4. Show current page\n";
        cout << "5. Show browsing history\n";
        cout << "6. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Website newSite;
            cout << "Enter website URL: ";
            cin >> newSite.url;

            backStack.push(current);
            forwardStack.clear();
            current = newSite;
            history.add(newSite);
            cout << "You are now visiting: " << current.url << "\n";
        }

        else if (choice == 2) {
            if (backStack.isEmpty()) {
                cout << "No more pages to go back to.\n";
                continue;
            }
            forwardStack.push(current);
            current = backStack.pop();
            cout << "You are now on: " << current.url << "\n";
        }

        else if (choice == 3) {
            if (forwardStack.isEmpty()) {
                cout << "No pages to go forward to.\n";
                continue;
            }
            backStack.push(current);
            current = forwardStack.pop();
            cout << "You are now on: " << current.url << "\n";
        }

        else if (choice == 4) {
            cout << "Current Page: " << current.url << "\n";
        }

        else if (choice == 5) {
            history.show();
        }

        else if (choice == 6) {
            cout << "Exiting browser simulator...\n";
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
