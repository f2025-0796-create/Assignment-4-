#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 10;

// Function prototypes
void initSeats(int seats[SIZE][SIZE]);
void showSeats(int seats[SIZE][SIZE]);
void bookSeat(int seats[SIZE][SIZE]);
void freeSeat(int seats[SIZE][SIZE]);
void analyzeRows(int seats[SIZE][SIZE]);
bool validPosition(int r, int c);

// Initialize seats
void initSeats(int seats[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            seats[r][c] = 0;
}

// Display seats
void showSeats(int seats[SIZE][SIZE]) {
    cout << "\n        ";
    for (int c = 1; c <= SIZE; c++)
        cout << setw(2) << c << " ";
    cout << "\n";

    for (int r = 0; r < SIZE; r++) {
        cout << "Row " << setw(2) << r + 1 << ": ";
        for (int c = 0; c < SIZE; c++)
            cout << setw(2) << seats[r][c] << " ";
        cout << "\n";
    }
}

// Reserve seat
void bookSeat(int seats[SIZE][SIZE]) {
    int r, c;
    cout << "Enter row and column to reserve: ";
    cin >> r >> c;

    while (!validPosition(r, c) || seats[r - 1][c - 1] == 1) {
        if (!validPosition(r, c))
            cout << "Invalid seat position!\n";
        else
            cout << "Seat already reserved!\n";

        cout << "Re-enter row and column: ";
        cin >> r >> c;
    }

    seats[r - 1][c - 1] = 1;
    cout << "Seat reserved successfully.\n";
}

// Cancel reservation
void freeSeat(int seats[SIZE][SIZE]) {
    int r, c;
    cout << "Enter row and column to cancel: ";
    cin >> r >> c;

    while (!validPosition(r, c) || seats[r - 1][c - 1] == 0) {
        if (!validPosition(r, c))
            cout << "Invalid seat position!\n";
        else
            cout << "Seat is already empty!\n";

        cout << "Re-enter row and column: ";
        cin >> r >> c;
    }

    seats[r - 1][c - 1] = 0;
    cout << "Reservation canceled.\n";
}

// Analyze rows
void analyzeRows(int seats[SIZE][SIZE]) {
    int emptyRows = 0, fullRows = 0, partialRows = 0;

    cout << "\nRow Analysis:\n";
    cout << setw(6) << "Row"
         << setw(10) << "Empty"
         << setw(10) << "Booked"
         << "Status\n";

    for (int r = 0; r < SIZE; r++) {
        int freeSeats = 0;

        for (int c = 0; c < SIZE; c++)
            if (seats[r][c] == 0)
                freeSeats++;

        if (freeSeats == SIZE) {
            emptyRows++;
            cout << setw(6) << r + 1 << setw(10) << freeSeats
                 << setw(10) << 0 << "Empty Row\n";
        }
        else if (freeSeats == 0) {
            fullRows++;
            cout << setw(6) << r + 1 << setw(10) << 0
                 << setw(10) << SIZE << "Fully Booked\n";
        }
        else {
            partialRows++;
            cout << setw(6) << r + 1 << setw(10) << freeSeats
                 << setw(10) << SIZE - freeSeats << "Partially Filled\n";
        }
    }

    cout << "\nSummary:\n";
    cout << "Empty Rows: " << emptyRows << endl;
    cout << "Fully Occupied Rows: " << fullRows << endl;
    cout << "Partially Occupied Rows: " << partialRows << endl;
}

// Validate position
bool validPosition(int r, int c) {
    return (r >= 1 && r <= SIZE && c >= 1 && c <= SIZE);
}

int main() {
    int seats[SIZE][SIZE];
    initSeats(seats);

    int choice;
    do {
        cout << "\n--- Bus Seat Reservation System ---\n";
        cout << "1. Display seats\n";
        cout << "2. Reserve seat\n";
        cout << "3. Cancel reservation\n";
        cout << "4. Row analysis\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: showSeats(seats); break;
            case 2: bookSeat(seats); break;
            case 3: freeSeat(seats); break;
            case 4: analyzeRows(seats); break;
            case 0: cout << "Program closed.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
