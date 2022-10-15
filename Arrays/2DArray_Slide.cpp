#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    // 2D Array
    cout << "\n2D Array\n";
    int minu[3][5];
    int H=3;
    int W=5;
    int n, m;
    int i=0;

    for(n=0; n<H; n++){                         //rows
        for(m=0; m<W; m++){                     //columns
            minu[n][m] = i++;                   //assigning the value of i each time
            cout << minu[n][m] << " ";          //printng the array
        }
        cout << "\n";
    }


    // 1D Array
    cout << "\n1D Array\n";
    int arr[3*5];
    int A=3;
    int B=5;
    int p, q;
    int j=0;

    for(p=0; p<A; p++){
        for(q=0; q<B; q++){
            arr[B*p+q] = i++;
            cout << arr[p][q] << " ";
        }
        cout << "\n";
    }


    getch();

}