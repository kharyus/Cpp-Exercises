#include "Template.hpp"
#include "Template2.hpp"

int main()
{
    Template<int> templInt;
    Template<std::string> templStr;

    Template2<int> templ2Int;
    Template2<std::string> templ2Str;

    templInt.display("Templates Exercise");
    templInt.hello(5);
    templStr.hello("Banana");

    templ2Int.hello(6);
    templ2Str.hello("Apple");

    return 0;
}
