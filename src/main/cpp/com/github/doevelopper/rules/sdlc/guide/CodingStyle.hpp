#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_GUIDE_CODINGSTYLE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_GUIDE_CODINGSTYLE_HPP

/*!
 *
 *  @copyright . (c) 2009-2016 PROJECT <http://www.exemple.org>
 *
 */

/*!
 * @file
 * @brief Coding Style declaration.
 */

#include <3rtparty/headers>
#include <project/headers>
#include <standard/library/headers>
#include <System/headers>

namespace com::github::doevelopper::rules::sdlc::guide
{
    /*!
     *  @class CodingStyle
     *  @brief     Pretty nice class.
     *  @details   This class is used to demonstrate a number of section commands.
     *  @pre       First initialize the system.
     *  @bug       Not all memory is freed when deleting an object of this class.
     *  @warning   Improper use can crash your application
     */
    class CodingStyle
    {
        /*! This is an enum class
         * with More detailed enum description.
         */
        enum class anEnumeration : std::uit8_t
        {
            en = 0, /*!< this is en */
            none /*!< this is none */
        };

    public:

        /*!
         * @brief default constructor.
         */
        CodingStyle();
        /*!
         * @brief copy constructor.
         */
        CodingStyle(const CodingStyle & orig) = default;
        /*!
         * @brief Move constructor  noexcept is deduced.
         */
        CodingStyle(CodingStyle && orig) = default;
        /*!
         * @brief Copy assignment: clean up target and copy  noexcept is deduced
         * @returns CodingStyle reference.
         */
        CodingStyle & operator=(const CodingStyle & orig) = default;
        /*!
         * @brief Move assignment: clean up target and move
         * @returns CodingStyle reference.
         */
        CodingStyle & operator=(CodingStyle && orig) = default;
        virtual ~CodingStyle()                       = default;
        /*!
         * @brief Change the internal value
         *
         * @param Value const reference
         */
        void setValue(const type & value);
        /*!
         * @brief Returns the internal value for reading
         *
         * @returns type const reference
         */
        type & getValue(void) const;

        void publicMethod();
        /*!
         *  @brief One-line summary of what the method does
         *
         *  Full description of what the method does
         *
         *  @tparam <T> A description of the template parameter
         *  @param[in] Parameter1 A description of the parameter
         *  @param[out] Parameter2 A description of the parameter
         *
         *  @return A description of the returned object
         */
        template <typename T>
        T MyFunction(int Parameter1, int & Parameter2);

    protected:

        void protectedMethod();

    private:

        void privateMethod();
        int member; /*! A brief description */
    };
}
#endif
