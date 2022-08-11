#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <tuple>

#include "platform.hpp"
#include "which.hpp"

using namespace std;

void show_locations(const map<string, vector<string>> &locations)
{
    if (locations.size() == 0)
        return;
    cout << "Commands found:\n";
    for (const auto &[name, paths] : locations)
    {
        cout << name << endl;
        for (const auto &path : paths)
            cout << '\t' << path << endl;
    }
}

void show_not_in_path(const vector<string> &names)
{
    if (names.size() == 0)
        return;
    cout << "Not found in path commands:\n";
    for (const auto &name : names)
        cout << name << endl;
}

const string help_text =
    " [names...]\n\n"
    "Locates the path of the provided names.\n\n"
    "names: names of the commands to look for\n";

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "Usage:\n"
             << argv[0] << help_text;
    }
    vector<string> names{};
    for (int i = 1; i < argc; i++)
    {
        names.push_back(argv[i]);
    }

    const vector<string> dirs = platform::get_path_dirs();

    map<string, vector<string>> found;
    vector<string> not_found;
    std::tie(found, not_found) = which::which(names, dirs);

    show_locations(found);
    if (found.size() > 0)
        cout << "\n";
    show_not_in_path(not_found);
    return 0;
}