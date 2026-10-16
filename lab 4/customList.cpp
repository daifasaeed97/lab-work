#include "MyList.h"
template <class Type>
class CustomList : public MyList<Type> {
public:
    CustomList(int max = 100, int size = 0)
        : MyList<Type>(max, size) {}

    CustomList(const CustomList<Type>& other)
        : MyList<Type>(other) {}

    ~CustomList() override = default;

    // Check whether a number is prime
    bool isPrime(Type n) const {
        if (n < 2)
            return false;

        for (Type i = 2; i <= n / i; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    // Sum of all prime numbers
    Type sum_ofPrime() const {
        Type sum = Type{};

        for (int i = 0; i < this->currentSize; i++) {
            if (isPrime(this->arr[i]))
                sum += this->arr[i];
        }

        return sum;
    }

    // Second maximum distinct even number
    Type secondMaxEven() const {
        Type max1{}, max2{};
        bool found1 = false, found2 = false;

        for (int i = 0; i < this->currentSize; i++) {
            Type value = this->arr[i];

            if (value % 2 != 0)
                continue;

            if (!found1 || value > max1) {
                if (found1 && value != max1) {
                    max2 = max1;
                    found2 = true;
                }

                max1 = value;
                found1 = true;
            }
            else if (value != max1 &&
                (!found2 || value > max2)) {
                max2 = value;
                found2 = true;
            }
        }

        if (!found2) {
            cout << "No second distinct even number exists.\n";
            return Type{};
        }

        return max2;
    }

    // Second minimum distinct odd number
    Type secondMinOdd() const {
        Type min1{}, min2{};
        bool found1 = false, found2 = false;

        for (int i = 0; i < this->currentSize; i++) {
            Type value = this->arr[i];

            if (value % 2 == 0)
                continue;

            if (!found1 || value < min1) {
                if (found1 && value != min1) {
                    min2 = min1;
                    found2 = true;
                }

                min1 = value;
                found1 = true;
            }
            else if (value != min1 &&
                (!found2 || value < min2)) {
                min2 = value;
                found2 = true;
            }
        }

        if (!found2) {
            cout << "No second distinct odd number exists.\n";
            return Type{};
        }

        return min2;
    }

    // Display duplicate values only once
    void printDuplicates() const {
        bool foundDuplicate = false;

        cout << "Duplicate values: ";

        for (int i = 0; i < this->currentSize; i++) {
            bool appearedBefore = false;

            for (int j = 0; j < i; j++) {
                if (this->arr[i] == this->arr[j]) {
                    appearedBefore = true;
                    break;
                }
            }

            if (appearedBefore)
                continue;

            int count = 0;

            for (int j = 0; j < this->currentSize; j++) {
                if (this->arr[i] == this->arr[j])
                    count++;
            }

            if (count > 1) {
                cout << this->arr[i] << " ";
                foundDuplicate = true;
            }
        }

        if (!foundDuplicate)
            cout << "None";

        cout << '\n';
    }

    // Rotate each half clockwise
    void rotateClockwaise(int r) {
        int n = this->currentSize;

        if (n == 0)
            return;

        int firstHalf = (n + 1) / 2;
        int secondHalf = n - firstHalf;

        rotateRight(0, firstHalf, r);
        rotateRight(firstHalf, secondHalf, r);
    }

    // Rotate each half anticlockwise
    void rotateanitclockwaise(int rt) {
        int n = this->currentSize;

        if (n == 0)
            return;

        int firstHalf = (n + 1) / 2;
        int secondHalf = n - firstHalf;

        rotateLeft(0, firstHalf, rt);
        rotateLeft(firstHalf, secondHalf, rt);
    }

private:
    void rotateRight(int start, int length, int r) {
        if (length <= 1)
            return;

        r = ((r % length) + length) % length;

        for (int k = 0; k < r; k++) {
            Type lastValue = this->arr[start + length - 1];

            for (int i = start + length - 1; i > start; i--)
                this->arr[i] = this->arr[i - 1];

            this->arr[start] = lastValue;
        }
    }

    void rotateLeft(int start, int length, int r) {
        if (length <= 1)
            return;

        r = ((r % length) + length) % length;

        for (int k = 0; k < r; k++) {
            Type firstValue = this->arr[start];

            for (int i = start; i < start + length - 1; i++)
                this->arr[i] = this->arr[i + 1];

            this->arr[start + length - 1] = firstValue;
        }
    }
};


// Main Menu
int main() {
    int capacity;

    cout << "Enter maximum capacity of list: ";
    cin >> capacity;

    if (capacity < 1) {
        cout << "Capacity must be positive.\n";
        return 0;
    }

    CustomList<int> list(capacity);

    int choice, value, index, rotations;

    do {
        cout << "\n===== CUSTOM LIST MENU =====\n";
        cout << "1. Add element at start\n";
        cout << "2. Add element at end\n";
        cout << "3. Remove element from start\n";
        cout << "4. Remove element from end\n";
        cout << "5. Insert element at index\n";
        cout << "6. Display list\n";
        cout << "7. Check if empty\n";
        cout << "8. Check if full\n";
        cout << "9. Get size\n";
        cout << "10. Get last element\n";
        cout << "11. Search element\n";
        cout << "12. Sum of prime numbers\n";
        cout << "13. Second maximum even number\n";
        cout << "14. Second minimum odd number\n";
        cout << "15. Print duplicates\n";
        cout << "16. Rotate clockwise\n";
        cout << "17. Rotate anticlockwise\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtFirstIndex(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtLastIndex(value);
            break;

        case 3:
            list.removeElementFromStart();
            break;

        case 4:
            if (!list.empty())
                cout << "Removed: "
                << list.removeElementFromEnd() << '\n';
            else
                cout << "List is empty!\n";
            break;

        case 5:
            cout << "Enter index (0-based): ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;

            if (list.insertAt(index, value))
                cout << "Element inserted successfully.\n";
            else
                cout << "Invalid index or list is full.\n";
            break;

        case 6:
            list.display();
            break;

        case 7:
            cout << (list.empty() ? "List is empty.\n"
                : "List is not empty.\n");
            break;

        case 8:
            cout << (list.full() ? "List is full.\n"
                : "List is not full.\n");
            break;

        case 9:
            cout << "Current size: " << list.size() << '\n';
            break;

        case 10:
            if (!list.empty())
                cout << "Last element: " << list.last() << '\n';
            else
                cout << "List is empty!\n";
            break;

        case 11:
            cout << "Enter value to search: ";
            cin >> value;

            cout << (list.search(value) ? "Value found.\n"
                : "Value not found.\n");
            break;

        case 12:
            cout << "Sum of prime numbers: "
                << list.sum_ofPrime() << '\n';
            break;

        case 13:
            cout << "Second maximum even number: "
                << list.secondMaxEven() << '\n';
            break;

        case 14:
            cout << "Second minimum odd number: "
                << list.secondMinOdd() << '\n';
            break;

        case 15:
            list.printDuplicates();
            break;

        case 16:
            cout << "Enter number of clockwise rotations: ";
            cin >> rotations;
            list.rotateClockwaise(rotations);
            cout << "List after rotation:\n";
            list.display();
            break;

        case 17:
            cout << "Enter number of anticlockwise rotations: ";
            cin >> rotations;
            list.rotateanitclockwaise(rotations);
            cout << "List after rotation:\n";
            list.display();
            break;

        case 0:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
