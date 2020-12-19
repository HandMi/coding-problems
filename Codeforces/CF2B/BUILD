cc_library(
    name = "CF2B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF2B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF2B",
        "@gtest//:gtest_main",
    ],
)
