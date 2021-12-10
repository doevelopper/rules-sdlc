
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

#ifndef RULES_SDLC_STDC_PIMPLPTR_HPP
#define RULES_SDLC_STDC_PIMPLPTR_HPP

#include <boost/shared_ptr.hpp>

#include <cassert>
#include <memory>
#include <type_traits>

namespace rules::sdlc::stdc
{
/*!
 * @brief Smart pointer implementing the pimpl idiom
 *
 * The pimpl idiom is a well-known pattern in C++ which allows to hide all the private
 * details of a class in its corresponding .cpp file, thus ensuring that only the public API
 * of the class is visible to the end user.
 *
 * PimplPtr wraps all the operations needed to implement this idiom.
 * It is a smart pointer class, and thus it has the standard pointer semantics.
 *
 * The default policy when copying a PimplPtr instance is to duplicate the underlying
 * data. When the PimplPtr is destroyed, the underlying data is destroyed as well.
 *
 * PimplPtr forwards constness to the underlying private implementation, which means that
 * the pointed data won't be editable in const functions of the owner object,
 * just like regular members.
 *
 * The template parameter T is the type of the private implementation.
 *
 * @remark This class internally uses boost::shared_ptr instead of a raw pointer,
 * because boost::shared_ptr is multi-thread safe and allows T to be incomplete.
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
 *     cfs::utils::PimplPtr<struct MyClassPrivate> d;
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
 *     d->x = x;
 * }
 * @endcode
 */
template < typename T >

class PimplPtr
{
public:
    /*!
     * @brief Default constructor
     *
     * This constructor initializes the data with a new default constructed instance of T
     */
    PimplPtr ( );
    /*!
     * @brief destructor
     */
    ~PimplPtr ( );

    /*!
     * @brief Construct the pimpl pointer from an instance of the private implementation
     *
     * This constructor takes the ownership of @a data
     *
     * @param data Instance of the private implementation to use
     */
    explicit PimplPtr ( T * data );

    /*!
     * @brief Copy constructor
     *
     * This constructor creates a new instance of the private implementation, which is
     * a deep copy of the source implementation
     *
     * @param copy Instance to copy
     */
    PimplPtr ( const PimplPtr< T > & copy );

    /*!
     * @brief Construct the pimpl pointer from a parameter
     *
     * This constructor directly forwards the argument to the constructor of T
     *
     * @param arg1 Argument to pass to the implementation
     */
    template < typename T1 >
    PimplPtr ( T1 arg1 );

    /*!
     * @brief Construct the pimpl pointer from two parameters
     *
     * This constructor directly forwards the arguments to the constructor of T
     *
     * @param arg1 First argument to pass to the implementation
     * @param arg2 Second argument to pass to the implementation
     */
    template < typename T1, typename T2 >
    PimplPtr ( T1 arg1, T2 arg2 );

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
    PimplPtr ( T1 arg1, T2 arg2, T3 arg3 );

    /*!
     * @brief Overload of -> operator for accessing the private implementation (non-const version)
     *
     * @return Non-const pointer to the private implementation
     */
    T *
        operator-> ( ) noexcept;

    /*!
     * @brief Overload of -> operator for accessing the private implementation (const version)
     *
     * @return Const pointer to the private implementation
     */
    const T *
        operator-> ( ) const noexcept;

    /*!
     * @brief Overload of * operator for accessing the private implementation (non-const version)
     *
     * @return Non-const reference to the private implementation
     */
    T &
        operator* ( ) noexcept;

    /*!
     * @brief Overload of * operator for accessing the private implementation (const version)
     *
     * @return Const reference to the private implementation
     */
    const T &
        operator* ( ) const noexcept;

    /*!
     * @brief Swap the data of two PimplPtr instances
     *
     * @param other PimplPtr instance to swap contents with
     */
    void
        swap ( PimplPtr< T > & other );

    //
    // Agregation initialization
    // SFINAE trick to not confuse with copy constructor
    //
    /*
                template <typename U, typename = typename std::enable_if< !std::is_same<PimplPtr, U>::value,
       void>::type> explicit PimplPtr(U&& u);

                template <typename T1, typename T2, typename ...Args>
                PimplPtr(T1&& a1, T2&& a2, Args&&... args);
     */

private:
    /*!
     * @brief Assignment is disabled, once constructed a PimplPtr cannot point to another implementation
     */
    PimplPtr< T > &
                         operator= ( const PimplPtr< T > & );
    std::shared_ptr< T > m_data;     ///< Pointer to the instance of the private implementation
};

}     // namespace cfs::utils

#include <rules/sdlc/std/PimplPtr.inl>

#endif
