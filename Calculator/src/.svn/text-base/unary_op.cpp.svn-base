#include <iostream>
#include <string>
#include <cassert>
#include <string>
#include "uminus.h"
#include "unary_op.h"
#include "uplus.h"

namespace cs225
{

unary_op::unary_op(std::unique_ptr<node> arg)
{
 arg_.swap(arg);
}

double unary_op::value() const
{
 return compute(arg_->value());
}

/**virtual double unary_op::compute(double val) const
{
 
}**/

std::unique_ptr<unary_op> make_unary_op(const std::string &op, std::unique_ptr<node> arg)
{
 if (op=="#")
  { std::unique_ptr<unary_op> p{new uplus(std::move(arg))};
    return p;} 
    
 else 
 {  std::unique_ptr<unary_op> p{new uminus(std::move(arg))};
   return p;}

 
}

}

