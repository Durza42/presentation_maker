#include <array>
#include <vector>
#include <cmath>
#include <iostream>

/**
 * @brief this function is used to get the description of the mathematical function corresponding to a transition between two slides.
 * @details the mathematical function is `sin(x)`.
 * `transition_values()` will returns an array starting at a chosen value of the math function and stopping at another chosen value.
 * Both are selected to make a transition as smouth as possible. 
 * exemple: for the sin function, it goes from 0 to PI because sin(0) = 0 and sin(PI) = 0. It will starts sliding slowly, and stop sliding slowly.
 * As the sum of all elements of the array is equal to 1, is might be easly used es descriptor for a movment.
 * 
 * @tparam _N the numbers of elements the returned array will contains: the more it is high, the more the array will be precise, and the more it will takes memory.
 * @return constexpr std::array<double, _N> the array describing the function
 */
template <std::size_t _N>
constexpr
std::array<double, _N> transition_values()
noexcept
{
TODO: // à revoir. pas constexpr car code brut => std::iota ? (NON) + boucle for étrange => params 1 de 2 types différents ? (size_t & double)

    /*
     * f : x -> sin(x)
     * begin: 0
     * end: PI
     */

    constexpr double begin = 0;
    constexpr double end = M_PI;
    double total = 0;

    std::array<double, _N> ret = {0};
    for(double i = 0, x = begin ; i <= _N ; ++i, x += (end - begin) / double(_N))
    {
        ret[i] = sin(x);
        total += ret[i];
    }

    double tot2 = 0;
    for(auto& it : ret)
    {
        it /= total;
        tot2 += it;
    }

    for(auto it : ret)
        std::cout << it << std::endl;
    std::cout << tot2 << std::endl;

    return ret;
}


/**
 * @brief this function is similar to others `transition_value()`; it retruns a vector of the size required which describes the behavior of the transition function.
 * 
 * @param precision the size of the returned vector. The more it is high, the more it is is precise, but the more it will take mémory
 * @return const std::vector<double> a std::vector describing the function
 */
inline
const std::vector<double> transition_values(std::size_t const precision)
noexcept
{
TODO: // à revoir. pas constexpr car code brut => std::iota ? (NON) + boucle for étrange => params 1 de 2 types différents ? (size_t & double)

    /*
     * f : x -> sin(x)
     * begin: 0
     * end: PI
     */

    constexpr double begin = 0;
    constexpr double end = M_PI;
    double total = 0;

    std::vector<double> ret(precision, 0);
    for(double i = 0, x = begin ; i <= precision ; ++i, x += (end - begin) / double(precision))
    {
        ret[i] = sin(x);
        total += ret[i];
    }

    double tot2 = 0;
    for(auto& it : ret)
    {
        it /= total;
        tot2 += it;
    }

    for(auto it : ret)
        std::cout << it << std::endl;
    std::cout << tot2 << std::endl;

    return ret;
}
