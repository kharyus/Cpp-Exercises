#include <iostream>
#include <experimental/optional>
#include <memory>
#include <vector>

using namespace std;
using namespace std::experimental;
//using std::experimental;

/** I don't want to pass ownership to the optional<unique_ptr> but it seems that there is no _sane_ way of passing references.
  * Having 3 layers of dereferencing everywhere on the code is so ugly. */


struct Messatsu {};

ostream& operator<<(ostream& os, Messatsu& messatsu)
{
    os << "Messsatsu!";
    return os;
}

int insane_way_main()
{
    unique_ptr<int> metsu;

    optional<int> shinku;

    optional<unique_ptr<int>> qwe(make_unique<int>(5));

    // 2 Layers of dereferencing, UGH!
    if (qwe)
        cout << **qwe << endl;

    vector<unique_ptr<Messatsu>> messatsus;
    messatsus.emplace_back();

    // A pointer to a unique pointer encapsulated by an optional...
    optional<unique_ptr<Messatsu>*> optMessatsu = &messatsus[0];

    // Holy shit, 3 layers.................. no comments.
    std::cout << ***optMessatsu << endl;

    return 0;
}

/** The saner way */
/** Intent is clear, no overhead and no dereferencing hell. */
template <typename T>
using optional_ptr = unique_ptr<T>;

int main()
{
    optional_ptr<int> myPtr(new int(5));

    // 1 Layer, exactly what should be expected.
    std::cout << *myPtr;
}
