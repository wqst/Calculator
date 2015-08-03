#ifndef CS225_TERMINAL_H_
#define CS225_TERMINAL_H_

#include <memory>
#include "node.h"

namespace cs225

{

class terminal: public node
{
  public:
  terminal(double value);

  double value() const override;

  private:
  double value_;

  
};
 
  std::unique_ptr<terminal> make_term(double value);

}



#endif
