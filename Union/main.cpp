#include <cstdint>
#include <iostream>

#define NUMBER_OF_PRODUCTS 50

struct Product {
  std::string name;
  double price;

};

struct Card{
  std::string title;
  Product products[10];
};

union Bill{
  char * title;
  int quantity;
  double price;
  double total;
  Card card;
  Product product;
};

int main () {

  std::cout << "size of Product: " << sizeof(Product) << '\n';
  std::cout << "size of Card: " << sizeof(Card) << '\n';
  std::cout << "size of Bill: " << sizeof(Bill);

  return 0;
}
