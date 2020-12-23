cc_library(
    name = "PEP004",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP004_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP004",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP004_bin",
    deps = [
        "//ProjectEulerPlus/PEP004",
    ],
)
