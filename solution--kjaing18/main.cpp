//Katelyn Jaing
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void part1();
void part2();
template < class T >
void multiply(T, T);
template < class T >
void swap(T, T);
void part3();
void part4();
int gcd( int, int );
int fib( int );
int power( int, int );
int triangle( int );
void part5();
int iter_gcd( int, int );
int iter_fib( int );
int iter_power( int, int );
int iter_triangle( int );

int main() {
    //part 1
    /*Find the root number.
     If the number under the root is a negative, throw an exception.*/
    //part1();
    
    //part 2
    /*Enter two numbers (integer or double).
     Then chooose whether to multiply or swap the numbers.*/
    //part2();
    
    //part 3
    /*Ask for how many students there are (size of vector).
     Then ask for names of each student and input into vector1
     Then ask for scores of each student and input into vector2.*/
    //part3();
    
    //part 4
    /* Find the GCD, find the Fibonacci number, draw a triangle*/
    //part4();
    
    //part 5
    /* part4() as iterative functions */
    part5();
    
    return 0;
}

//part 1
void part1()
{
    double number;
    cout << "Enter a number: ";
    cin >> number;
    
    try
    {
        if (number < 0)
            throw 0;
        else
            cout << "The square root of " << number << " is: " << sqrt(number) << endl;
    }
    catch (int n)
    {
        cout << "ERROR: number is a negative" << endl;
    }
}

//part
void part2()
{
    double num1, num2;
    cout << "Enter two numbers (integer or double): ";
    cin >> num1 >> num2;
    
    int ans;
    cout << "Choose one: " <<endl;
    cout << "1. Multiply " <<endl;
    cout << "2. Swap " <<endl;
    cin >> ans;
    
    if( ans == 1 )
        multiply( num1, num2 );
    else if( ans == 2 )
        swap( num1, num2 );
}

template < class T >
void multiply( T one, T two)
{
    cout << one << " * " << two << " = " << one * two <<endl;
}

template < class T >
void swap( T one, T two )
{
    T temp = one;
    one = two;
    two = temp;
    cout << one << " " << two << endl;
}

//part3
void part3()
{
    vector<string> students;
    vector<int> scores;
    
    int numOfStudents;
    cout << "How many students are there in the class? ";
    cin >> numOfStudents;
    
    //input student name
    string tempName;
    for( int i = 0; i < numOfStudents; i++ )
    {
        cout << "What is the name of student " << i + 1 << "? ";
        cin >> tempName;
        students.push_back(tempName);
    }
    
    //input student score
    double tempScore;
    for( int i = 0; i < numOfStudents; i++ )
    {
        cout << "what is the score of student " << i + 1 << "? ";
        cin >> tempScore;
        scores.push_back(tempScore);
    }
    
    //print out the students and scores
    cout << "Here is your class: " << endl;
    for( int i = 0; i < numOfStudents; i++ )
    {
        cout << "Name: " << students[i] << " Score: " << scores[i] << endl;
    }
}

//part4
void part4()
{
    //Euclid's algorithm
    int a, b;
    cout << "Enter two numbers to find the GCD: ";
    cin >> a >> b;
    cout << "The GCD of " << a << " and " << b << " is: " << gcd( a, b ) << endl;
    cout << "/*****************/" << endl;
    
    //Fibonacci Number
    int n;
    cout << "Enter a number to find the Fibonacci number: ";
    cin >> n;
    cout << "The Fibonnacci Sequence is: ";
    for( int i = 1; i <= n; i++ )
    {
        cout << fib( i ) << " ";
    }
    cout << endl;
    cout << "/*****************/" << endl;
    
    //Power
    int base, pow;
    cout << "Enter the base number then the power number: ";
    cin >> base >> pow;
    cout << base << "^" << pow << " = " << power( base, pow ) << endl;
    cout << "/*****************/" << endl;
    
    //Triangle
    int t;
    cout << "Enter a number to form its triangle: ";
    cin >> t;
    cout << triangle( t ) << " stars" << endl;
    
    for( int i = 1; i <= t; i++ )
    {
        for( int k = 0; k < i; k++ )
        {
            cout << "*";
        }
        cout << endl;
    }
    
    
}

