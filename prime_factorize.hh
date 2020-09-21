#ifndef PRIME_FACTORIZE_HH
#define PRIME_FACTORIZE_HH

#include <utility>
#include <vector>

namespace tt {
template <typename T, typename = typename std::enable_if<
                          std::is_integral<T>::value, T>::type>
std::vector<std::pair<T, int>> prime_factorize(T n) {
  std::vector<std::pair<T, int>> cnts{};
  if (n == 1) {
    return cnts;
  }

  T a = 2;
  while (n >= a * a) {
    int cnt = 0;
    while (n % a == 0) {
      n /= a;
      cnt++;
    }

    if (cnt > 0) {
      cnts.push_back({a, cnt});
    }

    a++;
  }

  if (n != 1) {
    cnts.push_back({n, 1});
  }

  return cnts;
}

}  // namespace tt

#endif
