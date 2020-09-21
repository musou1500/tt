#ifndef ERASTOSTHENES_HH
#define ERASTOSTHENES_HH

#include <vector>

namespace tt {
class Eratosthenes {
 private:
  std::vector<bool> is_prime_;

 public:
  Eratosthenes(int max_n) : is_prime_(max_n + 1, true) {
    is_prime_[0] = is_prime_[1] = false;
    for (int i = 2; i < is_prime_.size(); i++) {
      if (!is_prime_[i]) {
        continue;
      }

      for (int j = i * 2; j < is_prime_.size(); j += i) {
        is_prime_[j] = false;
      }
    }
  }

  bool operator()(int n) { return is_prime_[n]; }
};

}  // namespace tt

#endif
