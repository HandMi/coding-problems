cc_library(
    name = "PEP002",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP002_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP002",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP002_bin",
    deps = [
        "//ProjectEulerPlus/PEP002",
    ],
)
