#include <filesystem>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "platform.hpp"
#include "which.hpp"

using namespace std;
namespace fs = filesystem;
namespace which
{

    tuple<map<string, vector<string>>, vector<string>> which(const vector<string> &names, const vector<string> &dirs)
    {
        map<string, vector<string>> found;
        vector<string> not_found;
        for (const auto &name : names)
        {
            auto locations = locate(name, dirs);
            if (locations.size() != 0)
                found[name] = locations;
            else
                not_found.push_back(name);
        }
        return make_tuple(found, not_found);
    }

    vector<string> locate(const string &name, const vector<string> &dirs)
    {
        vector<string> found_in;
        for (const auto &dir : dirs)
        {
            const string path = dir + platform::dir_sep + name;
            const auto status = fs::status(path);
            if (status.type() == fs::file_type::not_found)
                continue;
            if (!fs::is_regular_file(status))
                continue;
            const static fs::perms exec = fs::perms::group_exec | fs::perms::owner_exec | fs::perms::others_exec;
            const bool is_executable = (status.permissions() & exec) != fs::perms::none;
            if (is_executable)
                found_in.push_back(path);
        }
        return found_in;
    }
}