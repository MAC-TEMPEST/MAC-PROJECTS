#include <iostream>

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int n;

  std::cout << "Entrez un nombre entier : ";
  std::cin >> n;

  std::cout << "Le " << n << "ème nombre de Fibonacci est : " << fibonacci(n) << std::endl;

  return 0;
}

