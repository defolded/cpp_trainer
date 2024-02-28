int main()
{
    int value{ 5 };
    int* ptr{ new int{} }; // allocate memory
    delete ptr; // return memory back to operating system
    ptr = &value; // reassign pointer to address of value

    return 0;
}