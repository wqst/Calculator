#ifndef CS225_DIVIDE_H_
#define CS225_DIVIDE_H_
#include "binary_op.h"

namespace cs225
{
class divide: public binary_op 
{
 public:
using binary_op::binary_op;
 double combine(double left,double right)const override;
};

}

#endif
