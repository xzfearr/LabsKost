#include <iostream>
#include <string_view>
#include <cassert>

size_t countOnes(std::string_view sv)
{
    size_t count = 0;

    for (char c : sv)
    {
        if (c == '1')
            count++;
    }

    return count;
}

std::string_view secondWord(std::string_view sv)
{
    size_t len = sv.size();
    size_t start = 0;
    size_t end = 0;

    bool firstSpaceFound = false;

    for (size_t i = 0; i < len; i++)
    {
        if (sv[i] == ' ')
        {
            if (!firstSpaceFound)
            {
                firstSpaceFound = true;
                start = i + 1;

                if (start >= len)
                    return "";

                if (sv[start] == ' ')
                    return "";
            }
            else
            {
                end = i;
                break;
            }
        }
    }

    if (!firstSpaceFound)
        return "";

    if (end == 0)
        end = len;

    return sv.substr(start, end - start);
}


void testCountOnes()
{
    assert(countOnes("") == 0);
    assert(countOnes("00000") == 0);
    assert(countOnes("abc") == 0);

    assert(countOnes("10101") == 3);
    assert(countOnes("111abc11") == 5);

    assert(countOnes("1") == 1);
    assert(countOnes("111111") == 6);
}

void testSecondWord()
{
    assert(secondWord("Hello world") == "world");
    assert(secondWord("Hello my dear") == "my");

    assert(secondWord("") == "");
    assert(secondWord(" ") == "");
    assert(secondWord(" a ") == "a");
    assert(secondWord("a  ") == "");
    assert(secondWord("a  b") == "");
    assert(secondWord("hello     world    dear") == "");
}

int main()
{
    testCountOnes();
    testSecondWord();
}