int gcd(int a, int b)
{
    if( a < b )
    {
        int temp = b;
        b = a;
        a = temp;
    }
    
    //a = b * t + r
    // t = a / b (integer, no double = no decimal)
    //r = a - b * t
    
    //base case
    int t = a / b;
    int r = a - b * t;
    
    if( a == 0 )
    {
        return std::abs(b);
    }
    else if( b == 0 )
    {
        return std::abs(a);
    }
    else if( r == 0 )
    {
        return b;
    }
    else    //recursion
        return gcd( b, r );
}

int fib( int n )
{
    if (n < 1)
        throw " invalid n";
    
    // base case
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    
    //recursive case
    return fib(n - 2) + fib(n - 1);
}

int power( int a, int b )
{
    if (b < 0)
        throw "negative exponent";
    
    //base case
    if (b == 0)
        return 1;
    
    //recusrion case
    return a * pow(a, b-1);
}

int triangle( int t )
{
    if( t < 0 )
        throw "Invalid number";
    
    //base case
    if( t == 0 )
        return 0;
    
    //recursion
    int total = t + triangle( t - 1 );
    return total;
}

//part5
void part5()
{
    //Euclid's algorithm
    int a, b;
    cout << "Enter two numbers to find the GCD: ";
    cin >> a >> b;
    cout << "The GCD of " << a << " and " << b << " is: " << iter_gcd( a, b ) << endl;
    cout << "/*****************/" << endl;
    
    //Fibonacci Number
    int n;
    cout << "Enter a number to find the Fibonacci number: ";
    cin >> n;
    cout << "The Fibonnacci Sequence is: ";
    for( int i = 1; i <= n; i++ )
    {
        cout << iter_fib( i ) << " ";
    }
    cout << endl;
    cout << "/*****************/" << endl;
    
    //Power
    int base, pow;
    cout << "Enter the base number then the power number: ";
    cin >> base >> pow;
    cout << base << "^" << pow << " = " << iter_power( base, pow ) << endl;
    cout << "/*****************/" << endl;
    
    //Triangle
    int t;
    cout << "Enter a number to form its triangle: ";
    cin >> t;
    cout << iter_triangle( t ) << " stars" << endl;
    
    for( int i = 1; i <= t; i++ )
    {
        for( int k = 0; k < i; k++ )
        {
            cout << "*";
        }
        cout << endl;
    }
    
}

int iter_gcd( int a, int b )
{
    if( a < b )
    {
        int temp = b;
        b = a;
        a = temp;
    }
    
    //a = b * t + r
    // t = a / b (integer, no double = no decimal)
    //r = a - b * t
    
    int t, r;
    
    if( a == 0 )
    {
        return std::abs(b);
    }
    else if( b == 0 )
    {
        return std::abs(a);
    }
    
    while( r != 0 )
    {
        t = a / b;
        r = a - b * t;
        if( r == 0 )
            return b;
        else
        {
            a = b;
            b = r;
        }
    }
    return 0;
}

int iter_fib( int n )
{
    if (n < 1)
        throw " invalid n";
    
    // base case
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;

    int nMinus1 = 1, nMinus2 = 1, num = 1;
    for( int i = 3; i <= n; i++ )
    {
        num = nMinus1 + nMinus2;
        nMinus2 = nMinus1;
        nMinus1 = num;
    }
    return num;
}

int iter_power( int a, int b )
{
    if (b < 0)
        throw "negative exponent";
    
    if (b == 0)
        return 1;
    
    int temp = a;
    while( b > 1 )
    {
        temp = temp * a;
        b--;
    }
    return temp;
}

int iter_triangle( int t )
{
    if( t < 0 )
        throw "Invalid number";
    
    //base case
    if( t == 0 )
        return 0;
    
    //recursion
    int total = 0;
    
    while( t > 0 )
    {
        total += t;
        t--;
    }
    return total;
}
