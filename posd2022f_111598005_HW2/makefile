.PHONY: dirs clean test

all: dirs ut_main

TEST = test/ut_point.h \
		test/ut_two_dimensional_vector.h \
		test/ut_triangle.h \
		test/ut_rectangle.h \
		test/ut_circle.h \
		test/ut_shape.h \
		test/ut_compound_shape.h \
		test/iterator/ut_null_iterator.h \
		test/iterator/ut_dfs_compound_iterator.h \
		test/iterator/ut_bfs_compound_iterator.h

SRC = src/point.h \
		src/two_dimensional_vector.h \
		src/triangle.h \
		src/rectangle.h \
		src/circle.h \
		src/shape.h \
		src/compound_shape.h \
		src/iterator/iterator.h \
		src/iterator/null_iterator.h \
		src/iterator/dfs_compound_iterator.h \
		src/iterator/bfs_compound_iterator.h






ut_main: test/ut_main.cpp  $(TEST) $(SRC)
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread




dirs:
	mkdir -p bin
	

clean:
	rm -rf bin

test: all
	bin/ut_all


