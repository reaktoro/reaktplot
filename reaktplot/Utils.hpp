// reaktplot - a modern C++ scientific plotting library powered by gnuplot
// https://github.com/reaktplot/reaktplot
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
//
// Copyright (c) 2022-2023 Allan Leal
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

// C++ includes
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string>
#include <type_traits>

// reaktplot includes
#include <reaktplot/Constants.hpp>
#include <reaktplot/Enums.hpp>

namespace reaktplot {
namespace detail {

/// Return a string for a given value of a generic type.
template <typename T>
auto str(const T& val) -> std::string
{
    std::stringstream ss;
    ss << val;
    return ss.str(); // Note: This is different than std::to_string(i). For example, it works with custom types. Also, std::to_string(2.0) may produce "2.000000", difficulting string comparison in the tests.
}

/// Return a string for a given char array
inline auto str(const char* word) -> std::string
{
    return word;
}

/// Return an empty string
inline auto str() -> std::string
{
    return {};
}

/// Remove from the beginning of the string the given character (by default, space).
inline auto trimleft(std::string str, unsigned char character = ' ') -> std::string
{
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [&](unsigned char ch) { return ch != character; }));
    return str;
}

/// Remove from the end of the string the given character (by default, space).
inline auto trimright(std::string str, unsigned char character = ' ') -> std::string
{
    str.erase(std::find_if(str.rbegin(), str.rend(), [&](unsigned char ch) { return ch != character; }).base(), str.end());
    return str;
}

/// Trim the string from both ends
inline auto trim(std::string str, unsigned char character = ' ') -> std::string
{
    return trimleft(trimright(str, character), character);
}

/// Remove extra spaces from a string (e.g., `"abc  acb   xy s "` becomes `"abc acb xy s "`).
inline auto collapseWhitespaces(std::string s) -> std::string
{
    s.erase(std::unique(std::begin(s), std::end(s), [](unsigned char a, unsigned char b) { return std::isspace(a) && std::isspace(b); }), std::end(s));
    return s;
}

/// Trim and collapse all spaces in a string (e.g., `"  abc  acb   xy s "` becomes `"abc acb xy s"`).
inline auto removeExtraWhitespaces(std::string s) -> std::string
{
    return trim(collapseWhitespaces(s));
}

/// Auxiliary function that returns the size of the vector argument with least size (for a single vector case)
template <typename VectorType>
auto minsize(const VectorType& v) -> std::size_t
{
    return v.size();
}

/// Auxiliary function that returns the size of the vector argument with least size
template <typename VectorType, typename... Args>
auto minsize(const VectorType& v, const Args&... args) -> std::size_t
{
    return std::min<decltype(v.size())>(v.size(), minsize(args...));
}

/// Check if type @p T is `std::string`.
template <typename T>
constexpr auto isString = std::is_same_v<std::decay_t<T>, std::string>;

/// Check if type @p T is `std::string`.
template <typename V>
constexpr auto isStringVector = isString<decltype(std::declval<V>()[0])>;

} // namespace detail
} // namespace reaktplot
