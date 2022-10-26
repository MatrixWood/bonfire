set_project("bonfire")
set_languages("c++17")
set_warnings("allextra")
--set_warnings("all", "error")

-- set_config("cxxflags", "-Wno-attributes")
set_config("cc", "clang")
set_config("cxx", "clang++")
set_config("ld", "clang++")

add_rules("mode.debug", "mode.release")

add_requires("gtest")

target("bonfire")
    set_kind("static")
    add_files("bonfile/net/*.cc")
    add_files("bonfile/util/*.cc")

add_subdirs('unittests')