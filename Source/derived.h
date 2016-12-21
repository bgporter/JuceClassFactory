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

#ifndef DERIVED_H_INCLUDED
#define DERIVED_H_INCLUDED

#include "base.h"


/**
 * @class Unity
 *
 * @brief NULL-filter class -- any inputs to its methods are returned without
 *        alteration.
 */
class Unity : public Base 
{
public:
   Unity() {};
   
   ~Unity() {};

   /**
    * Do nothing to the input and return it. 
    * @param  input an integer
    * @return       The same integer that was passed in.
    */
   int SomeIntOperation(int input) override;
   
   /**
    * Do nothing to the string and return it.
    * @param  s a string
    * @return   the string, unaltered.
    */
   String SomeStringOperation(const String& s) override;
   
};


/**
 * @class Smaller
 * @brief A class that returns a 'smaller' version of its inputs, whatever 
 *        that may mean.
 */
class Smaller  : public Base 
{
public:
   Smaller() {};
   
   ~Smaller() {};
   
   /**
    * Make the input integer smaller.
    * @param  input integer to process.
    * @return       input - 1
    */
   int SomeIntOperation(int input) override;
   
   /**
    * Make the input string 'smaller'
    * @param  s String to process
    * @return   a lowercase copy of the input string.
    */
   String SomeStringOperation(const String& s) override;
   
};

class Bigger : public Base 
{
public:
   Bigger() {};
   
   ~Bigger() {};
   
   /**
    * Make the input integer Bigger
    * @param  input integer to process
    * @return       input+ 1
    */
   int SomeIntOperation(int input) override;
   
   /**
    * Make the input string 'bigger'
    * @param  s String to process
    * @return   upper-case version of the input string.
    */
   String SomeStringOperation(const String& s) override;
   
};

#endif  // DERIVED_H_INCLUDED
