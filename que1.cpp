#include <iostream>
#include <vector>
using namespace std;

// Linked List

class LinkedList 
{
    vector<int> data;

public:
    void insertAtFront(int value) 
    {
        data.insert(data.begin(), value);
    }

    void insertAtEnd(int value) 
    {
        data.push_back(value);
    }

    void insertAtIndex(int value, int index) 
    {
        if(index < 0 || index > data.size()) 
        {
            cout << "Invalid index." << endl;
            return;
        }
        data.insert(data.begin() + index, value);
    }

    void deleteAtFront() 
    {
        if(data.empty()) 
        {
            cout << "List is empty." << endl;
            return;
        }
        data.erase(data.begin());
    }

    void deleteAtEnd() 
    {
        if(data.empty()) 
        {
            cout << "List is empty." << endl;
            return;
        }
        data.pop_back();
    }

    void deleteAtIndex(int index) 
    {
        if(index < 0 || index >= data.size()) 
        {
            cout << "Invalid index." << endl;
            return;
        }
        data.erase(data.begin() + index);
    }

    void updateList(int index, int value) 
    {
        if(index < 0 || index >= data.size()) 
        {
            cout << "Invalid index." << endl;
            return;
        }
        data[index] = value;
    }

    void printList() 
    {
        cout << "Linked List: ";
        for(int value : data) 
        {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, element, index;

    do {
        cout << endl << "-----------------" << endl;
        cout << "Enter 1 for insert at front" << endl;
        cout << "Enter 2 for insert at end" << endl;
        cout << "Enter 3 for insert at index" << endl;
        cout << "Enter 4 for delete at front" << endl;
        cout << "Enter 5 for delete at end" << endl;
        cout << "Enter 6 for delete at index" << endl;
        cout << "Enter 7 for update list" << endl;
        cout << "Enter 8 for view list" << endl;
        cout << "Enter 0 for exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter element to insert at front: ";
                cin >> element;
                list.insertAtFront(element);
            break;

            case 2:
                cout << "Enter element to insert at end: ";
                cin >> element;
                list.insertAtEnd(element);
            break;

            case 3:
                cout << "Enter element: ";
                cin >> element;
                cout << "Enter index: ";
                cin >> index;
                list.insertAtIndex(element, index);
            break;

            case 4:
                list.deleteAtFront();
            break;

            case 5:
                list.deleteAtEnd();
            break;

            case 6:
                cout << "Enter index: ";
                cin >> index;
                list.deleteAtIndex(index);
            break;

            case 7:
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter element: ";
                cin >> element;
                list.updateList(index, element);
            break;

            case 8:
                list.printList();
            break;

            case 0:
                cout << "Exiting." << endl;
            break;

            default:
                cout << "Wrong Choice." << endl;
            break;
        }

    } while(choice != 0);

    return 0;
}