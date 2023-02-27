#ifndef   _haisql_malloc_extend_define_hpp
#define  _haisql_malloc_extend_define_hpp

extern "C"
{
    //  下面的内容都是扩展函数
    //  下面的内容都是扩展函数
    void     malloc_show_config( void )  noexcept;
    size_t   malloc_all_size( void )  noexcept;
    void     malloc_set_limit_callback( const size_t sizet_limit_size_in, void ( *ptr_callback_function_in )( size_t ) )  noexcept;
    void     malloc_version( void ) noexcept;
    unsigned int malloc_page_type( void* ptr_void_in )  noexcept;
    void     malloc_multi( const unsigned int uint_size_in, const unsigned int uint_count_in, void** ptr_ptr_void_out  ) noexcept;
    void     free_multi( void** ptr_ptr_void_in, const unsigned int uint_count_in )  noexcept;
    void     memset_zero( void* ptr_void_in, const size_t sizet_size_in )  noexcept;
    void     memset_zero_uint_size( void* ptr_void_in, const unsigned int uint_byte_size_in )  noexcept;

    void*   malloc_less_128( const unsigned int uint_size_in ) noexcept;
    void*   malloc_less_3280( const unsigned int uint_size_in ) noexcept;
    void*   malloc_less_4k( const unsigned int uint_size_in ) noexcept;
    void*   malloc_less_2000k( const unsigned int uint_size_in ) noexcept;
    void*   malloc_fast( const size_t sizet_size_in ) noexcept;

    void   free_less_128( void* ptr_void_in )  noexcept;
    void   free_less_3280( void* ptr_void_in )  noexcept;
    void   free_less_4k( void* ptr_void_in )  noexcept;
    void   free_less_2000k( void* ptr_void_in )  noexcept;
    void   free_fast( void* ptr_void_in )  noexcept;

    void* thread_local_get( void* ptr_void_key_in )  noexcept;
    void   thread_local_set( void* ptr_void_key_in, void* ptr_void_value_in, void(*destructor_in)(void*) )  noexcept;
    void   thread_local_free( void* ptr_void_key_in )  noexcept;
}
#endif // _haisql_malloc_extend_define_hpp
