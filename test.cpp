#include"mu_test.h"
#include"string.h"
#include<iostream>
#include<cstring>

//using namespace std;
//using namespace advcpp;
//using namespace buf_advcpp;

/*UNIT(Simple_buffer)
	Buffer<char> b(0);
	ASSERT_THAT(b.Cap() == 0);
END_UNIT*/

UNIT(String_unary_addition)
	advcpp::String<char> s1("hello ");
	advcpp::String<char> s2("world");	
	advcpp::String<char> s3("hello world");
	s1 += s2;
	
	ASSERT_THAT(s1 == s3);
END_UNIT

UNIT(String_c_str)
	advcpp::String<char> s1("hello");
	ASSERT_THAT(strcmp(s1.As_cstr(), "hello") == 0);
END_UNIT

UNIT(Substring)
	advcpp::String<char> s("hey you");
	advcpp::String<char> s1("you");
	ASSERT_THAT(s.Substring(4) == s1);
END_UNIT

UNIT(Subscript)
	advcpp::String<char> s("some string");
	ASSERT_THAT(s[2] == 'm');
END_UNIT

UNIT(Subscript_const)
	const advcpp::String<char> s("const string");
	ASSERT_THAT(s[3] == 's');
END_UNIT

UNIT(Concat)
	advcpp::String<char> s("con");
	advcpp::String<char> s2("cat");
	advcpp::String<char> s3("concat");
	ASSERT_THAT(s + s2 == s3);
END_UNIT


TEST_SUITE(String tests)
	//TEST(Simple_buffer)
	TEST(String_unary_addition)
	TEST(String_c_str)
	TEST(Substring)
	TEST(Subscript)
	TEST(Subscript_const)
	TEST(Concat)
END_SUITE





















































