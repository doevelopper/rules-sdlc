
/*
   This is taken form a generated CMAKE .....AHL
 */
#ifndef RULES_SDLC_STDC_COMPILERDETECTION_HPP
#define RULES_SDLC_STDC_COMPILERDETECTION_HPP

//<prolog>

#ifndef SDLC_BEGIN_DECLS
#ifdef __cplusplus

#define SDLC_BEGIN_DECLS                                                                                               \
    extern "C"                                                                                                         \
    {
#define SDLC_END_DECLS }
#else

#define SDLC_BEGIN_DECLS
#define SDLC_END_DECLS
#endif
#endif

/*!
 * @brief
 */
#define SDLC_DECLARE(type) type

#define SDLC_NULLPTR                  nullptr
#define SDLC_DECL_EQ_DEFAULT          noexcept = default
#define SDLC_DECL_EQ_DELETE           noexcept = delete
#define SDLC_DECL_CONSTEXPR           constexpr
#define SDLC_CONSTEXPR                const
#define SDLC_DECL_OVERRIDE            override
#define SDLC_DECL_FINAL               final
#define SDLC_DECL_NOEXCEPT            noexcept
#define SDLC_DECL_NOEXCEPT_EXPR(x)    noexcept(x)
#define SDLC_FUNC_INFO                __PRETTY_FUNCTION__
#define SDLC_FOREVER                  for (;;)
#define SDLC_REQUIRED_RESULT          [[nodiscard]]
#define SDLC_REQUIRED_RESULT_MSG(MSG) [[nodiscard(MSG)]]
#define SDLC_DEPRECATED               [[deprecated]]
#define SDLC_DEPRECATED_MSG(MSG)      [[deprecated(MSG)]]
#define SDLC_MAYBE_UNUSED             [[maybe_unused]]
#define SDLC_UNUSED_ARG(x)                                                                                             \
    do                                                                                                                 \
    { /* null */                                                                                                       \
    }                                                                                                                  \
    while (&x == 0)

#if defined(__GNUC__)
#define UNUSED(x) UNUSED_##x __attribute__((unused))
#elif defined(__LCLINT__)
#define UNUSED(x) /*@unused@*/ x
#else
#define UNUSED(x) x
#endif

#define SDLC_FORWARD_DECLARE_CLASS(name)  class name;
#define SDLC_FORWARD_DECLARE_STRUCT(name) struct name;

#if defined(__cplusplus)
#if __has_cpp_attribute(clang::fallthrough)
#define SDLC_FALLTHROUGH() [[clang::fallthrough]]
#elif __has_cpp_attribute(gnu::fallthrough)
#define SDLC_FALLTHROUGH() [[gnu::fallthrough]]
#elif __has_cpp_attribute(fallthrough)
#define SDLC_FALLTHROUGH() [[fallthrough]]
#endif
#endif

#ifndef SDLC_FALLTHROUGH
#if (defined(__GNUC__) && __GNUC__ >= 700)
#define SDLC_FALLTHROUGH() __attribute__((fallthrough))
#else
#define SDLC_FALLTHROUGH() (void)0
#endif
#endif

#ifdef __GNUC__
#define SDLC_NEVER_INLINE  __attribute__((noinline))
#define SDLC_ALWAYS_INLINE inline __attribute__((always_inline))
#define SDLC_NORETURN      __attribute__((__noreturn__))
#else
#define SDLC_NEVER_INLINE
#define SDLC_ALWAYS_INLINE inline
#define SDLC_NORETURN
#endif

// qt5/qtbase/src/corelib/global/qglobal.h

#define Q_D(Class) Class##Private * const d = d_func()
#define Q_Q(Class) Class * const q = q_func()
/*
   Some classes do not permit copies to be made of an object. These
   classes contains a private copy constructor and assignment
   operator to disable copying (the compiler gives an error message).
 */

#define Q_DEFAULT_COPY_ASSIGN(Class)                                                                                   \
    Class(const Class &) SDLC_DECL_EQ_DEFAULT;                                                                         \
    Class & operator=(Class &&) SDLC_DECL_EQ_DEFAULT;

#define Q_DEFAULT_MOVE(Class)                                                                                          \
    Class(Class &&) SDLC_DECL_EQ_DEFAULT;                                                                              \
    Class & operator=(Class &&) SDLC_DECL_EQ_DEFAULT;

#define Q_DEFAULT_COPY(Class)                                                                                          \
    Class(const Class &) SDLC_DECL_EQ_DEFAULT;                                                                         \
    Class & operator=(const Class &) SDLC_DECL_EQ_DEFAULT;

#define Q_DISABLE_COPY_ASSIGN(Class)                                                                                   \
    Class(const Class &) SDLC_DECL_EQ_DELETE;                                                                          \
    Class & operator=(Class &&) SDLC_DECL_EQ_DELETE;

#define Q_DISABLE_COPY(Class)                                                                                          \
    Class(const Class &) SDLC_DECL_EQ_DELETE;                                                                          \
    Class & operator=(const Class &) SDLC_DECL_EQ_DELETE;

#define Q_DISABLE_MOVE(Class)                                                                                          \
    Class(Class &&) SDLC_DECL_EQ_DELETE;                                                                               \
    Class & operator=(Class &&) SDLC_DECL_EQ_DELETE;

#define Q_DISABLE_COPY_MOVE(Class)                                                                                     \
    Q_DISABLE_COPY(Class)                                                                                              \
    Q_DISABLE_MOVE(Class)

#define Q_DEFAULT_COPY_MOVE(Class)                                                                                     \
    Q_DEFAULT_COPY(Class)                                                                                              \
    Q_DEFAULT_MOVE(Class)

#define Q_NOT_INSTANTIABLE(Class)                                                                                      \
private:                                                                                                               \
                                                                                                                       \
    Class() SDLC_DECL_EQ_DELETE;                                                                                       \
    ~Class() SDLC_DECL_EQ_DELETE;

#define Q_PACKAGE(Class)                                                                                               \
    Q_NOT_INSTANTIABLE(Class)                                                                                          \
    Q_DISABLE_COPY_MOVE(Class)

#define Q_DECLARE_PUBLIC(Class)                                                                                        \
    inline Class * q_func()                                                                                            \
    {                                                                                                                  \
        return static_cast<Class *>(q_ptr);                                                                            \
    }                                                                                                                  \
    inline const Class * q_func() const                                                                                \
    {                                                                                                                  \
        return static_cast<const Class *>(q_ptr);                                                                      \
    }                                                                                                                  \
    friend class Class;

/*
    @brief Utility macros for handling private implementations. It is in addition
       to QtGlobal: Q_DECLARE_PRIVATE, Q_DECLARE_PUBLIC,
       Q_D and Q_Q.
 */

/*!
 * Define a public class constructor with no argument
 *
 * Also make sure the Pimpl is initalized
 *
 */
#define CONSTRUCTOR_NO_ARG_CPP(PUB)                                                                                    \
    PUB::PUB()                                                                                                         \
        : d_ptr(new PUB##Private)                                                                                      \
    {                                                                                                                  \
    }

/*!
 * Define a public class constructor with one argument
 *
 * Also make sure the Pimpl is initalized
 */
#define CONSTRUCTOR_1_ARG_CPP(PUB, _ARG1)                                                                              \
    PUB::PUB(_ARG1 _parent)                                                                                            \
        : Superclass(_parent)                                                                                          \
        , d_ptr(new PUB##Private)                                                                                      \
    {                                                                                                                  \
    }

/*!
 * Define the setter in the public class.
 *
 * This should be put in the .cxx file of the public class. The parameter are
 * the name of the public class (PUB), the type of the argument to return (_TYPE),
 * the name of the getter(_NAME) and the name of the variable in the Private class(_VARNAME).
 */
#define SET_CPP(PUB, _TYPE, _NAME, _VARNAME)                                                                           \
    void PUB::_NAME(_TYPE var)                                                                                         \
    {                                                                                                                  \
        Q_D(PUB);                                                                                                      \
        d->_VARNAME = var;                                                                                             \
    }

/*!
 * Define the setter in the public class.
 *
 * This should be put in the .cxx file of the public class. The parameter are
 * the name of the public class (PUB), the type of the argument to return (_TYPE),
 * the name of the setter(_NAME) and the name of the variable in the Private class(_VARNAME).
 * \see \ref CorePimpl
 */
#define GET_CPP(PUB, _TYPE, _NAME, _VARNAME)                                                                           \
    _TYPE PUB::_NAME() const                                                                                           \
    {                                                                                                                  \
        Q_D(const PUB);                                                                                                \
        return d->_VARNAME;                                                                                            \
    }

// https://www.fluentcpp.com/2019/08/30/how-to-disable-a-warning-in-cpp/

/*
 #define Q_CAST_IGNORE_ALIGN(body) \
 #pragma GCC diagnostic push \
 #pragma GCC diagnostic ignored "-Wcast-align" \
    body \
 #pragma GCC diagnostic pop
 */

#define QT_DO_PRAGMA(text)           _Pragma(#text)
#define QT_WARNING_PUSH              QT_DO_PRAGMA(GCC diagnostic push)
#define QT_WARNING_POP               QT_DO_PRAGMA(GCC diagnostic pop)
#define QT_WARNING_DISABLE_GCC(text) QT_DO_PRAGMA(GCC diagnostic ignored text)

// The body must be a statement:
#define Q_CAST_IGNORE_ALIGN(body) QT_WARNING_PUSH QT_WARNING_DISABLE_GCC("-Wcast-align") body QT_WARNING_POP

#if defined __GNUG__
#define D_PRETTY_FUNCTION __PRETTY_FUNCTION__
#else
#define D_PRETTY_FUNCTION __func__
#endif

#define D_UNUSED(variable) void(variable);

// #define TO_STR(x) #x
// #define STINGIFY(x) TO_STR(x)
// #define PRINTDEFINE(x) #x ": " STINGIFY(x)

// #ifdef _MSC_VER
//     #pragma message(PRINTDEFINE(__cplusplus))
//     #pragma message(PRINTDEFINE(_MSC_FULL_VER))
// #else
//     #pragma message(PRINTDEFINE(__cplusplus))
//     #if defined(__clang_major__)
//         #pragma message("clang version: " TO_STR(__clang_major__) "." TO_STR(__clang_minor__) "."
//         TO_STR(__clang_patchlevel__))
//     #endif
//     #if defined(__GNUC__)
//         #pragma message("gcc version: " TO_STR(__GNUC__) "." TO_STR(__GNUC_MINOR__))
//     #endif
// #endif

template <typename T>
inline T * qGetPtrHelper(T * ptr)
{
    return ptr;
}

template <typename Ptr>
inline auto qGetPtrHelper(Ptr & ptr) -> decltype(ptr.operator->())
{
    return ptr.operator->();
}

#define Q_DECLARE_PRIVATE(Class)                                                                                       \
    inline Class##Private * d_func()                                                                                   \
    {                                                                                                                  \
        Q_CAST_IGNORE_ALIGN(return reinterpret_cast<Class##Private *>(qGetPtrHelper(d_ptr));)                          \
    }                                                                                                                  \
    inline const Class##Private * d_func() const                                                                       \
    {                                                                                                                  \
        Q_CAST_IGNORE_ALIGN(return reinterpret_cast<const Class##Private *>(qGetPtrHelper(d_ptr));)                    \
    }                                                                                                                  \
    friend class Class##Private;

#define Q_DECLARE_PRIVATE_D(Dptr, Class)                                                                               \
    inline Class##Private * d_func()                                                                                   \
    {                                                                                                                  \
        Q_CAST_IGNORE_ALIGN(return reinterpret_cast<Class##Private *>(qGetPtrHelper(Dptr));)                           \
    }                                                                                                                  \
    inline const Class##Private * d_func() const                                                                       \
    {                                                                                                                  \
        Q_CAST_IGNORE_ALIGN(return reinterpret_cast<const Class##Private *>(qGetPtrHelper(Dptr));)                     \
    }                                                                                                                  \
    friend class Class##Private;

// somme shared compilers configurations
// Stringify
#define STRINGIFY(a) #a
/**
 * Configure the compiler warnings.
 */
#if defined(__clang__)
#define SDLC_BEGIN_CONFIGURE_WARNINGS                                                                                  \
    _Pragma(STRINGIFY(clang diagnostic push)) _Pragma(STRINGIFY(clang diagnostic ignored "-Wweak-vtables"))            \
        _Pragma(STRINGIFY(clang diagnostic ignored "-Wc++98-compat"))                                                  \
            _Pragma(STRINGIFY(clang diagnostic ignored "-Wpadded"))                                                    \
                _Pragma(STRINGIFY(clang diagnostic ignored "-Wdocumentation-unknown-command"))                         \
                    _Pragma(STRINGIFY(clang diagnostic ignored "-Wglobal-constructors"))                               \
                        _Pragma(STRINGIFY(clang diagnostic ignored "-Wexit-time-destructors"))
#elif defined(__GNUC__) || defined(__GNUG__)
#define SDLC_BEGIN_CONFIGURE_WARNINGS _Pragma(STRINGIFY(GCC diagnostic push))
#elif defined(_MSC_VER)
#define SDLC_BEGIN_CONFIGURE_WARNINGS __pragma(warning(push))
#endif

/**
 * Restore the original compiler warning configuration.
 */
#if defined(__clang__)
#define SDLC_END_CONFIGURE_WARNINGS _Pragma(STRINGIFY(clang diagnostic pop))
#elif defined(__GNUC__) || defined(__GNUG__)
#define SDLC_END_CONFIGURE_WARNINGS _Pragma(STRINGIFY(GCC diagnostic pop))
#elif defined(_MSC_VER)
#define SDLC_END_CONFIGURE_WARNINGS __pragma(warning(pop))
#endif

//<epilog>
#endif
