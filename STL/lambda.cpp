#include <iostream>
using namespace std;


signed main()
{

// Lamda Expression
//[capture](parameters) -> return_type { body }

int x = 10;
auto printX = [x]() { cout << x << std::endl; };
printX(); // Output: 10


auto incrementX = [&x]() { ++x; };
incrementX();
cout << x << std::endl; // Output: 11


int a = 5;
int b = 10;
auto sum = [a, b]() { return a + b; };
cout << sum(); // Output: 15


auto multiply = [](int a, int b = 2) { return a * b; };
cout << multiply(3); // Output: 6
cout << multiply(3, 4); // Output: 12


auto add = [](int a, int b) { return a + b; };
cout << add(3, 4); // Output: 7


// vector<int> numbers = {5, 3, 8, 1};
// sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });




}