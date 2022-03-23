#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;

static Notebook my_notebook;

TEST_CASE("good writing") {
	CHECK_NOTHROW(my_notebook.write(0, 1, 3, Direction::Horizontal, "i'm writing"));
	CHECK(my_notebook.read(0, 1, 3, Direction::Horizontal, 11) == "i'm writing");

	CHECK_NOTHROW(my_notebook.write(0, 6, 3, Direction::Vertical, "i'm writing"));
	CHECK(my_notebook.read(0, 6, 3, Direction::Vertical, 11) == "i'm writing");

	CHECK_NOTHROW(my_notebook.write(0, 1, 7, Direction::Vertical, "world"));
	CHECK(my_notebook.read(0, 1, 7, Direction::Vertical, 5) == "world");

	CHECK_NOTHROW(my_notebook.write(0, 14, 2, Direction::Horizontal, "Gil"));
	CHECK(my_notebook.read(0, 14, 2, Direction::Horizontal, 3) == "Gil");

	CHECK_NOTHROW(my_notebook.write(0, 5, 1, Direction::Horizontal, "belgrad"));
	CHECK(my_notebook.read(0, 5, 1, Direction::Horizontal, 7) == "belgrad");

	CHECK_NOTHROW(my_notebook.write(0, 1, 5, Direction::Vertical, "mirorr"));
	CHECK(my_notebook.read(0, 1, 5, Direction::Vertical, 6) == "mirorr");
}
TEST_CASE("bad writing") {

	CHECK_THROWS(my_notebook.write(0, 1, 5, Direction::Horizontal, "is it free"));

	CHECK_THROWS(my_notebook.write(0, 0, 8, Direction::Vertical, "is it free"));

	CHECK_THROWS(my_notebook.write(0, 7, 3, Direction::Vertical, "is it free"));

	CHECK_THROWS(my_notebook.write(0, 10, 2, Direction::Horizontal, "is it free"));

	CHECK_THROWS(my_notebook.write(0, 3, 96, Direction::Horizontal, "united_state"));

	CHECK_THROWS(my_notebook.write(0, 3, 105, Direction::Horizontal, "united_state"));

	CHECK_THROWS(my_notebook.write(0, 3, 105, Direction::Vertical, "united_state"));

	
}

TEST_CASE("good reading") {
	CHECK(my_notebook.read(0, 2, 7, Direction::Vertical, 3) == "orl");

	CHECK(my_notebook.read(0, 1, 9, Direction::Horizontal, 5) == "iting");

	CHECK(my_notebook.read(0, 4, 5, Direction::Horizontal, 5) == "_o_l_");

	CHECK(my_notebook.read(0, 15, 3, Direction::Vertical, 4) == "ng__");

	CHECK(my_notebook.read(0, 1, 3, Direction::Vertical, 5) == "i___l");

	CHECK(my_notebook.read(0, 1, 1, Direction::Horizontal, 6) == "___i'm ");

}
	
TEST_CASE("bad reading") {

	CHECK_THROWS(my_notebook.read(0, 3, 96, Direction::Horizontal,10 ));

	CHECK_THROWS(my_notebook.read(0, 3, 105, Direction::Horizontal, 3));

	CHECK_THROWS(my_notebook.read(0, 3, 105, Direction::Vertical, 4));
}


TEST_CASE("good erase") {
	
	CHECK_NOTHROW(my_notebook.erase(0, 1, 8, Direction::Horizontal, 6));
	CHECK(my_notebook.read(0, 1, 3, Direction::Horizontal, 11) == "i'm w~~~~~~");

	CHECK_NOTHROW(my_notebook.erase(0, 2, 5, Direction::Vertical, 4));
	CHECK(my_notebook.read(0, 2, 5, Direction::Vertical, 4) == "m~~~~r");

	CHECK(my_notebook.read(0, 5, 1, Direction::Horizontal, 7) == "belg~ad");

	CHECK_NOTHROW(my_notebook.erase(0, 1, 8, Direction::Horizontal, 6));
	CHECK(my_notebook.read(0, 1, 3, Direction::Horizontal, 11) == "i'm w~~~~~~");
}



TEST_CASE("bad erasing") {

	CHECK_THROWS(my_notebook.erase(0, 3, 96, Direction::Horizontal, 10));

	CHECK_THROWS(my_notebook.erase(0, 3, 105, Direction::Horizontal, 3));

	CHECK_THROWS(my_notebook.erase(0, 3, 105, Direction::Vertical, 4));
}