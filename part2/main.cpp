#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

using Cond = std::vector<std::array<int, 2>>;
using Ip = std::vector<int>;

bool filter(const Cond conditions, const Ip& ip)
{
    for (const auto& condition : conditions)
    {
        if (ip[condition[0]] != condition[1])
            return false;
    }
    return true;
}

bool filter_any(const Cond conditions, const Ip& ip)
{
    for (const auto& condition : conditions)
    {
        if (filter({condition}, ip))
            return true;
    }
    return false;
}

Ip split_ip(const std::string& str, char d)
{
    auto ip = split(str, d);
    Ip res;

    std::transform(ip.begin(), ip.end(), std::back_inserter(res), [](const auto& ip_part)
        {
            return std::stoi(ip_part);
        });

    return res;
}

void print_ip(const std::vector<int>& ip_line)
{
    for (std::vector<int>::const_iterator ip_part = ip_line.begin(); ip_part != ip_line.end(); ++ip_part)
    {
        std::cout << *ip_part;
        if (ip_part != ip_line.end() - 1)
        {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    try
    {
        std::vector<Ip> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split_ip(v.at(0), '.'));
        }

        std::sort(ip_pool.rbegin(), ip_pool.rend());

        for(const auto& ip_line: ip_pool)
        {
            print_ip(ip_line);
        }

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)
        for (const auto& ip_line : ip_pool)
        {
            if (filter({ {0,1} }, ip_line))
                print_ip(ip_line);
        }

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)
        for (const auto& ip_line : ip_pool)
        {
            if (filter({ {0,46}, {1,70} }, ip_line))
                print_ip(ip_line);
        }

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)
        for (const auto& ip_line : ip_pool)
        {
            if (filter_any({ {0,46}, {1,46}, {2,46}, {3,46} }, ip_line))
                print_ip(ip_line);
        }

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
