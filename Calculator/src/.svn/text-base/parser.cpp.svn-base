/**
 * @file parser.cpp
 * @author Chase Geigle
 * @date Summer 2014
 */

#include <cassert>
#include "parser.h"
#include "operation.h"
#include "number.h"
#include "terminal.h"
#include "binary_op.h"
#include "unary_op.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "exponent.h"
#include "uminus.h"
#include "uplus.h"

namespace cs225
{

/**
 * A "private class" for helping us parse expressions. Maintains all of the
 * state necessary to perform Dijkstra's shunting-yard algorithm.
 *
 * @see https://en.wikipedia.org/wiki/Shunting-yard_algorithm
 */
class parser
{
  public:
    /**
     * @param tokens The tokens to parse
     * @return the root of the parse tree for that expression
     */
    std::unique_ptr<node> parse(queue<std::unique_ptr<token>>& tokens);

  private:
    // add lots of other helper methods here!

    /**
     * The stack to hold the operator tokens encountered. This is the "side
     * rail" in the shunting yard algorithm.
     */
    stack<std::unique_ptr<token>> ops_;

    /**
     * What is this for? It is a mystery (and a hint)!
     */
    stack<std::unique_ptr<node>> nodes_;
    queue<std::unique_ptr<token>> output;
};

std::unique_ptr<node> parse(queue<std::unique_ptr<token>>& tokens)
{
    parser p;
    return p.parse(tokens);
}

std::unique_ptr<node> parser::parse(queue<std::unique_ptr<token>>& tokens)
{//std::cout <<"what"<< std::endl;
auto& t=tokens.front();
    if (t->text()=="/"||t->text()=="*"||t->text()=="^")
      throw std::runtime_error ("First should be a number!");
    while (!tokens.empty())
    {
        auto& tok = tokens.front();
        if  (tok->type()==token_type::OPERATION)
          {
                if (ops_.empty())
             {std::cout <<"operation"<< std::endl;
              std::cout <<"what"<< std::endl;
               ops_.push(std::move(tok));
               tokens.pop();    
    	     } 
       
                 
             
     
        else if (ops_.top()->text()=="(") 
      { 
        ops_.push(std::move(tok));
              
             tokens.pop();

      }  
          else if (tok->as_operation()->precedence()<ops_.top()->as_operation()->precedence()||((tok->as_operation()->associativity()==associativity::LEFT)&&(tok->as_operation()->precedence()<=ops_.top()->as_operation()->precedence())))
      {
           output.push(std::move(ops_.top()));
           ops_.pop();
           ops_.push(std::move(tok)); 
           tokens.pop();
      }
            
       else {std::cout <<"operation"<< std::endl;

             ops_.push(std::move(tok));
              
             tokens.pop();
            }
    //std::cout <<"what"<< std::endl;
          if (tokens.empty())
            throw std::runtime_error("extra operators!");
               
          }
        
         else if (tok->type()==token_type::TEXT)
        {
          if (tok->text()=="(")
             {ops_.push(std::move(tok));
              tokens.pop();
              //std::cout <<"operation"<< std::endl;
             }
        else if (tok->text()==")") 
             {
              while (ops_.top()->text()!="(")
              {
                //std::cout <<"operation"<< std::endl;
                output.push(std::move(ops_.top()));
                ops_.pop();
               if (ops_.empty())
                throw std::runtime_error ("the right doesn't match the left");
              }
              //std::cout <<"what happen"<< std::endl;
             
              ops_.pop();
              tokens.pop();
    
             }

        }


        else if (tok->type()==token_type::NUMBER)  
          {
             //std::cout <<"number"<< std::endl;
               
             output.push(std::move(tok)); 
             tokens.pop();  
              if (!tokens.empty())
             {if (tokens.front()->type()==token_type::NUMBER)
            {
             throw std::runtime_error("two consecutive number!");
             }}

           /** if (tokens.empty()) 
             {}**/  
          } 
 
        /// @todo handle the token
        
    }
   std::cout <<"what"<< std::endl;
       while (!ops_.empty())
    {if (ops_.top()->text()=="(")
      throw std::runtime_error ("problem of parathesis!");
     output.push(std::move(ops_.top()));
     ops_.pop(); 
    }
       while (!output.empty())  //calculation 
    {auto& q=output.front();
      if (q->type()==token_type::NUMBER)
         {nodes_.push(cs225::make_term(q->as_number()->value()));
            std::cout << "head: " << q->as_number()->value() << std::endl;
          output.pop();
         }
      else if (q->as_operation()->args()==1)
      {auto& temp=nodes_.top();
      nodes_.pop();
      nodes_.push(cs225::make_unary_op(output.front()->text(),std::move(temp)));
      
      output.pop();
      }

      else 
         {
          auto& right=nodes_.top();     
          nodes_.pop();
          auto& left=nodes_.top();
          nodes_.pop();
             if (q->text()=="+")
  {std::unique_ptr<binary_op>  p{new plus(std::move(left),std::move(right))};
   nodes_.push(std::move(p));} 
    
 else if (q->text()=="-")
   {std::unique_ptr<binary_op> p{new minus(std::move(left),std::move(right))};
    nodes_.push(std::move(p));}
 else if (q->text()=="*")
   {std::unique_ptr<binary_op> p{new times(std::move(left),std::move(right))};
     nodes_.push(std::move(p));}
 else if (q->text()=="/")
   {std::unique_ptr<binary_op> p{new divide(std::move(left),std::move(right))};
     nodes_.push(std::move(p));}
 else 
   {std::unique_ptr<binary_op> p{new exponent(std::move(left),std::move(right))};
     nodes_.push(std::move(p));}
          output.pop();
         }
 
      

        
    }

     return std::move(nodes_.top());

    /// @todo clean up remaining operators
    /// @todo return the root of your tree
}
}
