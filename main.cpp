#include <iostream>
#include <vector>

using namespace std;

struct Term {
    double coefficient;
    int exponent;
};

double evaluatePolynomial(const vector<Term>& polynomial, double x) {
    double result = 0.0;
    for (const auto& term : polynomial) {
        result += term.coefficient * pow(x, term.exponent);
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Term> polynomial;
    int numTerms;

    cout << "Введите количество членов полинома: ";
    cin >> numTerms;

    for (int i = 0; i < numTerms; ++i) {
        Term term;
        cout << "Введите коэффициент и степень для члена " << i + 1 << " через пробел: ";
        cin >> term.coefficient >> term.exponent;
        while (term.coefficient == 0) {
            cout << "Коэффициент не должен быть равен 0, введите коэффициент заново: ";
            cin >> term.coefficient;
        }
        polynomial.push_back(term);
    }

    cout << "Полином: ";
    for (int i = 0; i < polynomial.size(); ++i) {
        if (polynomial[i].coefficient >= 0 && i != 0) {
            cout << " + ";
        }
        else if (polynomial[i].coefficient < 0 and i != 0) {
            cout << " - ";
        }
        else if (i == 0 and polynomial[i].coefficient < 0) {
            cout << '-';
        }
        if (polynomial[i].coefficient != 1 and polynomial[i].coefficient != -1) {
            if (polynomial[i].exponent != 0 and polynomial[i].exponent != 1) {
                cout << abs(polynomial[i].coefficient) << "x^" << polynomial[i].exponent;
            }
            else if (polynomial[i].exponent == 0) {
                cout << abs(polynomial[i].coefficient);
            }
            else if (polynomial[i].exponent == 1) {
                cout << abs(polynomial[i].coefficient) << 'x';
            }
        }
        else if (polynomial[i].coefficient == 1 or polynomial[i].coefficient == -1) {
            if (polynomial[i].exponent != 0 and polynomial[i].exponent != 1) {
                cout << "x^" << polynomial[i].exponent;
            }
            else if (polynomial[i].exponent == 0) {
                cout << abs(polynomial[i].coefficient);
            }
            else if (polynomial[i].exponent == 1) {
                cout << 'x';
            }
        }
    }
    cout << endl;

    double x;
    cout << "Введите значение x: ";
    cin >> x;

    double result = evaluatePolynomial(polynomial, x);
    cout << "Значение полинома при x = " << x << " равно: " << result << endl;

    return 0;
}
