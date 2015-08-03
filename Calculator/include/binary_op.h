#ifndef CS225_BINARY_OP_H
#define CS225_BINARY_OP_H
#include <memory>
#include "node.h"



namespace cs225
{
class binary_op: public node
{
  public:
  binary_op(std::unique_ptr<node>left, std::unique_ptr<node> right);

  double value()const override;

  virtual double combine(double left, double right)const=0;
  
 private:
 std::unique_ptr<node> left_;
 std::unique_ptr<node> right_;

};


std::unique_ptr<binary_op> make_binary_op(const std::string &op, std::unique_ptr<node> left, std::unique_ptr<node> right);


 
}
#endif
