Operator Oveloading
- Operators are functions

    A+B       A.plus(B)
................................................
Without Operator Overloading


class MyInt{
private:
int d;
public :
MyInt() { }
MyInt(int p ) {d=p;}
MyInt plus(MyInt p) {
     int t;
     t=d+p.d;
     MyInt temp(t);
     return temp;
}
int getD() { return d;}
};

void main () {
MyInt a(10);
MyInt b(20);
MyInt c;
c=a.plus(b);            //c=a+b;
cout<<c.getD()<<endl;  ///cout<<c;
}
........................................
with operator Overloading
class MyInt{
private:
int d;
public :
MyInt() { }
MyInt(int p ) {d=p;}
MyInt operator +(MyInt p) {
     int t;
     t=d+p.d;
     MyInt temp(t);
     return temp;
}
int getD() { return d;}

};
void  operator<<(ostream &p,MyInt i){
      p<<i.getD();
}
void main () {
MyInt a=10;
MyInt b=20;
MyInt c;
c=a+b;   //c=a.plus(b)
cout<<c; //cout<<c.getD()<<endl;
}
............................................
Criticism on Operator Overloading

- Operators comes form Mathematics
- Always use operators for conventional purpose
What is conventional purpose?
e.g  +
  2+3
  3.4+3.5
  "Uc" + "P"
  matrix1 + matrix2

  car1+ car2  // unconventional

  student1+ student2  // unconventional

.................................................
Problem : Unary Op ++postfix  ++prfix
           
        int a=10;
       cou<<++a; //11
 int a=10;
 cout<<a++; //10
 cout<<a; //1


class MyInt{
private:
int d;
public :
MyInt() { }
MyInt(int p ) {d=p;}
MyInt operator +(MyInt p) {
     int t;
     t=d+p.d;
     MyInt temp(t);
     return temp;
}
//MyInt  plusplus(){
  MyInt  operator ++(){ //prefix ++
      d=d+1;
      return *this;//MyInt temp(d); return temp;
}
MyInt  operator ++(int p){ //postfix ++
        MyInt temp(d);
        d=d+1;
      return temp;
}
int getD() { return d;}

};
void  operator<<(ostream &p,MyInt i){
      p<<i.getD();
}
void main () {
MyInt a=10;
MyInt b=20;
cout<<++b;            //b.plusplus();  prefix
cout<<b++;            // prefix
cout<<b;
MyInt c;
c=a+b;   //c=a.plus(b)
cout<<c; //cout<<c.getD()<<endl;
}
............................................
