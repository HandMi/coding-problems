cc_library(
    name = "1256A",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1256A_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//1256A",
        "@gtest//:gtest_main",
    ],
)
