/*
 *	MetaCall Library by Parra Studios
 *	Copyright (C) 2016 - 2017 Vicente Eduardo Ferrer Garcia <vic798@gmail.com>
 *
 *	A library for providing a foreign function interface calls.
 *
 */

#include <gmock/gmock.h>

#include <metacall/metacall.h>
#include <metacall/metacall-plugins.h>

class metacall_initialize_ex_test : public testing::Test
{
public:
};

TEST_F(metacall_initialize_ex_test, DefaultConstructor)
{
	char loader_name[] = "mock";

	struct metacall_initialize_configuration_type config[] =
	{
		#if defined(OPTION_BUILD_PLUGINS_MOCK)
		{
			loader_name, NULL
		},
		#endif /* OPTION_BUILD_PLUGINS_MOCK */

		{
			NULL, NULL
		}
	};

	metacall_print_info();

	ASSERT_EQ((int) 0, (int) metacall_initialize_ex(config));

	/* Mock */
	#if defined(OPTION_BUILD_PLUGINS_MOCK)
	{
		const char * mock_scripts[] =
		{
			"empty.mock"
		};

		ASSERT_EQ((int) 1, (int) metacall_is_initialized("mock"));

		EXPECT_EQ((int) 0, (int) metacall_load_from_file("mock", mock_scripts, sizeof(mock_scripts) / sizeof(mock_scripts[0]), NULL));

		ASSERT_EQ((int) 0, (int) metacall_is_initialized("mock"));
	}
	#endif /* OPTION_BUILD_PLUGINS_MOCK */

	ASSERT_EQ((int) 0, (int) metacall_destroy());
}