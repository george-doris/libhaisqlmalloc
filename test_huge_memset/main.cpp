#include <iostream>
#include <chrono>
#include  <vector>
#include <string.h>


namespace  haisql
{

typedef   unsigned long long   timet_nanoseconds;
inline  volatile timet_nanoseconds   now_steady_nanoseconds( void ) noexcept
{
    return  std::chrono::duration_cast<std::chrono::nanoseconds>( std::chrono::steady_clock::now().time_since_epoch() ).count();
}

}//  namespace  haisql

int main()
{
    const size_t  sizet_test_count = 500;
    std::vector<void*>  vt_ptr_void;
    vt_ptr_void.resize( sizet_test_count );
    std::cout << "test count=" << sizet_test_count << std::endl;

    for( unsigned int uint_malloc_size=4096; uint_malloc_size<=2*1024*1024; uint_malloc_size*=2 )
    {
        auto   auto_malloc_begin = haisql::now_steady_nanoseconds();
        //  下面测试最大使用4G的内存
        for( unsigned int i=0; i<sizet_test_count; ++i )
        {
            vt_ptr_void[i] = malloc( uint_malloc_size );
            continue;
        }
        auto   auto_malloc_end = haisql::now_steady_nanoseconds();
        auto   auto_malloc_use = auto_malloc_end - auto_malloc_begin;
        std::cout << "test malloc size=" << uint_malloc_size << ", use_nanoseconds=" << auto_malloc_use << ", avg=" << auto_malloc_use / sizet_test_count << std::endl;

        auto   auto_memset_begin = haisql::now_steady_nanoseconds();
        //  下面测试最大使用4G的内存
        for( unsigned int i=0; i<sizet_test_count; ++i )
        {
            memset( vt_ptr_void[i], 0, uint_malloc_size );
            continue;
        }
        auto   auto_memset_end = haisql::now_steady_nanoseconds();
        auto   auto_memset_use = auto_memset_end - auto_memset_begin;
        std::cout << "test memset size=" << uint_malloc_size << ", use_nanoseconds=" << auto_memset_use << ", avg=" << auto_memset_use / sizet_test_count << std::endl << std::endl;

        for( unsigned int i=0; i<sizet_test_count; ++i )
        {
            free( vt_ptr_void[i] );
            continue;
        }
    }
    return 0;
}
