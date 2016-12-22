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

#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


/**
 * @class BaseFactory
 * @brief factory abstract base class that defines its API and is templated on the 
 *        base class of the type that its factories are meant to instantiate.
 *        Actual factory classes will use the below Factory<Base, Derived> 
 *        version that's defined immediately below.
 */
template <class T>
class BaseFactory
{
public:
   /**
    * @param name The name of the 'type' of object that this factory can create.
    */   
   BaseFactory(StringRef typeName)
   :  fTypeName(typeName)
   {
      T::RegisterFactory(typeName, this );
   }
   
   virtual ~BaseFactory() = default;
   
   virtual T* Create() = 0;
   
protected:
   /// the 'type name' for classes created by this factory, which may or
   /// may not be the same as the C++ name of the classes created by this
   /// factory.
   String fTypeName;  
   
   JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BaseFactory); 
};



template <class T, class Derived>
class Factory : public BaseFactory<T>
{
public:
   Factory(StringRef typeName)
   :  BaseFactory<T>(typeName)
   {
      // compile time assertion to make sure that there's a valid 
      // base/derived relationship between the two classes that this 
      // factory is templated on.
      static_assert(std::is_base_of<T, Derived>::value, "");
   }
   
   ~Factory() = default;
   
   T* Create() override
   {
      T* retval = new Derived();
      if (retval)
      {
         retval->SetTypeName(BaseFactory<T>::fTypeName);
      }
      return retval;
   }
private:
};


#endif  // FACTORY_H_INCLUDED
