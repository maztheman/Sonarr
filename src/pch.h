#include <exception>
#include <string>
#include <fstream>
#include <vector>
#include <string_view>
#include <functional>

#include <fmt/format.h>

template<typename Res, typename... ArgTypes>
using Func = std::function<Res, ArgTypes...>;