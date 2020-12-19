cc_library(
    name = "CF1A",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1A_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1A",
        "@gtest//:gtest_main",
    ],
)
