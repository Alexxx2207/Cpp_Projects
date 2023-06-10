/* Proving the machine's endianity. */
#include <iostream>
#include <functional>

using namespace std;

int main()
{
    /* Recursively check is Little endianity. */
    /* by using Allman coding style and only one return (without early returns) (if any) */
    auto isLittleEndian = []()
    {
        int i = 50462976; /* {0, 1, 2, 3} */
        char cArr[] = { 0, 1, 2, 3 };

        function<bool(char*, char*, char*)> _isLittleEndian = [&_isLittleEndian](char* cPI, char* cArrBegin, char* cArrEnd) -> bool
        {
            bool result;

            if (cArrBegin > cArrEnd)
            {
                result = true;
            }
            else
            {
                result = (int)*cPI == (int)*cArrBegin ? _isLittleEndian(++cPI, ++cArrBegin, cArrEnd) : false;
            }

            return result;
        };

        return _isLittleEndian((char*)&i, cArr, cArr + 3);
    };

    cout << std::boolalpha;
    cout << isLittleEndian();

    return 0;
}
