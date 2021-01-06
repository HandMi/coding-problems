cc_library(
    name = "PEP017",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP017_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP017",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP017_bin",
    deps = [
        "//ProjectEulerPlus/PEP017",
    ],
)
