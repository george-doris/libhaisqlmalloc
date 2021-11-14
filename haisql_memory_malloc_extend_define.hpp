#ifndef   _haisql_malloc_extend_define_hpp
#define  _haisql_malloc_extend_define_hpp

extern "C"
{
    //  下面的内容都是扩展函数
    void     malloc_show_config( void )  noexcept;
    size_t  malloc_all_size( void )  noexcept;
    void     malloc_set_limit_callback( const size_t sizet_limit_size_in, void ( *ptr_callback_function_in )( size_t ) )  noexcept;
    void     malloc_version( void ) noexcept;
    unsigned int malloc_page_type( void* ptr_void_in )  noexcept;
    void     malloc_multi( const unsigned int uint_size_in, const unsigned int uint_count_in, void** ptr_ptr_void_out  ) noexcept;
    void     free_multi( void** ptr_ptr_void_in, const unsigned int uint_count_in )  noexcept;
}
#endif // _haisql_malloc_extend_define_hpp
