#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int main (void){
    printf ("Hello world\n");
    int jotinha = 15;
    cout << "Hello world" << endl << jotinha;

    int vec[5] = {5, 7, 2, 3, 4};

    sort(vec[0], vec[4]);

    for (int i = 0; i < 5; i++)
        cout << vec [i] << " ";

    return 0;
}