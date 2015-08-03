#include "terminal.h"
#include "circ_array.h"

namespace cs225

{


  terminal::terminal(double value)
 { value_=value;}

 double terminal::value() const
 {
   return value_;
 }

 std::unique_ptr<terminal> make_term(double value)
{
  std::unique_ptr<terminal> p{new terminal(value)};
 return std::move(p);
 }


}
