#pragma once

#include <algorithm>
#include <array>
#include <map>
#include <sstream>
#include <vector>

namespace pokerbots::skeleton {

template <typename Container>
bool isEmpty(Container &&c) {
  return std::all_of(c.begin(), c.end(), [](auto &&v) { return v.empty(); });
}

template <typename Iterator>
std::string join(const Iterator begin, const Iterator end,
                 const std::string &separator) {
  std::ostringstream oss;
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) oss << separator;
    oss << *it;
  }
  return oss.str();
}

}  // namespace pokerbots::skeleton
