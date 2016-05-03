ADD_EXECUTABLE(main main.c)
INCLUDE_DIRECTORIES(/Users/duanzw/stu/cmake/t3/lib)
LINK_DIRECTORIES(/Users/duanzw/stu/cmake/t3/build/lib)
TARGET_LINK_LIBRARIES(main "/Users/duanzw/stu/cmake/t3/build/lib/libhello.dylib")
