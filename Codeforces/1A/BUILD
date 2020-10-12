cc_library(
    name = "1A",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1A_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/1A",
        "@gtest//:gtest_main",
    ],
)
