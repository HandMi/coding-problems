cc_library(
    name = "PEP011",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP011_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP011",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP011_bin",
    deps = [
        "//ProjectEulerPlus/PEP011",
    ],
)
