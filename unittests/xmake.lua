add_packages("gtest")

target("InetAddress_unittest")
    add_files("InetAddress_unittest.cc")
    add_packages("libbonfire")