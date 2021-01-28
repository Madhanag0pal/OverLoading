#include <iostream>
#include <math.h>

using namespace std;

class Complex{
  int real,imag;
public:
  Complex(int r=0,int i=0){
    real = r;
    imag = i;
  }
  // Complexobj + int
  Complex operator + (int i){
    Complex res(real + i,imag + i);
    return res;
  }
  Complex operator ++ (){
    ++real;
    ++imag;
    return *this;
  }
  Complex operator ++ (int a){
    Complex res(real++,imag++);
    return res;
  }
  Complex operator += (int n){
    Complex res(real+n,imag+n);
    return res;
  }
  Complex operator ^ (int n);
  
  friend Complex operator + (int ,Complex& );
  friend Complex operator ^ (int i,Complex &com);
  friend ostream& operator << (ostream& print, Complex c);
  friend istream& operator >> (istream& input, Complex &c){
    cin >> c.real;
    cout << "+i";
    input >>  c.imag;
    return input;
  }
};

Complex Complex::operator ^ (int n){
  Complex res(pow(real,n),pow(imag,n));
  return res;
}

Complex operator + (int i,Complex &com){
  Complex res(i+com.real,i+com.imag);
  return res;
}

Complex operator ^ (int i,Complex &com){
  Complex res(pow(i,com.real),pow(i,com.imag));
  return res;
}

ostream& operator << (ostream &print, Complex c){
  print << c.real << "  + i" << c.imag;
  return print;
}

int main() {
  Complex c1,c2;
  cin >> c1;
  c2 = ++c1;
  cout << c1 << "," << c2 << endl;
  c2 = c1++;
  cout << c1 << "," << c2 << endl;
}