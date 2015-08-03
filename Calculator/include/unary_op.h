#ifndef CS225_UNARY_OP_H_
#define CS225_UNARY_OP_H_

#include <memory>
#include "node.h"

namespace cs225
{
 class unary_op: public node
{
  public:
  
unary_op(std::unique_ptr<node> arg);
  double value() const override;

  virtual double compute(double val) const=0;

  private:

 std::unique_ptr<node> arg_;
};
 std::unique_ptr<unary_op>  make_unary_op(const std::string &op, std::unique_ptr<node> arg);

}

#endif
