cmake_minimum_required(VERSION 3.9)
project(LeetCode)
set(CMAKE_CXX_STANDARD 11)

#链接库
aux_source_directory(leetcode/editor/cn/include LEETCODE)
add_library(leetcode ${LEETCODE})
LINK_LIBRARIES(leetcode)


add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp)
add_executable(100-same-tree leetcode/editor/cn/100-same-tree.cpp)
add_executable(35-search-insert-position leetcode/editor/cn/35-search-insert-position.cpp)
add_executable(074-SsGoHC "leetcode/editor/cn/074-SsGoHC.cpp")
add_executable(485-max-consecutive-ones leetcode/editor/cn/485-max-consecutive-ones.cpp)
add_executable(495-teemo-attacking leetcode/editor/cn/495-teemo-attacking.cpp)
add_executable(414-third-maximum-number leetcode/editor/cn/414-third-maximum-number.cpp)