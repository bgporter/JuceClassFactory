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

#ifndef FACTORYDATABASE_H_INCLUDED
#define FACTORYDATABASE_H_INCLUDED

#include "factory.h"

/**
 * @class FactoryDatabase
 *
 * @brief A class that lets lets us associate Node classes with a name that 
 *        can be used to instantiate them at runtime.
 *
 * Some interesting and probably non-obvious code in this one. The issue that we
 * run into here is that we want each of the Node classes to register itself
 * with the single static instance of this class so that we can then create it. 
 * We want this registration to happen before the execution of `main()`, but 
 * we immediately run into the problem that the order of initialization between
 * different translation units is undefined behavior, so it's possible (and in
 * fact likely or almost certain) that the Node classes will try to register
 * themselves before the map of names to factory functions has been created. 
 *
 * **Boom.** 
 *
 * We use an approach here know variously as a 'nifty counter' or 
 * 'Schwarz counter' which you can Google as well as I did. Short version is 
 * that we make use of some guaranteed aspects of static variables declared
 * in header files to ensure that the database here is ready to go before anyone
 * attempts to actually use it. 
 *
 * Any cpp file that includes this will have a static instance of this class 
 * brought in (but the ctor/dtor only do anything on their first/last entrance/
 * exit)
 *
 * See the NodeFactoryDatabase instantiation for an example.
 */


template <class Base>
class FactoryDatabase
{
public:
   FactoryDatabase()
   {
      if (0 == fCount++)
      {
         fDatabase = new HashMap<String, BaseFactory<Base>* >();
      }
   }
   ~FactoryDatabase()
   {
      if (0 == --fCount)
      {
         delete fDatabase;
         fDatabase = nullptr;
      }
   }
   
   /**
    * Register a Node Factory object with a name that can be used to create 
    * Node objects at run time. 
    * @param name    name of the class to use when creating one (not necessarily
    *                the same as the actual C++ class name)
    * @param factory Pointer to a NodeFactory object that will return an instance
    *                of the Node class.
    */
   static void RegisterFactory(StringRef name, BaseFactory<Base>* factory)
   {
      jassert(fDatabase);
      DBG("Registering factory for " << name);
      fDatabase->set(name, factory);
   }   
   /**
    * Create a Node object using its name.
    * @param  name Typename of the class you'd like to create.
    * @return      A pointer to the object if we have a registered factory
    *              object that knows how to make it, or `nullptr`.
    */    
   static Base* Create(StringRef name)
   {
      Base* retval = nullptr;
      BaseFactory<Base>* factory = (*fDatabase)[name];
      if (factory)
      {
         retval = factory->Create();
      }
      return retval;
   }
   
   
protected:
   static int fCount;
   static HashMap<String, BaseFactory<Base>* >* fDatabase;
};



#endif  // FACTORYDATABASE_H_INCLUDED
