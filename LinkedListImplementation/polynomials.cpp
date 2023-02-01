#include <iostream>
#include<cmath>
using namespace std;

template <class T>
struct node {
    T coefficient;
    int exponent;
    node *next;
};
template <class T>
class polynomials {
    node<T> *start;

public:
    polynomials() {
        start = NULL;
    }
    node<T> *returnStart() {
        return start;
    }
    void insertElement(T value, int power) {
        node<T> *ptr = new node<T>;
        ptr->coefficient = value;
        ptr->exponent = power;
        if (start == NULL || power > start->exponent) {
            ptr->next = start;
            start = ptr;
        }else {
            node<T> *temp = start;
            while (temp->next != NULL && temp->next->exponent > power)
                temp = temp->next;
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }

    void displayElement() {
        node<T> *temp = start;
        char sign;
        while (temp) {
            sign = (temp->coefficient) < 0 ? '-' : '+';
            if (temp != start)
                cout << ' ' << sign << ' ' << abs(temp->coefficient);
            else
                cout << temp->coefficient;
            cout << "x^" << temp->exponent;
            temp = temp->next;
        }
    }
};
template <class T>
polynomials<T> addPolynomials(polynomials<T> &firstPolynomial, polynomials<T> &secondPolynomial) {
    polynomials<T> sum;
    node<T> *a = firstPolynomial.returnStart(), *b = secondPolynomial.returnStart();
    while (a && b) {
        if (a->exponent == b->exponent) {
            sum.insertElement(a->coefficient + b->coefficient, a->exponent);
            a = a->next;
            b = b->next;
        }
        else if (a->exponent > b->exponent) {
            sum.insertElement(a->coefficient, a->exponent);
            a = a->next;
        }
        else {
            sum.insertElement(b->coefficient, b->exponent);
            b = b->next;
        }
    }
    while (a) {
        sum.insertElement(a->coefficient, a->exponent);
        a = a->next;
    }
    while (b) {
        sum.insertElement(b->coefficient, b->exponent);
        b = b->next;
    }
    return sum;
}
int main() {
    polynomials<int> firstPolynomial, secondPolynomial, result;
    firstPolynomial.insertElement(-3, 1);
    firstPolynomial.insertElement(6, 0);
    firstPolynomial.insertElement(-3, 4);
    firstPolynomial.insertElement(3, 2);
    secondPolynomial.insertElement(-2, 4);
    secondPolynomial.insertElement(4, 3);
    secondPolynomial.insertElement(-2, 0);
    cout << "First Polynomial:  ";
    firstPolynomial.displayElement();
    cout<<endl;
    cout << "Second Polynomial "<<endl;
    secondPolynomial.displayElement();
    result = addPolynomials(firstPolynomial, secondPolynomial);
    result.displayElement();
}
