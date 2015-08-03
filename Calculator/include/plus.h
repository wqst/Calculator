#ifndef CS225_PLUS_H_
#define CS225_PLUS_H_

#include "binary_op.h"

namespace cs225
{
class plus: public binary_op
{
 public:
 
using binary_op::binary_op;

double combine(double left,double right)const override;

};

}

#endif
