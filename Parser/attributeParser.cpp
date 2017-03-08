#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
#include <experimental/optional>

using namespace std;
using namespace experimental;

/** Input string for testing. */
istringstream const input(R"(6 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
<tag3 akuma = "Messatsu" ryu = "tetsuzanko">
</tag3>
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value)");

/* Types */
/** An attribute is a concrete type. */
struct Attribute {
    string identifier;
    string value;
};

/** A tag can have multiple attributes and multiple inner tags. */
struct Tag {
    string identifier;
    vector<Attribute> attributes;
    vector<Tag*> innerTags;
    Tag* parent = nullptr;
};

/* Forward Declarations */
void getMarkup(int const n, Tag& rootTag);
void getQueries(int const q, Tag& rootTag);
optional<Tag*> tryParseLine(string line, Tag*& currentTag);
std::string tryDereference(string line, Tag& rootTag);

/** Main */
int main() {
    Tag rootTag;

    // Redefine standard input for testing purposes
    cin.rdbuf(input.rdbuf());

    // Display input for testing purposes, consumes the buffer when uncommented.
    //cerr << input.rdbuf() << endl;

    int n,  // Number of lines
        q;  // Number of queries
    cin >> n >> q;
    //cerr << n << " " << q << endl;

    // Remove useless linebreak after q(the number of queries).
    string useless;
    getline(cin, useless);

    // Line-break for clarity
    cout << '\n';

    // Gets the lines of our markup language.
    getMarkup(n, rootTag);

    // Line-break for clarity
    cout << '\n';

    // Gets the queries to run.
    getQueries(q, rootTag);

    return 0;
}

/* Functions */
/** Gets the lines of our markup language. */
void getMarkup(int const n, Tag& rootTag) {
    Tag* currentTag = &rootTag;

    for (int i = 0; i < n; ++i) {
        string line;

        getline(cin, line);

        cout << line << '\n';

        // Try to parse line for our language.
        optional<Tag*> tag = tryParseLine(line, currentTag);
        if (tag)
        {
            currentTag->innerTags.emplace_back(*tag);
            currentTag->innerTags.back()->parent = currentTag;
            currentTag = currentTag->innerTags.back();
        }
    }
}

/** Tries to parse the line for our language's structure. */
optional<Tag*> tryParseLine(string line, Tag*& currentTag) {
    // Create new tag object that it's going to be returned if everything goes well.
    Tag* tag = new Tag();

    // Check if it's a valid opening tag, or closing tag
    regex rexOpening (R"(<([^\/].*?)[\s>])");
    regex rexClosing (R"(<\/.+?[\s>])");
    smatch match;
    if (regex_search(line, match, rexOpening))
    {
        tag->identifier = match[1];
    }
    else if (regex_search(line, match, rexClosing))
    {
        currentTag = currentTag->parent;
        return {};
    }
    else
        return {};



    // Then get its attributes
    regex rexAttribute = regex(R"( *(.+?)\s*=\s*\"(.+?)\")");
    line = match.suffix();
    while (regex_search(line, match, rexAttribute))
    {
        Attribute attr;
        attr.identifier = match[1];
        attr.value = match[2];
        tag->attributes.push_back(attr);
        line = match.suffix();
    }

    return tag;
}

/** Gets the queries to run. */
void getQueries(int const q, Tag& rootTag) {
    for (int i = 0; i < q; ++i) {
        string line;

        getline(cin, line);

        cout << line << '\n';

        cout << tryDereference(line, rootTag) << '\n';
    }
}

/** Tries to get the value based on the query ran. */
std::string tryDereference(string line, Tag& rootTag)
{
    Tag* currentTag = &rootTag;

    // Traverse the _tag1.tag2.tagn_ sequence
    regex rex(R"((\w+?)\.)");
    smatch match;
    while (regex_search(line, match, rex))
    {
        // Try to find the specified tag
        auto it = currentTag->innerTags.begin();
        while (it != currentTag->innerTags.end())
        {
            if ((*it)->identifier == static_cast<string>(match[1]))
            {
                currentTag = *it;
                break;
            }
            ++it;
        }
        if (it == currentTag->innerTags.end())
            // Didn't find because didn't have the specified tag.
            return "Not Found!";

        line = match.suffix();
    }

    // Try to find value through tag~value
    rex = (R"((\w+?)~)");
    if (regex_search(line, match, rex))
    {
        // Try to find the specified tag
        auto it = currentTag->innerTags.begin();
        while (it != currentTag->innerTags.end())
        {
            if ((*it)->identifier == static_cast<string>(match[1]))
            {
                currentTag = *it;
                break;
            }
            ++it;
        }
        if (it == currentTag->innerTags.end())
            // Didn't find because didn't have the specified tag.
            return "Not Found!";

        line = match.suffix();

        // Get attribute's name or value
        line = line.substr(line.find_first_not_of(" "), line.find_last_not_of(" \n") + 1);
        auto ita = currentTag->attributes.begin();
        while (ita != currentTag->attributes.end())
        {
            if ((*ita).identifier == line)
            {
                return (*ita).value;
            }
            ++ita;
        }
    }

    // Didn't find
    return "Not Found!";
}
