#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class List {
private:
    // node struktura talpinanti duomenys ir pointerius i praeita ir sekanti node
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };
    // pointeriai i listo pradzia ir pabaiga
    Node* head;
    Node* tail;
    // list dydis
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List() { clear(); }

    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }

    void addNode(const T& data, const string& position) {
        // naujo node sukurimas
        Node* newNode = new Node{ data, nullptr, nullptr };
        // start - listo pradzia
        if (position == "start") {
            if (head == nullptr) {
                // jeigu listas tuscias, head ir tail pointina i nauja node
                // praeitas ir sekantis node pointina i nauja node
                head = newNode;
                tail = newNode;
                newNode->prev = newNode;
                newNode->next = newNode;
            }
            else {
                // jeigu listas ne tuscias, praeitas ir sekantis node pointina i nauja node
                // praeitas ir sekantis node pointina i egzistuojancius nodes
                newNode->prev = tail;
                newNode->next = head;
                head->prev = newNode;
                tail->next = newNode;
                // tail pointina i nauja node
                tail = newNode;
            }
        }
        // inside - vidury
        else if (position == "inside") {
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
                newNode->prev = newNode;
                newNode->next = newNode;
            }
            else {
                // jeigu listas ne tuscias surandama teisinga pozicija naujam node
                Node* curr = head;
                while (curr->next != head && (curr->data < data || (curr->data == data && curr->next != head))) {
                    curr = curr->next;
                }
                if (curr->data >= data) {
                    newNode->prev = curr->prev;
                    newNode->next = curr;
                    curr->prev->next = newNode;
                    curr->prev = newNode;
                    //jeigu node pridedamas listo pradziojem, head pointina i pradzia
                    if (curr == head) {
                        head = newNode;
                    }
                }
                else {
                    newNode->prev = curr;
                    newNode->next = head;
                    curr->next = newNode;
                    head->prev = newNode;
                    tail = newNode;
                }
            }
        }
        // end - pabaigoje
        else if (position == "end") {
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
                newNode->prev = newNode;
                newNode->next = newNode;
            }
            else {
                newNode->prev = head;
                newNode->next = head->next;
                head->next->prev = newNode;
                head->next = newNode;
                head = newNode;
            }
        }
        size++;
    }

    void deleteNode(const string& position) {
        if (head != nullptr) {
            Node* curr = nullptr;
            if (position == "start") {
                curr = head;
                head = head->next;
                head->prev = tail;
                tail->next = head;
            }
            // jeigu pozicija inside - istrinama antra node
            else if (position == "inside") {
                curr = head->next;
                if (curr->next == head) {
                    // jeigu liko 2 nodes, sekanti ir praeita node pointina i likusias nodes
                    curr->prev->next = head;
                    head->prev = curr->prev;
                }
                else {
                    // jeigu liko dauguiau liko daugiau nei 2 nodes, sekanti ir praeita node pointina i aplinkines nodes
                    curr->prev->next = tail;
                    tail->prev = curr->prev;
                }
            }
            else if (position == "end") {
                curr = tail;
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
            }
            delete curr;
            size--;
        }
    }

    Node* search(const T& data) {
        // pradedam nuo pradzios
        Node* curr = head;
        // pradedam nuo pradzios kol randama node ir ja graziname
        while (curr->data != data && curr->next != head) {
            curr = curr->next;
        }
        if (curr->data == data) {
            return curr;
        }
        // jeigu nerandama graziname nullptr
        else {
            return nullptr;
        }
    }

    void display() const {
        if (!isEmpty()) {
            Node* curr = head;
            // counteris seka kuris node yra rodomas
            int counter = 0;  

            while (curr->next != head && counter < size) {  
                cout << curr->data << " ";
                curr = curr->next;
                counter++;  
            }

            cout << curr->data << endl;
        }
    }

    void reverse() {
        if (!isEmpty()) {
            Node* curr = head;
            head = tail;
            tail = curr;
            Node* temp = nullptr;
            do {
                temp = curr->next;
                curr->next = curr->prev;
                curr->prev = temp;
                curr = temp;
            } while (curr != head);
        }
    }

    void clear() {
        if (head != nullptr) {
            Node* curr = head;
            // einame pro lista ir triname kiekviena node kol pasiekiame gala
            do {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            } while (curr != head);
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
    }
};

    int main() {
        
        List<int> list;
        list.addNode(1, "start");
        list.addNode(2, "start");
        list.addNode(3, "start");
        list.display();


        return 0;
    }
