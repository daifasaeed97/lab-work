#include "list.h"
template <class Type>
class MyList : public List<Type> {
public:
    MyList(int max = 100, int size = 0)
        : List<Type>(max, size) {}

    MyList(const MyList<Type>& other) : List<Type>(other) {}

    bool empty() const {
        return this->currentSize == 0;
    }

    bool full() const {
        return this->currentSize == this->maxSize;
    }

    int size() const {
        return this->currentSize;
    }

    void addElementAtFirstIndex(Type value) override {
        if (full()) {
            cout << "List is full!\n";
            return;
        }

        for (int i = this->currentSize; i > 0; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[0] = value;
        this->currentSize++;
    }

    void addElementAtLastIndex(Type value) override {
        if (full()) {
            cout << "List is full!\n";
            return;
        }

        this->arr[this->currentSize] = value;
        this->currentSize++;
    }

    Type removeElementFromEnd() override {
        if (empty()) {
            cout << "List is empty!\n";
            return Type{};
        }

        Type value = this->arr[this->currentSize - 1];
        this->currentSize--;

        return value;
    }

    void removeElementFromStart() override {
        if (empty()) {
            cout << "List is empty!\n";
            return;
        }

        for (int i = 0; i < this->currentSize - 1; i++)
            this->arr[i] = this->arr[i + 1];

        this->currentSize--;
    }

    bool insertAt(int index, Type value) {
        if (full() || index < 0 || index > this->currentSize)
            return false;

        for (int i = this->currentSize; i > index; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[index] = value;
        this->currentSize++;

        return true;
    }

    Type last() const {
        if (empty()) {
            cout << "List is empty!\n";
            return Type{};
        }

        return this->arr[this->currentSize - 1];
    }

    bool search(Type value) const {
        for (int i = 0; i < this->currentSize; i++) {
            if (this->arr[i] == value)
                return true;
        }

        return false;
    }

    void display() const {
        if (empty()) {
            cout << "List is empty.\n";
            return;
        }

        cout << "List: ";
        for (int i = 0; i < this->currentSize; i++)
            cout << this->arr[i] << " ";

        cout << '\n';
    }
};