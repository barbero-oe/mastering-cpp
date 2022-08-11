#pragma once

#include <tuple>
#include <vector>
#include <map>
#include <string>

namespace which
{
    std::tuple<
        std::map<std::string, std::vector<std::string>>,
        std::vector<std::string>>
    which(
        const std::vector<std::string> &,
        const std::vector<std::string> &);

    std::vector<std::string> locate(const std::string &, const std::vector<std::string> &);
}