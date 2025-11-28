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
    size_t first = sv.find(' ');
    if (first == std::string_view::npos)
        return "";

    size_t start = first + 1;

    while (start < sv.size() && sv[start] == ' ')
        start++;

    if (start >= sv.size())
        return "";

    size_t second = sv.find(' ', start);

    if (second == std::string_view::npos)
        return sv.substr(start);

    return sv.substr(start, second - start);
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
    assert(secondWord("hello     world    dear") == "world");
}

int main()
{
    testCountOnes();
    testSecondWord();

    std::cout << "All tests passed!\n";
}
