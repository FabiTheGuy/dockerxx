project(
    'dockerxx',
    'cpp',
    version : '0.1.0',
    default_options : ['warning_level=3', 'cpp_std=c++20']
)

# -------- Lib --------
curl_dep = dependency('libcurl', fallback : ['curl'])

sources = [
    'src/docker.cpp'
]
headers = [
    'include/docker.hpp'
]
includes = [
    'include'
]

dockerxx = shared_library(
    'dockerxx',
    sources: sources + headers,
    include_directories: includes,
    dependencies: [curl_dep],
    install : true,
)


# -------- Testing --------
test_sources = [
    'test/main.cpp'
]

gtest_dep = dependency('gtest', fallback : ['gtest', 'gtest_dep'])

test_executeable = executable(
    'dockerxx_test',
    sources: test_sources,
    include_directories: includes,
    link_with: [dockerxx],
    dependencies: [gtest_dep]
)

test(
    'dockerxx_test',
    test_executeable
)