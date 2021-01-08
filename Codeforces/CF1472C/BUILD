cc_library(
    name = "CF1472C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1472C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1472C",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF1472C_bin",
    deps = [
        "//Codeforces/CF1472C",
    ],
)
