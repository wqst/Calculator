#include <iostream>
#include <string>
#include "binary_op.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "exponent.h"


namespace cs225

{
 binary_op::binary_op(std::unique_ptr<node>left, std::unique_ptr<node>right)
{
 left_.swap(left);
 right_.swap(right);
}

 double binary_op::value()const
{
 return combine(left_->value(),right_->value());
}
 
 std::unique_ptr<binary_op> make_binary_op(const std::string &op, std::unique_ptr<node> left, std::unique_ptr<node> right)
{
   //std::unique_ptr<binary_op> p;
   if (op.compare("+")==0)
  {std::unique_ptr<binary_op>  p{new plus(std::move(left),std::move(right))};
   return p;} 
    
 else if (op.compare("-")==0)
   {std::unique_ptr<binary_op> p{new minus(std::move(left),std::move(right))};
    return p;}
 else if (op.compare("*")==0)
   {std::unique_ptr<binary_op> p{new times(std::move(left),std::move(right))};
     return p;}
 else if (op.compare("/")==0)
   {std::unique_ptr<binary_op> p{new divide(std::move(left),std::move(right))};
     return p;}
 else 
   {std::unique_ptr<binary_op> p{new exponent(std::move(left),std::move(right))};
     return p;}

 
}


/** virtual double binary_op::combine(double left, double right)const
{

}
**/

}
