cc_library(
    name = "PEP3",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP3_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP3",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP3_bin",
    deps = [
        "//ProjectEulerPlus/PEP3",
    ],
)
