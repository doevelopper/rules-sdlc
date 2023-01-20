/****************************************************************************
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


namespace rules::sdlc::stdc
{
    template <typename T>
    SharedPimplPtr<T>::SharedPimplPtr()
        : m_data(new T)
    {
    }

    template <typename T>
    SharedPimplPtr<T>::SharedPimplPtr(T* data)
        : m_data(data)
    {
        assert(data != 0);
    }

    template <typename T>
    template <typename T1>
    SharedPimplPtr<T>::SharedPimplPtr(T1 arg1)
        : m_data(new T(arg1))
    {
    }

    template <typename T>
    template <typename T1, typename T2>
    SharedPimplPtr<T>::SharedPimplPtr(T1 arg1, T2 arg2)
        : m_data(new T(arg1, arg2))
    {
    }

    template <typename T>
    template <typename T1, typename T2, typename T3>
    SharedPimplPtr<T>::SharedPimplPtr(T1 arg1, T2 arg2, T3 arg3)
        : m_data(new T(arg1, arg2, arg3))
    {
    }

    template <typename T>
    T* SharedPimplPtr<T>::operator->()
    {
        return m_data.get();
    }

    template <typename T>
    const T* SharedPimplPtr<T>::operator->() const
    {
        return m_data.get();
    }

    template <typename T>
    T& SharedPimplPtr<T>::operator*()
    {
        return *m_data;
    }

    template <typename T>
    const T& SharedPimplPtr<T>::operator*() const
    {
        return *m_data;
    }

    template <typename T>
    void SharedPimplPtr<T>::swap(SharedPimplPtr<T>& other)
    {
        m_data.swap(other.m_data);
    }

    template <typename T>
    void SharedPimplPtr<T>::unique()
    {
        if (!m_data.unique())
            m_data.reset(new T(*m_data));
    }

}
