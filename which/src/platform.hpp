#pragma once
#include <string>
#include <vector>

namespace platform
{
    std::vector<std::string> get_path_dirs();

#ifdef _WIN32
    const char os_pathsep{';'};
    const char dir_sep{'\\'};
#else
    const char os_pathsep{':'};
    const char dir_sep{'/'};
#endif
} // namespace name
