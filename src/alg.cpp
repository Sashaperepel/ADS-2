// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  int temp = value;
  for (int i = 1; i < n; ++i) {
    value = value * temp;
  }
  if (n == 0)
    value = 1;
  return value;
}

uint64_t fact(uint16_t n) {
  if (n <= 1)
    return 1;
  return n = n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  double value;
  value = (pown(x, n)) / (fact(n));
  return value;
}

double expn(double x, uint16_t count) {
  double value = 0;
  for (int i = 0; i <= count; ++i) {
    value = calcItem(x, i) + value;
  }
  return value;
}

double sinn(double x, uint16_t count) {
  double value = 0;
  int k = 1;
  bool flag = true;
  for (int i = 1; i <= count; ++i) {
    if (i % 2 == 0)
      k = k + 2;
    if (flag) {
      value = value + calcItem(x, k);
      flag = false;
    }
    else {
      value = value - calcItem(x, k);
      flag = true;
    }
  }
  return value;
}

double cosn(double x, uint16_t count) {
  double value = 0;
  int k = 0;
  bool flag = true;
  for (int i = 0; i < count; ++i) {
    if (i % 2 == 1)
      k = k + 2;
    if (flag) {
      value = value + calcItem(x, k);
      flag = false;
    }
    else {
      value = value - calcItem(x, k);
      flag = true;
    }
  }
  return value;
}
