#include <cxxtest/TestSuite.h>
#include <typeinfo>
#include "dicek/vector.hpp"

class VectorTest : public CxxTest::TestSuite {
public:
    void testDIM( void )
    {
        using namespace dicek::math;
        static_assert( vector<3, double>::DIM == 3, "vector<3,double>::DIM is not 3" );
        TSM_ASSERT_EQUALS( "vector<3,double>::DIM is not 3", 3, ( vector<3, double>::DIM ) );
    }

    void test_real_type( void )
    {
        using namespace dicek::math;
        static_assert( std::is_same< vector<3, double>::real_type, double>::value, "vector<3, double>::real_type is not double" );
        TSM_ASSERT( "vector<3, double>::real_type is not double", typeid( vector<3, double>::real_type ) == typeid( double ) );
    }

    void test_at( void )
    {
        using namespace dicek::math;
        vector<3, double> v;
        v.at( 0 ) = 5;
        v.at( 1 ) = 7;
        v.at( 2 ) = 11;

        TSM_ASSERT_EQUALS( "at(0) is not 5", v.at( 0 ), 5 );
        TSM_ASSERT_EQUALS( "at(1) is not 7", v.at( 1 ), 7 );
        TSM_ASSERT_EQUALS( "at(2) is not 11", v.at( 2 ), 11 );
    }

    void test_at_const( void )
    {
        using namespace dicek::math;
        vector<3, double> v;
        v.at( 0 ) = 13;
        v.at( 1 ) = 17;
        v.at( 2 ) = 19;

        const auto& ref = v;

        TSM_ASSERT_EQUALS( "at(0) is not 13", ref.at( 0 ), 13 );
        TSM_ASSERT_EQUALS( "at(1) is not 17", ref.at( 1 ), 17 );
        TSM_ASSERT_EQUALS( "at(2) is not 19", ref.at( 2 ), 19 );
    }

    void test_at_throw( void )
    {
        using namespace dicek::math;
        vector<3, double> v;
        TSM_ASSERT_THROWS( "Exception not thrown", v.at( 3 ), std::out_of_range );
        TSM_ASSERT_THROWS( "Exception not thrown", const_cast<const decltype( v )&>( v ).at( 3 ), std::out_of_range );
    }

    void test_operator_square_bracket( void )
    {
        using namespace dicek::math;
        vector<3, double> v;
        v[ 0 ] = 5;
        v[ 1 ] = 7;
        v[ 2 ] = 11;

        TSM_ASSERT_EQUALS( "operator[](0) is not 5", v[ 0 ], 5 );
        TSM_ASSERT_EQUALS( "operator[](1) is not 7", v[ 1 ], 7 );
        TSM_ASSERT_EQUALS( "operator[](2) is not 11", v[ 2 ], 11 );
    }

    void test_operator_square_bracket_const( void )
    {
        using namespace dicek::math;
        vector<3, double> v;
        v[ 0 ] = 13;
        v[ 1 ] = 17;
        v[ 2 ] = 19;

        const auto& ref = v;

        TSM_ASSERT_EQUALS( "operator[](0) is not 13", ref[ 0 ], 13 );
        TSM_ASSERT_EQUALS( "operator[](1) is not 17", ref[ 1 ], 17 );
        TSM_ASSERT_EQUALS( "operator[](2) is not 19", ref[ 2 ], 19 );
    }
};