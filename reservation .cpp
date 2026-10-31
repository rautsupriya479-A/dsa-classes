#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Passenger {
    int seatNo;
    int age;
    string name;
    string gender;
    Passenger* next;
};
class Train {
    int* seats;
    Passenger* head;
    int n;
public:
    Train() {
        n = 30;
        seats = (int*)malloc(n * sizeof(int));
        head = NULL;

        for (int i = 0; i < n; i++)
            seats[i] = 0;
    }
    void bookTicket() {
        int i;
        for (i = 0; i < n; i++)
            if (seats[i] == 0)
                break;
                 if (i == n) {
            cout << "Train is full!\n";
            return;
        }

        Passenger* p = new Passenger;

        p->seatNo = i + 1;
        cout << "Enter Name: ";
        getline(cin >> ws, p->name);

        cout << "Enter Age: ";
        cin >> p->age;

        cout << "Enter Gender: ";
        cin >> p->gender;

        p->next = head;
        head = p;
        seats[i] = 1;

        cout << "Ticket booked! Seat No: " << i + 1 << endl;
    }

    void cancelTicket() {
        int s;
        cout << "Enter seat number: ";
        cin >> s;

        if (s < 1 || s > n || seats[s - 1] == 0) {
            cout << "Seat not booked!\n";
            return;
        }

        Passenger *p = head, *prev = NULL;

        while (p != NULL && p->seatNo != s) {
            prev = p;
            p = p->next;
        }

        if (p != NULL) {
            if (prev == NULL)
                head = p->next;
            else
                prev->next = p->next;

            delete p;
            seats[s - 1] = 0;
            cout << "Ticket cancelled!\n";
        }
    }

    void trainStatus() {
        for (int i = 0; i < n; i++)
            cout << "Seat " << i + 1 << ": "
                 << (seats[i] ? "Booked" : "Available") << endl;
    }

    void passengerList() {
        Passenger* p = head;

        if (p == NULL)
            cout << "No passengers!\n";

        while (p != NULL) {
            cout << "Seat: " << p->seatNo
                 << " | Name: " << p->name
                 << " | Age: " << p->age
                 << " | Gender: " << p->gender << endl;
            p = p->next;
        }
    }

    ~Train() {
        while (head != NULL) {
            Passenger* p = head;
            head = head->next;
            delete p;
        }
        free(seats);
    }
};

int main() {
    Train t;
    int choice;

    do {
        cout << "\n1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. View Train Status\n";
        cout << "4. View Passenger List\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: t.bookTicket(); break;
            case 2: t.cancelTicket(); break;
            case 3: t.trainStatus(); break;
            case 4: t.passengerList(); break;
            case 5: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}