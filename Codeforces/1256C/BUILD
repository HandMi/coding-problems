cc_library(
    name = "1256C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1256C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/1256C",
        "@gtest//:gtest_main",
    ],
)
