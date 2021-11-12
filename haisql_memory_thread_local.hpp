#include "haisql_memory_malloc_extend_define.hpp"

#ifndef    _haisql_memory_thread_local_hpp
#define   _haisql_memory_thread_local_hpp

namespace  haisql
{

template<typename T>
class Thread_local
{
public:
    template <class... Args>
    Thread_local( Args&&... args ) noexcept;

    ~Thread_local( void )  noexcept;
    inline  T& value( void )  noexcept;
    inline  T* get_ptr( void )  noexcept;

private:
    static void destroy( void* arg )  noexcept;
    T    d_t_default;

    Thread_local( Thread_local& ) = delete;
    Thread_local& operator=( Thread_local& ) = delete;
};


template<typename T>
template <class... Args>
Thread_local<T>::Thread_local( Args&&... args ) noexcept:
    d_t_default( T( std::forward<Args>( args )... ) )
{
}


template<typename T>
Thread_local<T>::~Thread_local( void )  noexcept
{
    haisql_destroy_thread_local_ptr( this, &Thread_local<T>::destroy );
    return;
}


template<typename T>
void  Thread_local<T>::destroy( void* ptr_arg_in )  noexcept
{
    T* ptr_t_tmp = reinterpret_cast<T*>( ptr_arg_in );
    if( ptr_t_tmp )
    {
        delete  ptr_t_tmp;
    }
    return;
}


template<typename T>
T& Thread_local<T>::value( void )  noexcept
{
    T* ptr_t_return = reinterpret_cast<T*>( haisql_get_thread_local_ptr( this ) );
    if( !ptr_t_return )
    {
        T* ptr_t_new = new T( d_t_default );
        ptr_t_return = ptr_t_new;
        haisql_add_thread_local_ptr( this, ptr_t_new );
    }
    return *ptr_t_return;
}


template<typename T>
T* Thread_local<T>::get_ptr( void )  noexcept
{
    T* ptr_t_return = reinterpret_cast<T*>( get_thread_local_ptr( this ) );
    if( !ptr_t_return )
    {
        T* ptr_t_new = new T( d_t_default );
        ptr_t_return = ptr_t_new;
        add_thread_local_ptr( this, ptr_t_new );
    }
    return ptr_t_return;
}

}//  namespace  haisql
#endif // _haisql_memory_thread_local_hpp
