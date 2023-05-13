#ifndef IS_LAB_5_INCLUDE_POWER_H_
#define IS_LAB_5_INCLUDE_POWER_H_

template<typename T, int power>
T Power(T value) {
  if (power < 0) return 1.0 / Power<T, -power>(value);

  T result = 1;

  for (int i = 0; i < power; i++) {
    result *= value;
  }

  return result;
}

#endif //IS_LAB_5_INCLUDE_POWER_H_
