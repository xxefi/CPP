#include <iostream>
using namespace std;
template <typename T>
class Vector {
private:
    T* arr;             
    size_t capacity;   
    size_t vecSize;    

public:
   
    Vector() : arr(nullptr), capacity(capacity), vecSize(vecSize) {}


    ~Vector() {
        delete[] arr;
    }

   
    void push_back(const T& value) {
        if (vecSize == capacity) {

            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newArr = new T[newCapacity + 1];

            for (size_t i = 0; i < vecSize; ++i) {
                newArr[i] = arr[i];
            }
            capacity = newCapacity;
            delete[]arr;
            arr = newArr;
        }
        arr[vecSize++] = value;
    }

    
    void pop_back() {
        if (vecSize > 0) {
            --vecSize;
        }
    }

    
    size_t size() const {
        return vecSize;
    }

    
    bool empty() const {
        return vecSize == 0;
    }

    
    void clear() {
        vecSize = 0;
    }

    
    T* begin() const {
        return arr;
    }

    
    T* end() const {
        return arr + vecSize;
    }

    
    T& operator[](size_t index) {
        return arr[index];
    }

   
    void insert(size_t index, const T& value) {
        if (index > vecSize) {
            throw std::out_of_range("Index is out of range");
        }

        if (vecSize == capacity) {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newArr = new T[newCapacity];

            for (size_t i = 0; i < index; ++i) {
                newArr[i] = arr[i];
            }

            newArr[index] = value;

            for (size_t i = index; i < vecSize; ++i) {
                newArr[i + 1] = arr[i];
            }

            delete[] arr;

            arr = newArr;
            capacity = newCapacity;
            ++vecSize;
        }
        else {
            for (size_t i = vecSize; i > index; --i) {
                arr[i] = arr[i - 1];
            }
            arr[index] = value;
            ++vecSize;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    cout << "–азмер вектора: " << vec.size() << endl;

    cout << "Ёлементы вектора: ";
    for (int* it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    vec.pop_back();

    cout << "–азмер вектора после увеличени€: " << vec.size() << endl;

    vec.insert(1, 10);

    cout << "Ёлементы вектора после вставки: ";
    for (int* it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
