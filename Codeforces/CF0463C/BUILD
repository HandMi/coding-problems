load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "CF0463C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0463C_test",
    srcs = glob(["test/*.cpp"]),
    data = glob(["data/*.txt"]),
    deps = [
        "//Codeforces/CF0463C",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF0463C_bin",
    deps = [
        "//Codeforces/CF0463C",
    ],
)
