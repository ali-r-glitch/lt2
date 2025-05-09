#include <iostream>
#include <cassert>
#include "bmi.cpp"

using namespace std;

void test_pound()
{// test the ounce to pound conversion
assert(ounces2pounds(16)==1);
assert(ounces2pounds(0)==0);
assert(ounces2pounds(240)==15);
cout << "test_ounces2pounds passed.\n";
}

void test_ounce()
{//test the stones to pound conversion
assert(stones2pounds(1)==14);
assert(stones2pounds(0)==0);
assert(stones2pounds(15)==210);
cout <<"test_ounce paseed.\n ";
}
void test_weight() 
{//test the  conversion to metric kg
double result = weight2kg(10, 5, 8);  // 10st = 140, +5, +128 = 273 lbs 273/2.2 more or less equals 124.1
assert((result > 66.0 && result < 67.0));
cout << "test_weight2kg passed.\n";
}

void test_categorise()
{//test the bmi test
  assert(categorise(40, 1.9) == 'A');
    // Normal BMI
    assert(categorise(60, 1.7) == 'B');
    // Overweight BMI
    assert(categorise(75, 1.6) == 'C');
    // Extremely high BMI
    assert(categorise(100, 1.5) == 'D');  
cout << "test_categorise passed.\n";
}
int main() {
test_pound();
test_ounce();
test_weight();
test_categorise();
cout << "All tests passed.\n";
return 0;
}
