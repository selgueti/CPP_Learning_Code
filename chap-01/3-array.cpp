#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
    using namespace std;
    int length = 0;
    if (argc < 2)
    {
        cerr << "Expected argument for array size." << endl;
        return -1;
    }
    else
    {
        length = stoi(argv[1]);
        if (length < 0)
        {
            cout << "array length must be > 0" << endl;
            return -1;
        }
    }
    vector<int> array;
    for (int i = 0; i < length; i++)
    {
        array.emplace_back(i + 1);
    }
    for (int value : array)
    {
        cout << value << endl;
    }
    return 0;
}
