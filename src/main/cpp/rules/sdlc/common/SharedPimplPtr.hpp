
/*!**************************************************************************
**
** Copyright (C) 2009 TECHNOGERMA Systems France and/or its subsidiary(-ies).
** Contact: Technogerma Systems France Information (contact@technogerma.fr)
**
** This file is part of the GICS library.
**
** Commercial Usage
** Licensees holding valid GICS Commercial licenses may use this file in
** accordance with the GICS Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and TECHNOGERMA Systems France.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL3.txt included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at sales@technogerma.fr.
**
****************************************************************************/

// <insert copyright>

#ifndef RULES_SDLC_STDC_SHAREDPIMPLPTR_HPP
#define RULES_SDLC_STDC_SHAREDPIMPLPTR_HPP

#include <boost/shared_ptr.hpp>

#include <cassert>
#include <memory>

namespace rules::sdlc::stdc
{
/*!
 * @brief Smart pointer implementing the pimpl idiom with a sharing stategy
 *
 * See PimplPtr documentation for a complete explanation and example about the
 * pimpl idiom and how to use pimpl pointers.
 *
 * Unlike PimplPtr, SharedPimplPtr shares its private implementations when its copied, using a
 * reference counting strategy. This has the benefits of reducing the memory consumption,
 * as well as enabling Copy-On-Write.
 *
 * Example:
 *
 * @code
 * class MyClass
 * {
 * public:
 *
 *     int get() const;
 *     void set(int x);
 *
 * private:
 *
 *     goost::SharedPimplPtr<struct MyClassPrivate> d;
 * };
 * @endcode
 *
 * @code
 * #include <myclass.hpp>
 *
 * struct MyClassPrivate
 * {
 *     int x;
 * };
 *
 * int MyClass::get() const
 * {
 *     return d->x;
 * }
 *
 * void MyClass::set(int x)
 * {
 *     d.unique(); // duplicate if it was previously shared
 *     d->x = x;
 * }
 * @endcode
 */
template < typename T >

class SharedPimplPtr
{
public:
    /*!
     * @brief Default constructor
     *
     * This constructor initializes the data with a new default constructed instance of T
     */
    SharedPimplPtr ( );

    /*!
     * @brief Construct the pimpl pointer from an instance of the private implementation
     *
     * This constructor takes the ownership of @a data
     *
     * @param data Instance of the private implementation to use
     */
    explicit SharedPimplPtr ( T * data );

    /*!
     * @brief Construct the pimpl pointer from a parameter
     *
     * This constructor directly forwards the argument to the constructor of T
     *
     * @param arg1 Argument to pass to the implementation
     */
    template < typename T1 >
    SharedPimplPtr ( T1 arg1 );

    /*!
     * @brief Construct the pimpl pointer from two parameters
     *
     * This constructor directly forwards the arguments to the constructor of T
     *
     * @param arg1 First argument to pass to the implementation
     * @param arg2 Second argument to pass to the implementation
     */
    template < typename T1, typename T2 >
    SharedPimplPtr ( T1 arg1, T2 arg2 );

    /*!
     * @brief Construct the pimpl pointer from three parameters
     *
     * This constructor directly forwards the arguments to the constructor of T
     *
     * @param arg1 First argument to pass to the implementation
     * @param arg2 Second argument to pass to the implementation
     * @param arg3 Third argument to pass to the implementation
     */
    template < typename T1, typename T2, typename T3 >
    SharedPimplPtr ( T1 arg1, T2 arg2, T3 arg3 );

    /*!
     * @brief Overload of -> operator for accessing the private implementation (non-const version)
     *
     * @return Non-const pointer to the private implementation
     */
    T *
        operator-> ( );

    /*!
     * @brief Overload of -> operator for accessing the private implementation (const version)
     *
     * @return Const pointer to the private implementation
     */
    const T *
        operator-> ( ) const;

    /*!
     * @brief Overload of * operator for accessing the private implementation (non-const version)
     *
     * @return Non-const reference to the private implementation
     */
    T &
        operator* ( );

    /*!
     * @brief Overload of * operator for accessing the private implementation (const version)
     *
     * @return Const reference to the private implementation
     */
    const T &
        operator* ( ) const;

    /*!
     * @brief Swap the data of two SharedPimplPtr instances
     *
     * @param other SharedPimplPtr instance to swap contents with
     */
    void
        swap ( SharedPimplPtr< T > & other );

    /*!
     * @brief Ensure that the private implementation is no longer shared with other SharedPimplPtr instances
     *
     * This function checks the reference counter: if it's more than 1, it creates a new implementation which
     * is a deep copy of the previous one
     */
    void
        unique ( );

private:
    /*!
     * @brief Assignment is disabled, once constructed a SharedPimplPtr cannot point to another implementation
     */
    SharedPimplPtr< T > &
        operator= ( const SharedPimplPtr< T > & );

private:
    std::shared_ptr< T > m_data;     ///< Pointer to the instance of the private implementation
};

}

#include <rules/sdlc/common/SharedPimplPtr.inl>

#endif
