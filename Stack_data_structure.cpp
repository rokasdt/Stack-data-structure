#include <iostream>

const int MAX_SIZE = 5; 

class Stack {
private:
    int elements[MAX_SIZE]; 
    int top; 

public:
    Stack() {
        // pradinis skacius kol stekas tuscias
        top = -1;
    }

    void push(int value) {
        // patikrinimas ar stekas tuscias
        if (isFull()) {
            std::cout << "Error: Stack is full" << std::endl;
            return;
        }

        // prideda elementa steko virsuje ir pakelia virsutini indeksa
        elements[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Error: Stack is empty" << std::endl;
            return;
        }

        // sumazina virsutini indeksa ir pasalina elementa is steko
        top--;
    }

    int Top() {
        if (isEmpty()) {
            std::cout << "Error: Stack is empty" << std::endl;
            return -1; 
        }

        // grazina virsutini elementa
        return elements[top];
    }

    bool isEmpty() {
        // patikrina ar virsutinis indekas = -1
        return top == -1;
    }

    bool isFull() {
        // patikrina ar virsutinis indekas yra maksimalus steko dydis
        return top == MAX_SIZE - 1;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Error: Stack is empty" << std::endl;
            return;
        }

        std::cout << "Stack: ";

        // printina visus elementus nuo apacios i virsu
        for (int i = 0; i <= top; i++) {
            std::cout << elements[i] << " ";
        }

        std::cout << std::endl;
    }

    void reverse() {
        if (isEmpty()) {
            std::cout << "Error: Stack is empty" << std::endl;
            return;
        }

        // apsukima keiciant elementus vietomis
        // apkeicia virsu, apacia ir tada juda i vidury
        int start = 0;
        int end = top;

        while (start < end) {
            int temp = elements[start];
            elements[start] = elements[end];
            elements[end] = temp;

            start++;
            end--;
        }
    }


    void clear() {
        // resetina virsutini indeksa i -1 ir taip isvalo steka
        top = -1;
    }
};

int main() {
    Stack s; 


    return 0;
}
