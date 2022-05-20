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

#include <rules/sdlc/std/API_Export.hpp>

namespace rules::sdlc::stdc
{
    template <typename T>
    PimplPtr<T>::PimplPtr()
        : m_data(new T)
    {
    }

    template <typename T>
    PimplPtr<T>::~PimplPtr()
    {

    }

    template <typename T>
    PimplPtr<T>::PimplPtr(T* data)
        : m_data(data)
    {
        assert(data != nullptr);
    }

    template <typename T>
    PimplPtr<T>::PimplPtr(const PimplPtr<T>& copy)
        : m_data(new T(*copy.m_data))
    {
    }

    template <typename T>
    template <typename T1>
    PimplPtr<T>::PimplPtr(T1 arg1)
        : m_data(new T(arg1))
    {
    }

    template <typename T>
    template <typename T1, typename T2>
    PimplPtr<T>::PimplPtr(T1 arg1, T2 arg2)
        : m_data(new T(arg1, arg2))
    {
    }

    template <typename T>
    template <typename T1, typename T2, typename T3>
    PimplPtr<T>::PimplPtr(T1 arg1, T2 arg2, T3 arg3)
        : m_data(new T(arg1, arg2, arg3))
    {
    }

    template <typename T>
    T* PimplPtr<T>::operator->() noexcept
    {
        return (m_data.get());
    }

    template <typename T>
    const T* PimplPtr<T>::operator->() const noexcept
    {
        return (m_data.get());
    }

    template <typename T>
    T& PimplPtr<T>::operator*() noexcept
    {
        return (*m_data);
    }

    template <typename T>
    const T& PimplPtr<T>::operator*() const noexcept
    {
        return (*m_data);
    }

    template <typename T>
    void PimplPtr<T>::swap(PimplPtr<T>& other)
    {
        m_data.swap(other.m_data);
    }
/*
    template <typename T>
    PimplPtr<T>& PimplPtr<T>::operator=(PimplPtr const& rhs)
    {
        PimplPtr<T> tmp(rhs);
        *this = std::move(tmp);
        return (*this);
    }

//    template <typename T>
//    PimplPtr<T>& PimplPtr<T>::operator=(PimplPtr<T>&&) noexcept = default;

    template <typename T>
    template <typename U, typename>
    PimplPtr<T>::PimplPtr(U&& u)
    : m_data(new T{std::forward<U>(u)})
    {
    }

    template <typename T>
    template <typename U1, typename U2, typename ...Args>
    PimplPtr<T>::PimplPtr(U1&& u1, U2&& u2, Args&&... args)
    : m_data(new T{std::forward<U1>(u1),
                 std::forward<U2>(u2),
                 std::forward<Args>(args)...})
    {
    }
*/

}
