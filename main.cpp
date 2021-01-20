#include <iostream>
#include <math.h>

using namespace std;

ostream &outp = cout;
istream &inp = cin;

class Complex{
  int real,imag;
public:
  Complex(int r=0,int i=0){
    real = r;
    imag = i;
  }
  // Complexobj + [other dt]
  Complex operator + (int i){
    Complex res;
    res.real = i + this->real;
    res.imag = i + imag;
    return res;
  }
  Complex operator ++ (){
    Complex res;
    res.real = ++real;
    res.imag = ++imag;
    return res;
  }
  Complex operator ++ (int a){
    Complex res;
    res.real = ++real;
    res.imag = ++imag;
    return res;
  }
  Complex operator += (int n){
    Complex &res = *this;
    res.real += n;
    res.imag += n;
    return res;
  }

  Complex operator ^ (int n);
  friend Complex operator + (int ,Complex& );
  friend Complex operator ^ (int i,Complex &com);
  friend ostream& operator << (ostream& print, Complex c);
  friend istream& operator >> (istream& input, Complex &c){
    cout << "Enter Real number: ";
    cin >> c.real;
    cout << "Enter Imaginary number: ";
    input >>  c.imag;
    return input;
  }
};

Complex Complex::operator ^ (int n){
  Complex res;
  res.real = pow(real,n);
  res.imag = pow(imag,n);
  return res;
}

Complex operator + (int i,Complex &com){
  Complex res;
  res.real = i + com.real;
  res.imag = i + com.imag;
  return res;
}

Complex operator ^ (int i,Complex &com){
  Complex res;
  res.real = pow(i,com.real);
  res.imag = pow(i,com.imag);
  return res;
}

ostream& operator << (ostream &print, Complex c){
  print << c.real << "  + i";
  cout << c.imag;
  return print;
}

int main() {
  Complex c1,c2;
  inp >> c1;
  c1 = c1 + 1;
  cout << c1 <<endl << &cout << endl;
  c1 = 1 + c1;
  outp << c1 << "," << c2;
}