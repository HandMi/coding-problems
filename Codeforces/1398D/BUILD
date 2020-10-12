cc_library(
    name = "1398D",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1398D_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/1398D",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "1398D_bin",
    deps = [
        "//Codeforces/1398D",
    ],
)
