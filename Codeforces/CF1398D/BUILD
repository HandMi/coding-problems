cc_library(
    name = "CF1398D",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1398D_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1398D",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF1398D_bin",
    deps = [
        "//Codeforces/CF1398D",
    ],
)
