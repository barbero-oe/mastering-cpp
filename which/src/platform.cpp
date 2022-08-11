#include <sstream>
#include <vector>
#include <string>

#include "platform.hpp"

namespace platform
{
    using namespace std;

    vector<string> get_path_dirs()
    {
        vector<string> dirs;
        stringstream path_env{getenv("PATH")};
        string path;
        while (getline(path_env, path, os_pathsep))
        {
            dirs.push_back(path);
        }
        return dirs;
    }
} // namespace platform