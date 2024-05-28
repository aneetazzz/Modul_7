#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

class Queue {
private:
    Node* front; 
    Node* back; 
public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    void enqueueAntrian(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        cout << "\nAntrian ditambahkan: Nama: " << nama << ", NIM: " << nim << endl;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        cout << "\nAntrian dihapus: Nama: " << front->nama << ", NIM: " << front->nim << endl;
        front = front->next;
        delete temp;
    }

    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
        cout << "\nAntrian dikosongkan" << endl;
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        cout << "\nData antrian mahasiswa:" << endl;
        Node* current = front;
        int position = 1;
        while (current != nullptr) {
            cout << position << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            position++;
        }
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue antrian;
    antrian.enqueueAntrian("Anita Nurazizah Agussalim", "2311102017");
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.dequeueAntrian();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.clearQueue();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    return 0;
}