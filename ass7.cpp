#include <iostream>
#include <stack>
using namespace std;

void reverseString(string str)
{
    stack<char> s;

    for (char ch : str)
        s.push(ch);

    cout << "Original String: " << str << endl;
    cout << "Reversed String: ";

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    cout << endl;
}

void palindrome(string str)
{
    stack<char> s;

    for (char ch : str)
        s.push(ch);

    string rev = "";

    while (!s.empty())
    {
        rev += s.top();
        s.pop();
    }

    if (str == rev)
        cout << "String is Palindrome";
    else
        cout << "String is Not Palindrome";
}

int main()
{
    string str;

    cout << "Enter string: ";
    cin >> str;

    reverseString(str);
    palindrome(str);

    return 0;
}
