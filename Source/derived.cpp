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

#include "derived.h"
#include "factory.h"

namespace
{
   // here in an anonymous namespace, we create an instance of the 
   // appropriate Factory type for each of the derived classes we wish to 
   // be able to create through the `Base::Create("someType")` interface. 
   // Creating these has as a side effect the registration of the factory 
   // classes in the factory database object, so there's nothing else to do
   // for these factories to be usable. 
   Factory<Base, Unity>    unityFactory("unity");
   Factory<Base, Smaller>  smallerFactory("smaller");
   Factory<Base, Bigger>   biggerFactory("bigger");
};



int Unity::SomeIntOperation(int input)
{
   return input;
}

String Unity::SomeStringOperation(const String& s)
{
   return s;
} 



int Smaller::SomeIntOperation(int input)
{
   return input - 1;
}

String Smaller::SomeStringOperation(const String& s)
{
   return s.toLowerCase();
} 



int Bigger::SomeIntOperation(int input)
{
   return input + 1;
}

String Bigger::SomeStringOperation(const String& s)
{
   return s.toUpperCase();
} 
