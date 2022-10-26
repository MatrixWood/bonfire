add_packages("gtest")

target("InetAddress_test")
    add_files("InetAddress_test.cc")
    add_packages("libbonfire")