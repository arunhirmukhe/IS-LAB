
#include <iostream>
#include <math.h>
#include<set>
using namespace std;
int find_q(int p){
    for(int i=1;i<p;i++){
        set<int>s;
        for(int j=1;j<p;j++){
            int number = pow(i,j);
            s.insert(number%p);
        }
        if(s.size()==p-1){
            return i;
        }
        cout<<endl;
    }
    return 0;
}
int main()
{
    int p, X1, X2;
    cout<<"Enter the Prime Number : ";
    cin >> p;
    int q = find_q(p);
    cout<<"The Alpha Generated : "<<q<<endl;
    cout<<"Enter the Persnal Key of First Person :: ";
    cin >> X1;
    cout<<"Enter the Persnal Key of Second Person :: ";
    cin >> X2;
    int num = pow(q, X1);
    int Y1 = num % p;
    cout <<"Enter the Encrypted Key for First : "<< Y1 << endl;
    num = pow(q, X2);
    int Y2 = num % p;
    cout <<"Enter the Encrypted Key for second : "<< Y2 << endl;
    num = pow(Y2, X1);
    int key1 = num % p;
    num = pow(Y1, X2);
    int key2 = num % p;
    if (key1 == key2)
    {
        cout << "Same key : " << Y1 << endl;
    }
}