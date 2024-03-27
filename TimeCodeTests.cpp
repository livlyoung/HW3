//Liv Young HW 3 part 1
//TimeCodeTests.cpp

#include <iostream>
#include <assert.h>
#include <stdexcept>

using namespace std;

#include "TimeCode.h"


void TestComponentsToSeconds(){

	cout << "Testing ComponentsToSeconds" << endl;
	
	long long unsigned int t = TimeCode::ComponentsToSeconds(3, 17, 42);
	cout<<t<<endl;
	assert(t == 11862);
	
	long long unsigned int t2 = TimeCode::ComponentsToSeconds(12, 71, 123904846);
	cout<<t2<<endl;
	assert(t2 == 123952306);

	long long unsigned int t3 = TimeCode::ComponentsToSeconds(0, 0, 0);
	cout<<t3<<endl;
	assert(t3 == 0);
	
	cout << "PASSED!" << endl << endl;
}


void TestDefaultConstructor(){

	cout << "Testing Default Constructor" << endl;
	TimeCode tc;
	
	cout << "tc: " << tc.ToString() << endl;
	assert(tc.ToString() == "0:0:0");
	
	cout << "PASSED!" << endl << endl;
}


void TestComponentConstructor(){
	cout << "Testing Component Constructor" << endl;
	TimeCode tc = TimeCode(0, 0, 0);
	cout << "tc: " << tc.ToString() << endl;
	assert(tc.ToString() == "0:0:0");

	// Roll-over inputs
	TimeCode tc2 = TimeCode(0, 61, 61);
	cout << "tc2: " << tc2.ToString() << endl;
	assert(tc2.ToString() == "1:2:1");

	TimeCode tc3 = TimeCode(0, 0, 86400);
	cout << "tc3: " << tc3.ToString() << endl;
	assert(tc3.ToString() == "24:0:0");
	
	
	TimeCode tc4 = TimeCode(3, 71, 3801);
	cout << "tc4: " << tc4.ToString() << endl;
	assert(tc4.ToString() == "5:14:21");

	
	cout << "PASSED!" << endl << endl;
}


void TestGetComponents(){
	cout << "Testing GetComponents" << endl;
	
	unsigned int h;
	unsigned int m;
	unsigned int s;
	
	// Regular values
	TimeCode tc = TimeCode(5, 2, 18);
	tc.GetComponents(h, m, s);
	cout<<tc.ToString()<<endl;
	assert(h == 5 && m == 2 && s == 18);
	
	// More tests go here!

	TimeCode tc2 = TimeCode(5, -2, 18);
	tc2.GetComponents(h, m, s);
	cout<<tc2.ToString()<<endl;
	assert(h == 4 && m == 58 && s == 18);

	TimeCode tc3 = TimeCode(0, 0, 86400);
	tc3.GetComponents(h, m, s);
	cout<<tc3.ToString()<<endl;
	assert(h == 24 && m == 0 && s == 0);

	TimeCode tc4 = TimeCode(0, 125, 5);
	tc4.GetComponents(h, m, s);
	cout<<tc4.ToString()<<endl;
	assert(h == 2 && m == 5 && s == 5);
	
	cout << "PASSED!" << endl << endl;
}


void TestSubtract(){
	cout << "Testing Subtract" << endl;
	TimeCode tc1 = TimeCode(1, 0, 0);
	TimeCode tc2 = TimeCode(0, 50, 0);
	TimeCode tc3 = tc1 - tc2;
	cout<<tc3.ToString()<<endl;
	assert(tc3.ToString() == "0:10:0");
	
	TimeCode tc4 = TimeCode(3, 59, 8);
	TimeCode tc5 = TimeCode(1, 30, 9);
	TimeCode tc6 = tc4 - tc5;
	cout<< tc6.ToString() <<endl;
	assert(tc6.ToString() == "2:28:59");

	TimeCode tc7 = TimeCode(3, 50, 8);
	TimeCode tc8 = TimeCode(0, 0, 0);
	TimeCode tc9 = tc7 - tc8;
	cout<< tc9.ToString() <<endl;
	assert(tc9.ToString() == "3:50:8");


	// TimeCode tc10 = TimeCode(1, 50, 8);
	// TimeCode tc11 = TimeCode(2, 0, 0);
	// TimeCode tc12 = tc10 - tc11;
	// cout<< tc12.ToString() <<endl;
	// assert(false);

	
	// TimeCode tc7 = TimeCode(1, 15, 45);
	// try{
	// 	TimeCode tc8 = tc1 - tc7;
	// 	cout << "tc8: " << tc8.ToString() << endl;
	// 	//assert(false);
	// }
	// catch(const invalid_argument& e){
	// 	// just leave this empty
	// 	// and keep doing more tests
	// }

	// // more tests
	
	cout << "PASSED!" << endl << endl;
}

