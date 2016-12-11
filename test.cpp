#include"mu_test.h"
#include"string.h"
#include<iostream>
#include<cstring>

using namespace std;
using namespace advcpp;
using namespace buf_advcpp;

UNIT(Simple_buffer)
	Buffer b(0);
	ASSERT_THAT(b.Cap() == 0);
END_UNIT

UNIT(String_unary_addition)
	String s1("hello ");
	String s2("world");	
	s1 += s2;
	ASSERT_THAT(s1 == "hello world");
END_UNIT

UNIT(String_c_str)
	String s1("hello");
	ASSERT_THAT(strcmp(s1.As_cstr(), "hello") == 0);
END_UNIT

UNIT(Substring)
	String s("hey you");
	ASSERT_THAT(s.Substring(4) == "you");
END_UNIT


TEST_SUITE(String tests)
	TEST(Simple_buffer)
	TEST(String_unary_addition)
	TEST(String_c_str)
	TEST(Substring)
END_SUITE

