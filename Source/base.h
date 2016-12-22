/*
 * Copyright (c) 2016 Brett g Porter
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above
 * copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS",
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

#include "factoryBuildable.h"
#include "factoryDatabase.h"

/**
 * @class Base
 * @brief A simple demo class for the class factory system. 
 *
 * The 3 methods:
 * - `SetTypeName()``
 * - `RegisterFactory()`
 * - `Create()` 
 *
 * must be present in the base of a class that is to be created using this 
 * class factory system. 
 */
class Base : public FactoryBuildable<Base>
{
public:
   /**
    * The classes created by our factory need to be default-constructable.
    */
   Base();
   
   virtual ~Base();
   


   ///@{
   /**
    * @name Simple demo methods overridden in derived classes.
    */

   /**
    * Perform some sort of arithmetic operation.
    * @param  input input value  .
    * @return       Output value. 
    */
   virtual int SomeIntOperation(int input) = 0;
   
   /**
    * Perform some sort of operation on a string. 
    * @param  s Input string.
    * @return   Output string. 
    */
   virtual String SomeStringOperation(const String& s) = 0;
   
   ///@}

private:

   String fTypeName;
   
   JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Base)
};



#endif  // BASE_H_INCLUDED