void TestAdd(){

	cout << "Testing Add" << endl;
	TimeCode tc1 = TimeCode(1, 0, 0);
	TimeCode tc2 = TimeCode(0, 50, 0);
	TimeCode tc3 = tc1 + tc2;
	cout<<tc3.ToString()<<endl;
	assert(tc3.ToString() == "1:50:0");
	
	TimeCode tc4 = TimeCode(3, 59, 8);
	TimeCode tc5 = TimeCode(1, 30, 9);
	TimeCode tc6 = tc4 + tc5;
	cout<< tc6.ToString() <<endl;
	assert(tc6.ToString() == "5:29:17");

	TimeCode tc7 = TimeCode(3, 50, 8);
	TimeCode tc8 = TimeCode(0, 0, 0);
	TimeCode tc9 = tc7 + tc8;
	cout<< tc9.ToString() <<endl;
	assert(tc9.ToString() == "3:50:8");
	
	cout << "PASSED!" << endl << endl;
}

void TestMultiply(){

	cout << "Testing Multiply" << endl;
	TimeCode tc1 = TimeCode(1, 0, 0);
	
	TimeCode tc2 = tc1 * 3.5;
	cout<<tc2.ToString()<<endl;
	assert(tc2.ToString() == "3:30:0");
	
	TimeCode tc4 = TimeCode(3, 59, 8);

	TimeCode tc6 = tc4 * 0;
	cout<< tc6.ToString() <<endl;
	assert(tc6.ToString() == "0:0:0");


	TimeCode tc7 = TimeCode(3, 50, 8);
	TimeCode tc9 = tc7 * 100;
	cout<< tc9.ToString() <<endl;
	assert(tc9.ToString() == "383:33:20");
	
	cout << "PASSED!" << endl << endl;
}


void TestDivide(){

	cout << "Testing Divide" << endl;
	TimeCode tc1 = TimeCode(1, 0, 0);
	TimeCode tc2 = tc1 / 3.5;
	cout<<tc2.ToString()<<endl;
	assert(tc2.ToString() == "0:17:8");
	
	// TimeCode tc4 = TimeCode(3, 59, 8);
	// TimeCode tc6 = tc4 / 0;
	// cout<< tc6.ToString() <<endl;
	// assert(false);

	TimeCode tc7 = TimeCode(3, 50, 8);
	TimeCode tc9 = tc7 / 100;
	cout<< tc9.ToString() <<endl;
	assert(tc9.ToString() == "0:2:18");
	
	cout << "PASSED!" << endl << endl;
}


void TestSetMinutes()
{
	cout << "Testing SetMinutes" << endl;

	TimeCode tc = TimeCode(8, 20, 9);
	tc.SetMinutes(10); // test valid change
	cout<<tc.ToString()<<endl;
	assert(tc.ToString() == "8:10:9");

	TimeCode tc1 = TimeCode(8, 20, 9);
	tc1.SetMinutes(3); // test valid change
	cout<<tc1.ToString()<<endl;
	assert(tc1.ToString() == "8:3:9");

	TimeCode tc2 = TimeCode(8, 20, 9);
	tc2.SetMinutes(0); // test valid change
	cout<<tc2.ToString()<<endl;
	assert(tc2.ToString() == "8:0:9");

	TimeCode tc3 = TimeCode(8, 20, 9);
	tc3.SetMinutes(35); // test valid change
	cout<<tc3.ToString()<<endl;
	assert(tc3.ToString() == "8:35:9");

	// TimeCode tc = TimeCode(8, 20, 9);
	// tc.SetMinutes(60); // test valid change
	// cout<<tc.ToString()<<endl;
	// assert(tc.ToString() == "8:15:9");

	// try
	// {
	// 	tc.SetMinutes(80);  // test invalid change
	// 	assert(false);
	// }
	// catch (const invalid_argument &e)
	// {
	// 	// cout << e.what() << endl;
	// }

	// assert(tc.ToString() == "8:15:9");

	cout << "PASSED!" << endl << endl;
}

void TestSetHours()
{
	cout << "Testing SetHours" << endl;

	TimeCode tc = TimeCode(8, 5, 9);
	tc.SetHours(3); // test valid change
	cout<<tc.ToString()<<endl;
	assert(tc.ToString() == "3:5:9");

	TimeCode tc2 = TimeCode(12, 5, 9);
	tc2.SetHours(10); // test valid change
	cout<<tc2.ToString()<<endl;
	assert(tc2.ToString() == "10:5:9");

	TimeCode tc3 = TimeCode(12, 5, 9);
	tc3.SetHours(25); // test valid change
	cout<<tc3.ToString()<<endl;
	assert(tc3.ToString() == "25:5:9");

	cout << "PASSED!" << endl << endl;
}

