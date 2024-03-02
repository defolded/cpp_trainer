// A function named max() that takes two doubles and returns the larger of the two.
double max(const double& a, const double& b);

// A function named swap() that swaps two integers.
void swap(int& a, int& b);

// A function named getLargestElement() that takes a dynamically allocated array
// of integers and returns the largest number in such a way that the caller can
// change the value of the element returned (don’t forget the length parameter).

// Note: array can't be const in this case, because returning a non-const reference
// to a const element would be a const violation.
int& getLargestElement(int* array, int length);

int main()
{
    return 0;
}