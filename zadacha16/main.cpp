#include <iostream>
#include <complex>
using namespace std;

struct Compl
{
    double a, b;
    double k, p;
};

class Complex
{
private:
    Compl comp1;
    Compl comp2;

    double real_a, image_b;
    double real_c, image_d;
public:

    Complex(double x = 0,double y = 0, double z = 0, double w = 0)
        {
            comp1.a = x;
            comp1.b = y;
            comp2.k = z;
            comp2.p = w;
        }

    Complex operator +(const Complex &c){
        Complex d;
        d.comp1.a = comp1.a + c.comp1.a;
        d.comp1.b = comp1.b + c.comp1.b;
        return d;
    }

    Complex operator -(const Complex &c){
        Complex y;
        y.comp1.a=comp1.a-c.comp1.a;
        y.comp1.b=comp1.b-c.comp1.b;
        return y;
    }

    Complex operator *(const Complex &c){
        Complex t;
        t.comp1.a = comp1.a * c.comp1.a - comp1.b * c.comp1.b;
        t.comp1.b = comp1.a * c.comp1.b + comp1.b * c.comp1.a;
        return t;
    }

    Complex operator /(const Complex &c){
        Complex t;
        t.comp1.a = (comp1.a * c.comp1.a + comp1.b * c.comp1.b) / (comp1.a * comp1.a + comp1.b * comp1.b);
        t.comp1.b = (comp1.b * c.comp1.a - comp1.a * c.comp1.b) / (comp1.a * comp1.a + comp1.b * comp1.b);
        return t;
    }

    void getComp(){
            if(comp1.b >= 0)
                cout << comp1.a << "+" << comp1.b << "i\n";
            else
                cout << comp1.a << comp1.b << "i\n";
    }

    Complex setValues(){
        double x, y;
        cout << "Действительная часть: ";
        cin >> x;
        cout << "Мнимая часть: ";
        cin >> y;
        Complex A = Complex (x,y);
        return A;
    }

    void getValues()
        {
            cout << real_a << "+j" << image_b << endl;
        }

    void Sum(Complex x)
        {
             real_a = real_a + x.real_a;
             image_b = image_b + x.image_b;
        }

//    double getSum(double r_a, double i_b, double r_c, double i_d)
//    {
//        real_a = r_a;
//        image_b = i_b;
//        real_c = r_c;
//        image_d = i_d;
//        double compl_sum;
//        compl_sum = (r_a, i_b) + (r_c, i_d);
//        cout << "Complex sum: " << compl_sum << endl;
//        return compl_sum;
//    }
};

int chois(){
    int chois_1;
    cout << " Операции над комплексными числами\n";
    cout << "1 - Сложение\n";
    cout << "2 - Вычитание\n";
    cout << "3 - Умножение\n";
    cout << "4 - Деление\n";
    cout << "\n Выберите действие : \n";
    cin >> chois_1;
    return chois_1;
}

void choise(){
    switch (chois()){
    case 1: {
        Complex a, b;
        cout<<"Первое число:\n";
        a = a.setValues();
        cout<<"Второе число:\n";
        b = b.setValues();
        Complex c = a + b;
        c.getComp();
        break;
            }
    case 2:{
        Complex a, b;
        cout<<"Первое число:\n";
        a = a.setValues();
        cout<<"Второе число:\n";
        b = b.setValues();
        Complex c = a - b;
        c.getComp();
        break;
        }
    case 3:{
        Complex a, b;
        cout<<"Первое число:\n";
        a = a.setValues();
        cout<<"Второе число:\n";
        b = b.setValues();
        Complex c = a * b;
        c.getComp();
        break;
            }
    case 4:{
        Complex a, b;
        cout<<"Первое число:\n";
        a = a.setValues();
        cout<<"Второе число:\n";
        b = b.setValues();
        Complex c = a / b;
        c.getComp();
        break;
           }
default :exit(0);
    }
}

int main()
{
     choise();
    return 0;
}