void TestSetSeconds()
{
	cout << "Testing SetSeconds" << endl;

	TimeCode tc = TimeCode(8, 5, 9);
	tc.SetSeconds(3); // test valid change
	cout<<tc.ToString()<<endl;
	assert(tc.ToString() == "8:5:3");

	tc.SetSeconds(15); // test valid change
	cout<<tc.ToString()<<endl;
	assert(tc.ToString() == "8:5:15");


	tc.SetSeconds(59); // test valid change
	cout<<tc.ToString()<<endl;
	assert(tc.ToString() == "8:5:59");

	
	//tc.SetSeconds(71); // test invalid change


	// try
	// {
	// 	tc.SetSeconds(71);  // test invalid change
	// 	assert(false);
	// }
	// catch (const invalid_argument &e)
	// {
	// 	// cout << e.what() << endl;
	// }

	// assert(tc.ToString() == "9:5:9");

	cout << "PASSED!" << endl << endl;
}


void TestGetHours()
{
	cout << "Testing GetHours" << endl;
	int hr;

	TimeCode tc = TimeCode(8, 5, 9);
	hr = tc.GetHours(); // test valid change
	assert(hr == 8);

	TimeCode tc2 = TimeCode(0, 5, 9);
	hr = tc2.GetHours(); // test valid change
	assert(hr == 0);

	cout << "PASSED!" << endl << endl;
}

void TestGetMinutes()
{
	cout << "Testing GetMinutes" << endl;
	int min;

	TimeCode tc = TimeCode(8, 5, 9);
	min = tc.GetMinutes(); // test valid change
	assert(min == 5);

	TimeCode tc2 = TimeCode(8, 0, 9);
	min = tc2.GetMinutes(); // test valid change
	assert(min == 0);

	cout << "PASSED!" << endl << endl;
}

void TestGetSeconds()
{
	cout << "Testing GetSeconds" << endl;
	int sec;

	TimeCode tc = TimeCode(8, 5, 9);
	sec = tc.GetSeconds(); // test valid change
	assert(sec == 9);

	TimeCode tc2 = TimeCode(8, 1, 0);
	sec = tc2.GetSeconds(); // test valid change
	assert(sec == 0);

	cout << "PASSED!" << endl << endl;
}

void TestOperatorEquals()
{
	cout << "Testing ==" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	TimeCode tc2 = TimeCode(8, 1, 0);
	TimeCode tc3 = TimeCode(8, 5, 9);
	
	assert((tc == tc3) == true);
	assert((tc == tc2) == false);
	cout << "PASSED!" << endl << endl;
}

void TestOperatorNotEqual()
{
	cout << "Testing !=" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	TimeCode tc2 = TimeCode(8, 1, 0);
	TimeCode tc3 = TimeCode(8, 5, 9);
	
	assert((tc != tc3) == false);
	assert((tc != tc2) == true);
	cout << "PASSED!" << endl << endl;
}

void TestOperatorLessThan()
{
	cout << "Testing <" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	TimeCode tc2 = TimeCode(8, 1, 0);
	TimeCode tc3 = TimeCode(8, 5, 9);
	
	assert((tc < tc3) == false);
	assert((tc < tc2) == false);
	assert((tc2 < tc) == true);
	assert((tc2 < tc2) == false);

	cout << "PASSED!" << endl << endl;
}


void TestOperatorLessThanOrEqual()
{
	cout << "Testing <=" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	TimeCode tc2 = TimeCode(8, 1, 0);
	TimeCode tc3 = TimeCode(8, 5, 9);
	
	assert((tc <= tc3) == true);
	assert((tc <= tc2) == false);
	assert((tc2 <= tc) == true);
	assert((tc2 <= tc2) == true);

	cout << "PASSED!" << endl << endl;
}


void TestOperatorGreaterThan()
{
	cout << "Testing >" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	TimeCode tc2 = TimeCode(8, 1, 0);
	TimeCode tc3 = TimeCode(8, 5, 9);
	
	assert((tc > tc3) == false);
	assert((tc > tc2) == true);
	assert((tc2 > tc) == false);
	assert((tc2 > tc2) == false);

	cout << "PASSED!" << endl << endl;
}

void TestOperatorGreaterThanOrEqual()
{
	cout << "Testing >=" << endl;
	TimeCode tc = TimeCode(8, 5, 9);
	TimeCode tc2 = TimeCode(8, 1, 0);
	TimeCode tc3 = TimeCode(8, 5, 9);
	
	assert((tc >= tc3) == true);
	assert((tc >= tc2) == true);
	assert((tc2 >= tc) == false);
	assert((tc2 >= tc2) == true);

	cout << "PASSED!" << endl << endl;
}


	
int main(){
	
	TestComponentsToSeconds();
	TestDefaultConstructor();
	TestComponentConstructor();
	TestGetComponents();
	TestSubtract();
	TestAdd();
	TestMultiply();
	TestDivide();
	TestSetMinutes();
	TestSetHours();
	TestSetSeconds();
	TestGetHours();
	TestGetMinutes();
	TestGetSeconds();
	TestOperatorEquals();
	TestOperatorNotEqual();
	TestOperatorLessThan();
	TestOperatorLessThanOrEqual();
	TestOperatorGreaterThan();
	TestOperatorGreaterThanOrEqual();

	
	cout << "PASSED ALL TESTS!!!" << endl;
	return 0;
}
