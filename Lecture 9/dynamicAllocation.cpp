#include <iostream>

using namespace std;

//void check(){
//    int a = 10;
//
//    a++;
//    cout<<a<<endl;
//}

void test(int* arr) {

}

int main() {
//    check();

    int *a = new int(10);

    int *b = new int(30);
    int n = 4;

    cout << a << endl;
    cout << *a << endl;

//    int arr[n];

//    test(arr);
//
//    arr[9];
//
//    cout<<arr<<endl;

    int *arr = new int[4];

    for (int i = 0; i < 4; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }

    delete a;
    delete b;

    delete [] arr;

    return 0;
}