load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "PEP018",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP018_test",
    srcs = glob(["test/*.cpp"]),
    data = glob(["data/*.txt"]),
    deps = [
        "//ProjectEulerPlus/PEP018",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP018_bin",
    deps = [
        "//ProjectEulerPlus/PEP018",
    ],
)
