#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

int main() {

	// int x = 10;

	// cout << (&x) << endl; //8080

	// int* xptr = &x;
	// // cout << (*xptr) << endl;
	// // cout << xptr << endl;

	// // cout << (xptr + sizeof(int)) << endl;

	// // char ch = 'A';
	// // char* chptr = &ch;

	// // cout << (void*(chptr)) << endl;
	// // cout << (void*(chptr + 1)) << endl;


	// // cout << (&x) << endl;
	// // cout << xptr << endl;
	// // cout << "******************" << endl;

	// int** xxptr = &xptr;

	// cout << xxptr << endl;
	// // cout << (&xptr) << endl;

	// cout << (xxptr + 1) << endl;
	// cout << (*xxptr) << endl;

	// void * new_xptr = (void*)xptr;

	// cout<<sizeof(new_xptr)<<endl;

	// cout<<"Value of x after typecasting "<<(*new_xptr)<<endl;

	// cout<<xptr<<endl; //8080

	// cout<<(*xptr)<<endl; //10

	// cout<<(xptr + 1)<<endl; //8081

	// int x = 10;

	// int &z = x;

	// z++;

	// cout<<x<<endl;
	// cout<<(&z)<<endl;
	// cout<<(&x)<<endl;

	// cout<<(*xptr)<<endl; //10

	// float f = 10.6;
	// cout<<(&f)<<endl;

	// float* fptr = f;
	// cout<<fptr<<endl;

	// bool b = true;

	// cout<<(&b)<<endl;

	// float f = (float)10*10;
	// cout<<f<<endl;

	char c = 'A';

	cout << (&c) << endl;

	cout << ((void*)&c) << endl;

	char *cptr = &c;

	cout << cptr << endl;

	cout << sizeof(cptr) << endl;

	cptr = cptr + 1;

	// cout << (*((void*)cptr)) << endl;  // ERROR

	// cout << ((int)c) << endl;


	//TypeCasting

	// float avg = (1 + 2 + 3 + 4) / float(4);

	// cout << avg << endl;

	// char p = 'A';

	// p = p + 2;

	// cout << (p) << endl;

	return 0;
}