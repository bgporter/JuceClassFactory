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

#include "../JuceLibraryCode/JuceHeader.h"

#include "base.h"


/**
 * @class FactoryTest
 * @brief Simple unit tests to verify that the class factory system is 
 *        working correctly.
 */
class FactoryTest : public UnitTest 
{
public:
   FactoryTest() : UnitTest("Class Factory Tests")
   {
   }
   
   void runTest() override
   {
      beginTest("object creation");
      // things that should be created...
      ScopedPointer<Base> unity = Base::Create("unity");
      expect(nullptr != unity);
      
      ScopedPointer<Base> smaller = Base::Create("smaller");
      expect(nullptr != smaller);
      
      ScopedPointer<Base> bigger = Base::Create("bigger");
      expect(nullptr != bigger);
      
      // we don't know about the imaginary type, so we should get
      // a NULL Pointer back from the Create() call.
      ScopedPointer<Base> notThere = Base::Create("imaginary");
      expect(nullptr == notThere);
      
      
      beginTest("Integer operations");
      // Verify that the 3 objects we've created are of the 
      // correct type by exercising their API.
      expect(100 == unity->SomeIntOperation(100));
      expect(99 == smaller->SomeIntOperation(100));
      expect(101 == bigger->SomeIntOperation(100));
      
      beginTest("String operations");
      const String kTestString("ThIs Is A dIfFeReNt StRiNg");
      expect(kTestString == unity->SomeStringOperation(kTestString));
      expect(kTestString.toLowerCase() == smaller->SomeStringOperation(kTestString));
      expect(kTestString.toUpperCase() == bigger->SomeStringOperation(kTestString));
   }
   
};


static FactoryTest test;

//==============================================================================
int main (int argc, char* argv[])
{

   // for demo purposes, just run unit tests and exit the app.
   UnitTestRunner testRunner;
   testRunner.runAllTests();
    

    return 0;
}
