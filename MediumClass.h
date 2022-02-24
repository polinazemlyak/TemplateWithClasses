#ifndef MEDIUMCLASS_H
#define MEDIUMCLASS_H

#include <iostream>
#include <string>
#include "Types.h"

class Product {
  std::string code;
  std::string name;
  int price;
  int discount;
  int count;

public:
  Product();

  bool operator==(const Product& prod) {
    return this->code == prod.code;
  };

  friend class Busket;
};

typedef Product* ProductLink;

class Busket {
  //Product** goods;
  ProductLink* goods;
  int size;     // максимальный размер корзины
  int count;
  ProductLink last;

public:
  Busket() {
    size = 50;
    count = 0;
    last = nullptr;
    goods = new ProductLink[size];
  };

  ~Busket() {
    delete[] goods;
  };

  void add() {
    *this += last;
  };

  Busket& operator+=(const ProductLink& prod) {
    for (int i = 0; i < count; i++) {
      if (*goods[i] == *prod) {
        goods[i]->count += 1;
        return *this;
      }
    }
    count++;
    goods[count] = prod; // =!!!!
    goods[count]->count += 1;

    return *this;
  }
};

#endif // MEDIUMCLASS_H
