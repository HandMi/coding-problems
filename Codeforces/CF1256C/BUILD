cc_library(
    name = "CF1256C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1256C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1256C",
        "@gtest//:gtest_main",
    ],
)
