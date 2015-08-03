/**
 * @file circ_array.h
 * @author Chase Geigle
 * @date Summer 2014
 */

#include <stdexcept>
#include "circ_array.h"
#include <cassert>
#include <utility>
//#include "dl_list.h"
#include <iostream>
#include <math.h>
#include <list>
#include <vector>
#include <memory>
//#include "rgba_pixel.h"

namespace cs225
{

template <class T>
circ_array<T>::circ_array()
{
    arr_=nullptr;
    t=nullptr;
    size_=0;
    capacity=0;
    head=0;
    tail=0;
    /// @todo mp_parse.1
}

template <class T>
circ_array<T>::circ_array(uint64_t size)
//arr_{new std::unique_ptr<T[]>[size]}
    //t{new std::unique_ptr<bool>[size]}
{
  /** arr_=nullptr;
      T* pointer=new T[size];
   
   std::unique_ptr<T[]> temp{pointer};
   arr_.swap(temp);**/
   std::unique_ptr<T[]> temp{new T[size]};
   std::unique_ptr<bool[]> temp2{new bool[size]};
   arr_.swap(temp);
   t.swap(temp2);
   //arr_{new T[size]};
    //t=new std::unique_ptr<bool>[size];
    for (uint64_t i=0;i<size;i++)
      {//arr_[i]=0;
       t[i]=true;}
    size_=size;
   capacity=size;
    head=0;
    tail=size-1;

    /// @todo mp_parse.1
}

template <class T>
circ_array<T>::circ_array(const circ_array& other)
{
   /**if (other==nullptr)
     return;**/ 

   /**T* pointer=new T[other.capacity];
   for (uint64_t i=0;i<other.capacity;i++)
   {pointer[i]=other[i];

    }
   std::unique_ptr<T[]> temp{pointer};
   arr_.swap(temp);**/
   std::unique_ptr<T[]> temp{new T[other.capacity]};
   arr_.swap(temp);
   std::unique_ptr<bool[]> temp2{new bool[other.capacity]};
   t.swap(temp2);
   //arr_=new std::unique_ptr<T[]>[other.capacity];
   
   capacity=other.capacity;
   size_=other.size_;
   head=other.head;
   tail=other.tail;
   for (uint64_t i=0;i<capacity;i++ )
       {arr_[i]=other.arr_[i];
       t[i]=other.t[i];
       }
    /// @todo mp_parse.1
}

template <class T>
circ_array<T>::circ_array(circ_array&& other)
{   
   std::unique_ptr<T[]> temp{new T[other.capacity]};
   arr_.swap(temp);
   std::unique_ptr<bool[]> temp2{new bool[other.capacity]};
   t.swap(temp2);
   //arr_=new std::unique_ptr<T[]>[other.capacity];
   

   size_=0;

   for (uint64_t i=0;i<capacity;i++ )
       {std::swap(arr_[i],other.arr_[i]);
       std::swap(t[i],other.t[i]);
       }

   std::swap(size_,other.size_);
    /**for (uint64_t i=0;i<other.capacity;i++)
       {arr_[i]=other[i];
       t[i]=other[i];**/
    //arr_.swap(other);
   /**for (uint64_t i=0;i<other.arrlength;i++ )
       other[i]=nullptr;**/
   
     //other.arr_=nullptr;
     //other.t=nullptr;
     other.size_=0;
     
     //other.t=nullptr;
     /// @todo mp_parse.1
}

template <class T>
circ_array<T>& circ_array<T>::operator=(circ_array rhs)
{
    swap(rhs);
//arrlength=rhs.arrlength;
return *this;
/// @todo mp_parse.1
}

template <class T>
circ_array<T>::~circ_array() = default;

template <class T>
void circ_array<T>::swap(circ_array& other)
{
     std::unique_ptr<T[]> temp{new T[other.capacity]};
   
   std::unique_ptr<bool[]> temp2{new bool[other.capacity]};
   


  for (uint64_t i=0;i<other.capacity;i++)
       {temp[i]=other.arr_[i];
        //std::cout <<"test_move"<<i<< std::endl;
        temp2[i]=other.t[i];
      }
std::unique_ptr<T[]> temp3{new T[capacity]};
   
   std::unique_ptr<bool[]> temp4{new bool[capacity]};
  for (uint64_t i=0;i<capacity;i++)
       {temp3[i]=arr_[i];
        //std::cout <<"test_move"<<i<< std::endl;
        temp4[i]=t[i];
      }
   std::swap(arr_,temp);
   std::swap(t,temp2);
   std::swap(other.arr_,temp3);
   std::swap(other.t,temp4);
   std::swap(capacity,other.capacity);
   std::swap(size_,other.size_);
   std::swap(head,other.head);
   std::swap(tail,other.tail);
  


 /// @todo mp_parse.1
}

template <class T>
const T& circ_array<T>::operator[](uint64_t idx) const
{
  uint64_t i=0;
  uint64_t j=0;
  //int i=-1;
 if (idx>=capacity)
   throw std::out_of_range("out of range!");
  if (head==0)
    {
  for (;j<idx+1;)
     {
      if (t[i]==true) j++;  
      if (idx+1!=j) i++;
     }
    return arr_[i];
    }
  else 
     {//i=head;
      //std::cout <<head<< std::endl;
      if (head+idx<capacity)
       {
        return arr_[head+idx];} 
       
    std::cout << "hello: " << arr_[head-capacity+idx-2] << std::endl;
       return arr_[head-capacity+idx-2]; }
    /// @todo mp_parse.1
}

template <class T>
T& circ_array<T>::operator[](uint64_t idx)
{
 



  uint64_t i=0;
  uint64_t j=0;
  //int i=-1;
 if (idx>=capacity)
   throw std::out_of_range("out of range!");
  if (head==0)
    {
  for (;j<idx+1;)
     {
      if (t[i]==true) j++;  
      if (idx+1!=j) i++;
     }
    return arr_[i];
    }
  else 
     {//i=head;
      //std::cout <<head<< std::endl;
      if (head+idx<capacity)
       {
        //std::cout <<arr_[0]<< std::endl;
        return arr_[head+idx];} 
   //std::cout << "hello: " << arr_[head-capacity+idx-2] << std::endl;
       return arr_[head-capacity+idx-2]; }
  /** uint64_t i=0;
  uint64_t j=0;
  //int i=-1;
 if (idx>=capacity)
   throw std::out_of_range("out of range!");
  if (head==0)
    { for (;j<idx+1;)
     {
      if (t[i]==true) j++;  
      if (idx+1!=j) i++;
     }
    return arr_[i];
    }
  else 
     {i=head;
        for (;j<idx+1&&i<capacity;)
         {
           if (t[i]==true)
           j++;
           if (idx+1!=j) i++;
         }
      if (j==idx) return arr_[i];
      i=0;
     for (;j<idx+1;)
       {
        if (t[i]==true)
           j++;
           if (idx+1!=j) i++;
       }
      return arr_[i];

     }
**/
    /// @todo mp_parse.1
}

template <class T>
const T& circ_array<T>::at(uint64_t idx) const
{
  uint64_t i=0;
  uint64_t j=0;
  //int i=-1;
 if (idx>=capacity)
   throw std::out_of_range("out of range!");
  if (head==0)
    {
  for (;j<idx+1;)
     {
      if (t[i]==true) j++;  
      if (idx+1!=j) i++;
     }
    return arr_[i];
    }
  else 
     {i=head;
     
      std::cout <<head<< std::endl;
      if (head+idx<capacity)
       {std::cout <<head+idx<< std::endl;
        std::cout <<arr_[0]<< std::endl;
        return arr_[head+idx];} 
        std::cout << "hello: " << arr_[head-capacity+idx-2] << std::endl;  
       return arr_[head-capacity+idx-2]; }
    /// @todo mp_parse.1
}

template <class T>
T& circ_array<T>::at(uint64_t idx)
{
  uint64_t i=0;
  uint64_t j=0;
  //int i=-1;
 if (idx>=capacity)
   throw std::out_of_range("out of range!");
  if (head==0)
    {
  for (;j<idx+1;)
     {
      if (t[i]==true) j++;  
      if (idx+1!=j) i++;
     }
    return arr_[i];
    }
  else 
     {
      if (head+idx<capacity)
       {
        return arr_[head+idx];} 
  //std::cout << "hello: " << arr_[head-capacity+idx-2] << std::endl;
       return arr_[head-capacity+idx-2]; }
  

     
    /// @todo mp_parse.1
}

template <class T>
void circ_array<T>::push_front(const T& elem)
{size_++;
    if (size_-1==capacity)
    {if (capacity==0)
     { capacity++;
        std::unique_ptr<T[]> temp{new T[capacity]};
        std::unique_ptr<bool[]> temp2{new bool[capacity]}; 
        head=0;
        tail=0;
        temp[0]=elem;
        temp2[0]=true;
        arr_.swap(temp);
        t.swap(temp2);

     }

    else 
    {std::unique_ptr<T[]> temp{new T[2*capacity]};
      std::unique_ptr<bool[]> temp2{new bool[2*capacity]}; 
     
      //temp_.swap(temp);
      //std::unique_ptr<T[]> temp=new std::unique_ptr<T[]>[2*capacity];
      uint64_t j=1;      
      temp[0]=elem;
      temp2[0]=true;
      //temp2[0]=true;
      for (uint64_t i=head;i<capacity;i++)
         {if (t[i]==true)
          {temp[j]=arr_[i];
           temp2[j]=true;
           j++;
          }
         }
           //temp2[i]=t[head+i-1];}
      for (uint64_t i=0;i<head;i++)
          {
           if (t[i]==true)
           {temp[j]=arr_[i];
            temp2[j]=true;
            j++;
           }
           
           //temp2[capacity-head-1+i]=t[i];
          }
      //temp[capacity]=elem;
      //temp2[capacity]=true;
      for (;j<2*capacity-1;j++)
         {
        
           temp2[j]=false;;
         }
      
      arr_.swap(temp);
      t.swap(temp2);
      //t.swap(temp2);
      head=0;
      tail=capacity;
      capacity=capacity*2;
      
     }
}
    else if (t[head]==false)
       {
        
        arr_[head]=elem;
        t[head]=true;
       }
     
     else if (head!=0)
      {head--;
       arr_[head]=elem;
       t[head]=true;
       //t[head]=true;
     }
     else if (head==0)
     {
       head=capacity-1;
       arr_[head]=elem;
       t[head]=true;
       //t[head]=true;
     }
    /// @todo mp_parse.1
}


template <class T>
void circ_array<T>::push_front(T&& elem)
{size_++;
    if (size_-1==capacity)
    {if (capacity==0)
     { capacity++;
        std::unique_ptr<T[]> temp{new T[capacity]};
        std::unique_ptr<bool[]> temp2{new bool[capacity]}; 
        head=0;
        tail=0;
        temp[0]=std::move(elem);
        temp2[0]=true;
        arr_.swap(temp);
        t.swap(temp2);

     }

    else 
    {std::unique_ptr<T[]> temp{new T[2*capacity]};
      std::unique_ptr<bool[]> temp2{new bool[2*capacity]}; 
     
      //temp_.swap(temp);
      //std::unique_ptr<T[]> temp=new std::unique_ptr<T[]>[2*capacity];
      uint64_t j=1;      
      temp[0]=std::move(elem);
      temp2[0]=true;
      //temp2[0]=true;
      for (uint64_t i=head;i<capacity;i++)
         {if (t[i]==true)
          {temp[j]=std::move(arr_[i]);
           temp2[j]=true;
           j++;
          }
         }
           //temp2[i]=t[head+i-1];}
      for (uint64_t i=0;i<head;i++)
          {
           if (t[i]==true)
           {temp[j]=std::move(arr_[i]);
            temp2[j]=true;
            j++;
           }
           
           //temp2[capacity-head-1+i]=t[i];
          }
      //temp[capacity]=elem;
      //temp2[capacity]=true;
      for (;j<2*capacity-1;j++)
         {
        
           temp2[j]=false;;
         }
      
      arr_.swap(temp);
      t.swap(temp2);
      //t.swap(temp2);
      head=0;
      tail=capacity;
      capacity=capacity*2;
      
     }
}

    else if (t[head]==false)
       {
        
        arr_[head]=std::move(elem);
        t[head]=true;
       }
     
     else if (head!=0)
      {head--;
       arr_[head]=std::move(elem);
       t[head]=true;
       //t[head]=true;
     }
     else if (head==0)
     {
       head=capacity-1;
       arr_[head]=std::move(elem);
       t[head]=true;
       //t[head]=true;
     }
    /// @todo mp_parse.1
}


template <class T>
void circ_array<T>::push_back(const T& elem)
{
   std::cout <<"number"<< std::endl; 
   size_++;


    if (size_-1==capacity)
      {if (capacity==0)
     { capacity++;
        std::unique_ptr<T[]> temp{new T[capacity]};
        std::unique_ptr<bool[]> temp2{new bool[capacity]}; 
        head=0;
        tail=0;
        temp[0]=elem;
        temp2[0]=true;
        arr_.swap(temp);
        t.swap(temp2);

     }
     else { std::unique_ptr<T[]> temp{new T[2*capacity]};
      std::unique_ptr<bool[]> temp2{new bool[2*capacity]};
      uint64_t j=0;
      
      for (uint64_t i=head;i<capacity;i++)
          {
           if (t[i]==true)
          {temp[j]=arr_[i];
           temp2[j]=true;
           j++;
          }
          
           }//temp2[i]=t[head+i];}
      for (uint64_t i=0;i<head;i++)
          {if (t[i]==true)
          {temp[j]=arr_[i];
           temp2[j]=true;
           j++;
          }
           //temp2[i]=t[i];
          }

      
 for (;j<2*capacity-1;j++)
         {
        
           temp2[j]=false;;
         }
     
     temp[capacity]=elem;
      temp2[capacity]=true;
      
      arr_.swap(temp);
      t.swap(temp2);
      //t.swap(temp2);
      head=0;
      tail=capacity;
      
      capacity=capacity*2;
      
     }
  }


    else if (t[tail]==false)
       {
        
        arr_[tail]=elem;
        t[tail]=true; 
        }
     
     else if (tail<capacity-1)
      {tail++;
       arr_[tail]=elem;
       t[tail]=true;
       //t[tail]=true;
     }
     else if (tail==capacity-1)
     {
       tail=0;
       arr_[tail]=elem;
       t[0]=true;
       //t[tail]=true;
     }

    /// @todo mp_parse.1
}

template <class T>
void circ_array<T>::push_back(T&& elem)
{
  std::cout <<"number"<< std::endl;
    size_++;
   
    if (size_-1==capacity)
      {if (capacity==0)
     { capacity++;
        std::unique_ptr<T[]> temp{new T[capacity]};
        std::unique_ptr<bool[]> temp2{new bool[capacity]}; 
        head=0;
        tail=0;
        temp[0]=std::move(elem);
        temp2[0]=true;
        arr_.swap(temp);
        t.swap(temp2);

     }
     else { std::unique_ptr<T[]> temp{new T[2*capacity]};
      std::unique_ptr<bool[]> temp2{new bool[2*capacity]};
      uint64_t j=0;
      
      for (uint64_t i=head;i<capacity;i++)
          {
           if (t[i]==true)
          {temp[j]=std::move(arr_[i]);
           temp2[j]=true;
           j++;
          }
          
           }//temp2[i]=t[head+i];}
      for (uint64_t i=0;i<head;i++)
          {if (t[i]==true)
          {temp[j]=std::move(arr_[i]);
           temp2[j]=true;
           j++;
          }
           //temp2[i]=t[i];
          }

      
 for (;j<2*capacity-1;j++)
         {
        
           temp2[j]=false;;
         }
      
      temp[capacity]=std::move(elem);
      temp2[capacity]=true; 
    
      
      arr_.swap(temp);
      t.swap(temp2);
      //t.swap(temp2);
      head=0;
      tail=capacity;
      t[capacity]=true;
      
      capacity=capacity*2;
      
     }
}

    else if (t[tail]==false)
       {
        
        arr_[tail]=std::move(elem);
        t[tail]=true; 
        }
     
     else if (tail<capacity-1)
      {tail++;
       arr_[tail]=std::move(elem);
       t[tail]=true;
       //t[tail]=true;
     }
     else if (tail==capacity-1)
     {
       tail=0;
       arr_[tail]=std::move(elem);
       t[0]=true;
       //t[tail]=true;
     }

    /// @todo mp_parse.1
}

template <class T>
void circ_array<T>::pop_front()
{
   if (size_==0) return;
   size_--;
   t[head]=false;
   
   if (head!=capacity-1)
   head++;
   else
   head=0;
    ; 
   
    /// @todo mp_parse.1
}

template <class T>
uint64_t circ_array<T>::head_() const
{
  return tail;
}

template <class T>
void circ_array<T>::pop_back()
{ 
  if (size_==0) return;
  t[tail]=false;
  size_--;
  //arr_[tail]=999;
  if (tail==0)
    tail=capacity-1;
  else tail--;
    /// @todo mp_parse.1
}

template <class T>
void circ_array<T>::erase(uint64_t idx)
{
  size_--;
  /**std::cout <<" which one"<<arr_[idx+head]<< std::endl;
  std::cout <<" head::"<<head<< std::endl;
std::cout <<" TORF"<<t[6]<< std::endl;**/
  if (head+idx<capacity)
  t[idx+head]=false;
  else t[head-capacity+idx-2]=false;
  std::cout <<" TORF"<<t[idx+head]<< std::endl;
  std::unique_ptr<T[]> temp{new T[capacity-1]};
      std::unique_ptr<bool[]> temp2{new bool[capacity-1]};
      uint64_t j=0;
      
      for (uint64_t i=head;i<capacity;i++)
          {
           if (t[i]==true)
          {temp[j]=arr_[i];
std::cout <<"this is"<<temp[j]<< std::endl;
           temp2[j]=true;
           j++;
          }
          
           }//temp2[i]=t[head+i];}
        std::cout <<" j is"<<j<< std::endl;
      for (uint64_t i=0;i<head;i++)
          {if (t[i]==true)
          {temp[j]=arr_[i];
           temp2[j]=true;
           j++;
          }
           //temp2[i]=t[i];
          }

      std::cout <<" j is"<<j<< std::endl;
      for (;j<capacity-1;j++)
         {
         temp[j]=false;
         }
      std::cout <<" j is"<<j<< std::endl;
      arr_.swap(temp);
      t.swap(temp2);
      //t.swap(temp2);
      head=0;
      tail=size_-1;
 std::cout <<"??? "<<arr_[0]<< std::endl;
     std::cout <<"??? "<<arr_[1]<< std::endl;
     std::cout <<"??? "<<arr_[2]<< std::endl;
      capacity--;
 /// @todo mp_parse.1
}

/**template <class T>
uint64_t circ_array<T>::head()
{uint64_t i=0;
 while (arr_[i]!=nullptr)
   i++;
 return i;
}

template <class T>
uint64_t circ_array<T>::tail()
{uint64_t i=arrlength-1;
 while (arr_[i]!=nullptr)
   i--;
 return i;
}**/
template <class T>
uint64_t circ_array<T>::size() const
{/**uint64_t j=0;
   for (uint64_t i=0;i<capacity;i++)
     {if (arr_[i]!=999)
      j++;
      }**/
   return size_; /// @todo mp_parse.1
}

template <class T>
bool circ_array<T>::empty() const
{
   return (size_==0); 
   //for (uint64_t i=0;i<size();i++)
/**{
 if (arr_[i]!=nullptr) return true;
}
return false;**/

 /// @todo mp_parse.1
}
}
