#define BOOST_TEST_MODULE test
#include <boost/test/included/unit_test.hpp>
#include "print_ip.hpp"

BOOST_AUTO_TEST_SUITE( TestSuite )

    struct cout_redirect {
        cout_redirect( std::streambuf * new_buffer )
                : old( std::cout.rdbuf( new_buffer ) )
        { }

        ~cout_redirect( ) {
            std::cout.rdbuf( old );
        }

    private:
        std::streambuf * old;
    };

    BOOST_AUTO_TEST_CASE(test1)
    {
        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard( output.rdbuf( ) );
            print_ip( char{-1} );
        }
        BOOST_CHECK( output.is_equal( "255\n" ) );
    }

    BOOST_AUTO_TEST_CASE(test2)
    {
        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard( output.rdbuf( ) );
            print_ip( short{0} );
        }
        BOOST_CHECK( output.is_equal( "0.0\n" ) );
    }

    BOOST_AUTO_TEST_CASE(test3)
    {
        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard( output.rdbuf( ) );
            print_ip( int{2130706433} );
        }
        BOOST_CHECK( output.is_equal( "127.0.0.1\n" ) );
    }

    BOOST_AUTO_TEST_CASE(test4)
    {
        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard( output.rdbuf( ) );
            print_ip( long{8875824491850138409} );
        }
        BOOST_CHECK( output.is_equal( "123.45.67.89.101.112.131.41\n" ) );
    }

    BOOST_AUTO_TEST_CASE(test5)
    {
        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard( output.rdbuf( ) );
            print_ip(std::string{"Hello, World!"});
        }
        BOOST_CHECK( output.is_equal( "Hello, World!\n") );
    }

    BOOST_AUTO_TEST_CASE(test6)
    {
        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard( output.rdbuf( ) );
            print_ip(std::vector<int>{100, 200, 300, 400});
        }
        BOOST_CHECK( output.is_equal( "100.200.300.400\n") );
    }

    BOOST_AUTO_TEST_CASE(test7)
    {
        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard( output.rdbuf( ) );
            print_ip(std::vector<int>{400, 300, 200, 100});
        }
        BOOST_CHECK( output.is_equal( "400.300.200.100\n") );
    }


BOOST_AUTO_TEST_SUITE_END()
