#include <iostream>
#include <memory>
#include <string>

/**
 * The Product interface declares the operations that all concrete products must
 * implement.
 */
class Product {
 public:
  virtual ~Product() = default;
  virtual std::string Operation() const = 0;
};

/**
 * Concrete Products provide various implementations of the Product interface.
 */
class ConcreteProduct1 : public Product {
 public:
  std::string Operation() const override {
    return "{Result of the ConcreteProduct1}";
  }
};

class ConcreteProduct2 : public Product {
 public:
  std::string Operation() const override {
    return "{Result of the ConcreteProduct2}";
  }
};

/**
 * The Creator class declares the factory method createProduct() that is supposed to return an
 * object of a Product class. The Creator's subclasses usually provide the
 * implementation of this method.
 */
class Creator {
 public:
  virtual ~Creator() = default;

  // Use std::unique_ptr to return ownership of the created product.
  virtual std::unique_ptr<Product> createProduct() const = 0;

  /**
   * Also note that, despite its name, the Creator's primary responsibility is
   * not creating products. Usually, it contains some core business logic that
   * relies on Product objects, returned by the factory method createProduct(). Subclasses can
   * indirectly change that business logic by overriding the createProduct() method and
   * returning a different type of product from it.
   */
  std::string SomeOperation() const {
    // Call the factory method to create a Product object.
    auto product = this->createProduct();
    // Now, use the product.
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    return result;
  }
};

/**
 * Concrete Creators override the factory method in order to change the
 * resulting product's type.
 */
class ConcreteCreator1 : public Creator {
 public:
  std::unique_ptr<Product> createProduct() const override {
    return std::make_unique<ConcreteProduct1>();
  }
};

class ConcreteCreator2 : public Creator {
 public:
  std::unique_ptr<Product> createProduct() const override {
    return std::make_unique<ConcreteProduct2>();
  }
};

/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void ClientCode(const Creator& creator) {
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << creator.SomeOperation() << std::endl;
}

/**
 * The Application picks a creator's type depending on the configuration or
 * environment.
 */

int main() {
  std::cout << "App: Launched with the ConcreteCreator1.\n";
  auto creator1 = std::make_shared<ConcreteCreator1>();
  ClientCode(*creator1);
  
  std::cout << std::endl;
  
  std::cout << "App: Launched with the ConcreteCreator2.\n";
  auto creator2 = std::make_shared<ConcreteCreator2>();
  ClientCode(*creator2);

  return 0;
}
