/*!
 *
 *   (c) 2009-2016 PROJECT <http://www.exemple.org>
 *
 */

#include <path/to/folder/CodingStyle.hpp>

CodingStyle::CodingStyle() {
}

CodingStyle::CodingStyle(const CodingStyle& orig) {
}

CodingStyle::CodingStyle(CodingStyle&& other) {
}

CodingStyle & CodingStyle::operator=(const CodingStyle& other) {
    return *this;
}

CodingStyle& CodingStyle::operator=(CodingStyle&& other) {
    return *this;
}

CodingStyle::~CodingStyle() {
}

void CodingStyle::protectedMethod()
{
    try 
    {
        doSomeStuff();
    } catch (const std::overflow_error& e) {
        // this executes if f() throws std::overflow_error (same type rule)
    } catch (const std::runtime_error& e) {
        // this executes if f() throws std::underflow_error (base class rule)
    } catch (const std::exception& e) {
        // this executes if f() throws std::logic_error (base class rule)
    } catch (...) {
        // this executes if f() throws std::string or int or any other unrelated type
    }
}

void CodingStyle::privateMethod()
{
    Variant typedValue;
    switch (someType()) 
    {
        
    }
}
    